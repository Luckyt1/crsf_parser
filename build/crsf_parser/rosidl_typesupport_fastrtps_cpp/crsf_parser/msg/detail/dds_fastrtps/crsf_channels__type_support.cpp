// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from crsf_parser:msg/CRSFChannels.idl
// generated code does not contain a copyright notice
#include "crsf_parser/msg/detail/crsf_channels__rosidl_typesupport_fastrtps_cpp.hpp"
#include "crsf_parser/msg/detail/crsf_channels__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: channels
  {
    cdr << ros_message.channels;
  }
  // Member: link_quality
  cdr << ros_message.link_quality;
  // Member: rssi_dbm
  cdr << ros_message.rssi_dbm;
  // Member: failsafe
  cdr << (ros_message.failsafe ? true : false);
  // Member: timestamp
  cdr << ros_message.timestamp;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_crsf_parser
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  crsf_parser::msg::CRSFChannels & ros_message)
{
  // Member: channels
  {
    cdr >> ros_message.channels;
  }

  // Member: link_quality
  cdr >> ros_message.link_quality;

  // Member: rssi_dbm
  cdr >> ros_message.rssi_dbm;

  // Member: failsafe
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.failsafe = tmp ? true : false;
  }

  // Member: timestamp
  cdr >> ros_message.timestamp;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_crsf_parser
get_serialized_size(
  const crsf_parser::msg::CRSFChannels & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: channels
  {
    size_t array_size = 16;
    size_t item_size = sizeof(ros_message.channels[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: link_quality
  {
    size_t item_size = sizeof(ros_message.link_quality);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rssi_dbm
  {
    size_t item_size = sizeof(ros_message.rssi_dbm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: failsafe
  {
    size_t item_size = sizeof(ros_message.failsafe);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: timestamp
  {
    size_t item_size = sizeof(ros_message.timestamp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_crsf_parser
max_serialized_size_CRSFChannels(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: channels
  {
    size_t array_size = 16;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: link_quality
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rssi_dbm
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: failsafe
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: timestamp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = crsf_parser::msg::CRSFChannels;
    is_plain =
      (
      offsetof(DataType, timestamp) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _CRSFChannels__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const crsf_parser::msg::CRSFChannels *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _CRSFChannels__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<crsf_parser::msg::CRSFChannels *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _CRSFChannels__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const crsf_parser::msg::CRSFChannels *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _CRSFChannels__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_CRSFChannels(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _CRSFChannels__callbacks = {
  "crsf_parser::msg",
  "CRSFChannels",
  _CRSFChannels__cdr_serialize,
  _CRSFChannels__cdr_deserialize,
  _CRSFChannels__get_serialized_size,
  _CRSFChannels__max_serialized_size
};

static rosidl_message_type_support_t _CRSFChannels__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CRSFChannels__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace crsf_parser

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_crsf_parser
const rosidl_message_type_support_t *
get_message_type_support_handle<crsf_parser::msg::CRSFChannels>()
{
  return &crsf_parser::msg::typesupport_fastrtps_cpp::_CRSFChannels__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, crsf_parser, msg, CRSFChannels)() {
  return &crsf_parser::msg::typesupport_fastrtps_cpp::_CRSFChannels__handle;
}

#ifdef __cplusplus
}
#endif
