// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from crsf_parser:msg/CRSFChannels.idl
// generated code does not contain a copyright notice

#ifndef CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "crsf_parser/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "crsf_parser/msg/detail/crsf_channels__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace crsf_parser
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_crsf_parser
cdr_serialize(
  const crsf_parser::msg::CRSFChannels & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_crsf_parser
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  crsf_parser::msg::CRSFChannels & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_crsf_parser
get_serialized_size(
  const crsf_parser::msg::CRSFChannels & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_crsf_parser
max_serialized_size_CRSFChannels(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace crsf_parser

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_crsf_parser
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, crsf_parser, msg, CRSFChannels)();

#ifdef __cplusplus
}
#endif

#endif  // CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
