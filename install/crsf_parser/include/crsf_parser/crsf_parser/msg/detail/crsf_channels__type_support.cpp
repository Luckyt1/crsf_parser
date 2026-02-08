// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from crsf_parser:msg/CRSFChannels.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "crsf_parser/msg/detail/crsf_channels__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace crsf_parser
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CRSFChannels_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) crsf_parser::msg::CRSFChannels(_init);
}

void CRSFChannels_fini_function(void * message_memory)
{
  auto typed_message = static_cast<crsf_parser::msg::CRSFChannels *>(message_memory);
  typed_message->~CRSFChannels();
}

size_t size_function__CRSFChannels__channels(const void * untyped_member)
{
  (void)untyped_member;
  return 16;
}

const void * get_const_function__CRSFChannels__channels(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint16_t, 16> *>(untyped_member);
  return &member[index];
}

void * get_function__CRSFChannels__channels(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint16_t, 16> *>(untyped_member);
  return &member[index];
}

void fetch_function__CRSFChannels__channels(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint16_t *>(
    get_const_function__CRSFChannels__channels(untyped_member, index));
  auto & value = *reinterpret_cast<uint16_t *>(untyped_value);
  value = item;
}

void assign_function__CRSFChannels__channels(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint16_t *>(
    get_function__CRSFChannels__channels(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint16_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CRSFChannels_message_member_array[5] = {
  {
    "channels",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    16,  // array size
    false,  // is upper bound
    offsetof(crsf_parser::msg::CRSFChannels, channels),  // bytes offset in struct
    nullptr,  // default value
    size_function__CRSFChannels__channels,  // size() function pointer
    get_const_function__CRSFChannels__channels,  // get_const(index) function pointer
    get_function__CRSFChannels__channels,  // get(index) function pointer
    fetch_function__CRSFChannels__channels,  // fetch(index, &value) function pointer
    assign_function__CRSFChannels__channels,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "link_quality",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(crsf_parser::msg::CRSFChannels, link_quality),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rssi_dbm",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(crsf_parser::msg::CRSFChannels, rssi_dbm),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "failsafe",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(crsf_parser::msg::CRSFChannels, failsafe),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(crsf_parser::msg::CRSFChannels, timestamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CRSFChannels_message_members = {
  "crsf_parser::msg",  // message namespace
  "CRSFChannels",  // message name
  5,  // number of fields
  sizeof(crsf_parser::msg::CRSFChannels),
  CRSFChannels_message_member_array,  // message members
  CRSFChannels_init_function,  // function to initialize message memory (memory has to be allocated)
  CRSFChannels_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CRSFChannels_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CRSFChannels_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace crsf_parser


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<crsf_parser::msg::CRSFChannels>()
{
  return &::crsf_parser::msg::rosidl_typesupport_introspection_cpp::CRSFChannels_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, crsf_parser, msg, CRSFChannels)() {
  return &::crsf_parser::msg::rosidl_typesupport_introspection_cpp::CRSFChannels_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
