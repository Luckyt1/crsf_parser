#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include <communication/msg/motion_commands.hpp>
#include <iostream>
class TransformNode : public rclcpp::Node
{
public:
    TransformNode() : Node("transform_node")
    {
        last_update_time_ = this->now(); // 或者直接赋值当前时间
        subscription_ = this->create_subscription<sensor_msgs::msg::Joy>(
            "crsf/joy", 10, std::bind(&TransformNode::on_joy_received, this, std::placeholders::_1));
        publisher_ = this->create_publisher<communication::msg::MotionCommands>("/motion_commands", 20);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(10), std::bind(&TransformNode::publish_motion_commands, this));
    }
private:
    struct ControllerData
    {
        float x;
        float y;
        float z;
        float yaw;
        bool die;
        int left_mode;
        
    };
private:
    ControllerData controller_data_;
    rclcpp::Time last_update_time_;
    const double TIMEOUT_THRESHOLD = 0.5; // 设置 0.5 秒为超时阈值
    void limit(float& value)
    {
        const float LIMIT_THRESHOLD = 0.01;// 设置死区
        if(value<LIMIT_THRESHOLD&&value>-LIMIT_THRESHOLD)
            value=0.0;

    }
    void reset_value()
    {
        controller_data_.x = 0.0;
        controller_data_.y = 0.0;
        controller_data_.z = 0.0;
        controller_data_.yaw = 0.0;
    }
    void on_joy_received(const sensor_msgs::msg::Joy::SharedPtr msg)
    {
        last_update_time_ = this->now();
        controller_data_.x = msg->axes[1];
        controller_data_.y = msg->axes[0]*-1;
        // z_ = msg->axes[0];
        controller_data_.yaw =msg->axes[3]*-1;
        // controller_data_.left_mode =msg->axes[5];
        controller_data_.die=msg->axes[8]>0.3?true:false;
        // RCLCPP_INFO(this->get_logger(), "Received joy message");
    }
    void publish_motion_commands()
    {
        auto current_time = this->now();
        // RCLCPP_INFO(this->get_logger(), "当前时间: %f 秒", current_time.seconds());
        auto duration = (current_time - last_update_time_).seconds();
        auto msg = communication::msg::MotionCommands();
        if (controller_data_.die) {
            system("killall -SIGINT robot_controller");
            system("killall -SIGINT pt_main_thread");
            system("killall -SIGINT hardware");
            system("killall -SIGINT simulation");// mujoco
            system("killall -SIGINT bxi_example_py_elf3_dance");
            system("killall -SIGINT bxi_example_py_elf3_run");
            printf("kill robot_controller\n");//robot_controller
            reset_value();
            return;
        }
        if (duration > TIMEOUT_THRESHOLD) {
            // 如果超时，强制赋 0 (Failsafe)
            controller_data_.x = 0.0;
            controller_data_.y = 0.0;
            controller_data_.z = 0.0;
            controller_data_.yaw = 0.0;
            // 可选：在这里记录日志提醒
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000, "Remote lost! Failsafe triggered.");
        }
        limit(controller_data_.x);
        limit(controller_data_.y);
        limit(controller_data_.z);
        limit(controller_data_.yaw);

        msg.vel_des.x = controller_data_.x;
        msg.vel_des.y = controller_data_.y;
        msg.vel_des.z = controller_data_.z;
        msg.yawdot_des = controller_data_.yaw;
        // msg.btn_5=controller_data_.left_mode;
        publisher_->publish(msg);
    }
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
    rclcpp::Publisher<communication::msg::MotionCommands>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};
int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TransformNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}