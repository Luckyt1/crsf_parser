cmake_minimum_required(VERSION 3.8)
project(crsf_parser)

# 设置C++标准
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# 查找依赖
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# 查找消息依赖
find_package(builtin_interfaces REQUIRED)

# 添加自定义消息
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/CRSFChannels.msg"
  DEPENDENCIES builtin_interfaces
)

# 包含目录
include_directories(
  include
  ${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp
)

# 创建可执行文件
add_executable(${PROJECT_NAME}_node src/crsf_parser.cpp)

# 链接库
target_include_directories(${PROJECT_NAME}_node PUBLIC
  ${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp
)

# 添加依赖
ament_target_dependencies(${PROJECT_NAME}_node
  rclcpp
  sensor_msgs
  std_msgs
  rosidl_default_runtime
)

# 导出依赖
rosidl_target_interfaces(${PROJECT_NAME}_node
  ${PROJECT_NAME} rosidl_typesupport_cpp)

# 创建 tranform 可执行文件
add_executable(tranform src/tranform.cpp)

ament_target_dependencies(tranform
  rclcpp
  sensor_msgs
  std_msgs
)

# 需要添加 communication 包依赖
find_package(communication REQUIRED)
ament_target_dependencies(tranform communication)

# 安装目标
install(TARGETS
  ${PROJECT_NAME}_node
  tranform
  DESTINATION lib/${PROJECT_NAME}
)

# 安装启动文件
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

# 安装消息文件
install(DIRECTORY msg
  DESTINATION share/${PROJECT_NAME}
)

# 导出包含目录
ament_export_include_directories(include)

# 导出库依赖
ament_export_libraries(${PROJECT_NAME}_node)

# 导出目标依赖
ament_export_dependencies(
  rclcpp
  sensor_msgs
  std_msgs
  rosidl_default_runtime
  builtin_interfaces
)

ament_package()