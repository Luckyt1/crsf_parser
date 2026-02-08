from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
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
    ])