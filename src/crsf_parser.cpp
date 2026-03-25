#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "crsf_parser/msg/crsf_channels.hpp"
#include <cstdlib>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <chrono>
#include <vector>
#include <string>
#include <memory>
#include <cstring>
#include <cstdint>
#include "CSerialPort/SerialPort.h"
#include "CSerialPort/SerialPortInfo.h"
using namespace itas109;
class CRSFParser : public rclcpp::Node,
                   public CSerialPortListener,
                   public CSerialPortHotPlugListener {
public:
    CRSFParser()
        : Node("crsf_parser")
    {
        // 声明参数
        this->declare_parameter<std::string>("port", "/dev/ttyACM0");
        this->declare_parameter<int>("baudrate", 115200);
        this->declare_parameter<bool>("publish_joy", true);
        this->declare_parameter<bool>("publish_raw", true);
        this->declare_parameter<float>("scale_factor", 1.0);
        this->declare_parameter<bool>("debug", false);
        last_publish_time_ = this->now();
        // 获取参数
        port_ = this->get_parameter("port").as_string();
        baudrate_ = this->get_parameter("baudrate").as_int();
        publish_joy_ = this->get_parameter("publish_joy").as_bool();
        publish_raw_ = this->get_parameter("publish_raw").as_bool();
        scale_factor_ = this->get_parameter("scale_factor").as_double();
        debug_ = this->get_parameter("debug").as_bool();

        // 创建发布者
        if (publish_raw_) {
            crsf_pub_ = this->create_publisher<crsf_parser::msg::CRSFChannels>(
                "crsf/channels", 10);
            RCLCPP_INFO(this->get_logger(), "启用原始CRSF数据发布");
        }
        if (publish_joy_) {
            joy_pub_ =
                this->create_publisher<sensor_msgs::msg::Joy>("crsf/joy", 10);
            RCLCPP_INFO(this->get_logger(), "启用Joy消息发布");
        }

        // 打开串口
        openSerialPort();

        // 创建状态报告定时器
        status_timer_ =
            this->create_wall_timer(std::chrono::seconds(2),
                                    std::bind(&CRSFParser::reportStatus, this));

        RCLCPP_INFO(this->get_logger(), "CRSF解析节点已启动");
    }

private:
    void openSerialPort()
    {
        std::vector<SerialPortInfo> m_availablePortsList =
            CSerialPortInfo::availablePortInfos();
        RCLCPP_INFO(this->get_logger(), "AvailableFriendlyPorts:");
        int availablePortCount = (int)m_availablePortsList.size();
        bool has_port = false;
        for (int i = 1; i <= availablePortCount; ++i) {
            SerialPortInfo serialPortInfo = m_availablePortsList[i - 1];
            RCLCPP_INFO(this->get_logger(), "%d - %s %s %s", i,
                        serialPortInfo.portName, serialPortInfo.description,
                        serialPortInfo.hardwareId);
            if (port_.compare(serialPortInfo.portName) == 0) {
                has_port |= true;
            }
        }
        if (!has_port) {
            RCLCPP_ERROR(this->get_logger(), "没有这个串口: %s", port_.c_str());
        }
        sp.connectReadEvent(this);
        sp.connectHotPlugEvent(this);
        sp.init(port_.c_str(), // windows:COM1 Linux:/dev/ttyS0
                baudrate_, // baudrate
                itas109::ParityNone, // parity
                itas109::DataBits8, // data bit
                itas109::StopOne, // stop bit
                itas109::FlowNone, // flow
                4096 // read buffer size
        );
        if (has_port) {
            try_open();
        }
    }
    void onReadEvent(const char *portName, unsigned int readBufferLen)
    {
        uint8_t buffer[256];
        int read_len = sp.readData(buffer, 256);
        int pointer = 0;
        while (read_len) {
            parseByte(buffer[pointer]);
            pointer++;
            read_len--;
        }
    };

    void onHotPlugEvent(const char *portName, int isAdd)
    {
        RCLCPP_INFO(this->get_logger(), "portName: %s, isAdded: %d\n", portName,
                    isAdd);
        if (strcmp(portName, port_.c_str()) == 0) {
            if (isAdd) {
                try_open();
            } else {
                sp.close();
                RCLCPP_INFO(this->get_logger(), "串口已关闭:%s", port_.c_str());
            }
        }
    }
    void try_open()
    {
        sp.open();
        RCLCPP_INFO(this->get_logger(), "打开 %s %s", port_.c_str(),
                    sp.isOpen() ? "成功" : "失败");
        if (!sp.isOpen()) {
            RCLCPP_ERROR(this->get_logger(), "Code: %d, Message: %s",
                         sp.getLastError(), sp.getLastErrorMsg());
            exit(1);
        }
    }
    void parseByte(uint8_t byte)
    {
        static uint8_t crc = 0;

        switch (parser_state_) {
        case STATE_SYNC:
            if (byte == CRSF_SYNC_BYTE) {
                parser_state_ = STATE_LENGTH;
                frame_length_ = 0;
                data_index_ = 0;
                crc = 0;
            }
            break;
        case STATE_LENGTH:
            frame_length_ = byte;
            // crc = crc8(&byte, 1, crc);
            if (frame_length_ > 4 && frame_length_ <= CRSF_MAX_FRAME_SIZE) {
                parser_state_ = STATE_TYPE;
                // frame_length_ -= 2; // Exclude CRC bytes
            } else {
                parser_state_ = STATE_SYNC;
            }
            break;

        case STATE_TYPE:
            frame_type_ = byte;
            crc = crc8(&byte, 1, crc);
            parser_state_ = STATE_PAYLOAD;
            break;

        case STATE_PAYLOAD:

            if (data_index_ >= (frame_length_ - 3)) {
                frame_buffer_[data_index_] = byte;
                crc = crc8(&byte, 1, crc);
                parser_state_ = STATE_CRC;

            } else {
                frame_buffer_[data_index_] = byte;
                crc = crc8(&byte, 1, crc);
                data_index_++;
            }

            break;

        case STATE_CRC:
            if (crc == byte) {
                processFrame();
            } else if (debug_) {
                RCLCPP_WARN(this->get_logger(),
                            "CRC校验失败: 期望 %02X, 实际 %02X", crc, byte);
            }
            parser_state_ = STATE_SYNC;
            break;
        }
    }

    void processFrame()
    {
        switch (frame_type_) {
        case CRSF_FRAMETYPE_RC_CHANNELS_PACKED:
            processRCChannels();
            break;

        case CRSF_FRAMETYPE_LINK_STATISTICS:
            processLinkStatistics();
            break;

        case CRSF_FRAMETYPE_GPS:
            if (debug_)
                RCLCPP_DEBUG(this->get_logger(), "GPS数据帧");
            break;

        case CRSF_FRAMETYPE_BATTERY_SENSOR:
            if (debug_)
                RCLCPP_DEBUG(this->get_logger(), "电池传感器帧");
            break;

        default:
            if (debug_)
                RCLCPP_DEBUG(this->get_logger(), "未知帧类型: 0x%02X",
                             frame_type_);
            break;
        }
    }

    void processRCChannels()
    {
        // 解析16个11位通道值
        uint32_t bits = 0;
        uint8_t bit_count = 0;
        uint8_t *data_ptr = frame_buffer_;

        // 使用指针运算提高效率
        for (int ch = 0; ch < 16; ch++) {
            // 读取足够的位
            while (bit_count < 11) {
                bits |= (*data_ptr++) << bit_count;
                bit_count += 8;
            }

            // 提取11位值
            channels_[ch] = bits & 0x7FF;

            // 右移已使用的位
            bits >>= 11;
            bit_count -= 11;
        }

        // 检查是否需要发布
        auto now = this->now();
        auto elapsed = now - last_publish_time_;

        // 限制发布频率到100Hz
        if (elapsed >= std::chrono::milliseconds(10)) {
            last_publish_time_ = now;

            // 发布原始CRSF数据
            if (publish_raw_) {
                auto msg = crsf_parser::msg::CRSFChannels();

                // 填充通道数据
                for (int i = 0; i < 16; i++) {
                    msg.channels[i] = channels_[i];
                }

                msg.link_quality = link_quality_;
                msg.rssi_dbm = rssi_dbm_;
                msg.failsafe = failsafe_;
                msg.timestamp = now.nanoseconds();

                crsf_pub_->publish(msg);
            }

            // 发布Joy消息
            if (publish_joy_) {
                auto joy_msg = sensor_msgs::msg::Joy();
                joy_msg.header.stamp = now;
                joy_msg.header.frame_id = "crsf";

                // 将通道值归一化到[-1.0, 1.0]
                // CRSF范围：173-1811（微调范围），中值：992
                for (int i = 0; i < 16; i++) {
                    float normalized;
                    if (channels_[i] < 992) {
                        normalized =
                            -(992.0f - channels_[i]) / 819.0f; // 992-173=819
                    } else {
                        normalized =
                            (channels_[i] - 992.0f) / 819.0f; // 1811-992=819
                    }
                    normalized *= scale_factor_;
                    normalized = std::max(-1.0f, std::min(1.0f, normalized));
                    joy_msg.axes.push_back(normalized);
                }

                joy_pub_->publish(joy_msg);
            }

            frames_received_++;
        }
    }

    void processLinkStatistics()
    {
        if (data_index_ < 3)
            return;

        // 解析链路统计
        link_quality_ = frame_buffer_[0]; // 上行链路质量
        uint8_t downlink_quality = frame_buffer_[1]; // 下行链路质量
        rssi_dbm_ = frame_buffer_[2]; // RSSI (dBm * -1)

        // 检查失控保护
        if (link_quality_ < 20 || rssi_dbm_ > 100) { // RSSI值越大信号越差
            failsafe_ = true;
            if (debug_) {
                RCLCPP_WARN(this->get_logger(),
                            "失控保护激活! LQ: %d%%, RSSI: %d dBm",
                            link_quality_, rssi_dbm_);
            }
        } else {
            failsafe_ = false;
        }
    }

    uint8_t crc8(uint8_t *data, size_t length, uint8_t crc)
    {
        for (size_t i = 0; i < length; i++) {
            crc ^= data[i];
            for (int j = 0; j < 8; j++) {
                if (crc & 0x80) {
                    crc = (crc << 1) ^ 0xD5;
                } else {
                    crc <<= 1;
                }
            }
        }
        return crc;
    }

    void reportStatus()
    {
        if (debug_) {
            RCLCPP_INFO(
                this->get_logger(),
                "状态: 波特率: %d, 帧数: %lu, 字节: %lu, LQ: %d%%, RSSI: %d dBm",
                baudrate_, frames_received_, bytes_received_, link_quality_,
                rssi_dbm_);
        }
    }
    CSerialPort sp;
    // CRSF协议常量
    static constexpr uint8_t CRSF_SYNC_BYTE = 0xC8;
    static constexpr size_t CRSF_MAX_FRAME_SIZE = 64;
    static constexpr uint8_t CRSF_FRAMETYPE_RC_CHANNELS_PACKED = 0x16;
    static constexpr uint8_t CRSF_FRAMETYPE_LINK_STATISTICS = 0x14;
    static constexpr uint8_t CRSF_FRAMETYPE_GPS = 0x02;
    static constexpr uint8_t CRSF_FRAMETYPE_BATTERY_SENSOR = 0x08;

    // 解析器状态
    enum ParserState {
        STATE_SYNC,
        STATE_TYPE,
        STATE_LENGTH,
        STATE_PAYLOAD,
        STATE_CRC
    };

    ParserState parser_state_ = STATE_SYNC;
    uint8_t frame_type_ = 0;
    uint8_t frame_length_ = 0;
    uint8_t frame_buffer_[CRSF_MAX_FRAME_SIZE];
    size_t data_index_ = 0;

    // 通道数据
    uint16_t channels_[16] = { 0 };
    uint8_t link_quality_ = 100;
    uint8_t rssi_dbm_ = 99;
    bool failsafe_ = false;

    // ROS2组件
    rclcpp::Publisher<crsf_parser::msg::CRSFChannels>::SharedPtr crsf_pub_;
    rclcpp::Publisher<sensor_msgs::msg::Joy>::SharedPtr joy_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::TimerBase::SharedPtr status_timer_;
    rclcpp::Time last_publish_time_;

    // 串口
    std::string port_;
    int baudrate_;

    // 参数
    bool publish_joy_;
    bool publish_raw_;
    float scale_factor_;
    bool debug_;

    // 统计信息
    unsigned long frames_received_ = 0;
    unsigned long bytes_received_ = 0;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CRSFParser>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}