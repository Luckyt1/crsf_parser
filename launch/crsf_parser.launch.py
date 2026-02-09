from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # 1. 定义第一个节点：CRSF 解析器
    crsf_node = Node(
        package='crsf_parser',
        executable='crsf_parser_node',
        name='crsf_parser',
        parameters=[{
            'port': '/dev/ttyACM0',
            'baudrate': 115200,
            'publish_joy': True,
            'publish_raw': True
        }],
        output='screen'
    )

    # 2. 定义第二个节点：你写的转换节点 (例如叫 remote_controller)
    transform_node = Node(
        package='crsf_parser', # 换成你的包名
        executable='tranform', # 换成你的可执行文件名
        name='transform_node',
        output='screen',
    )

    # 返回包含这两个节点的列表
    return LaunchDescription([
        crsf_node,
        transform_node
    ])