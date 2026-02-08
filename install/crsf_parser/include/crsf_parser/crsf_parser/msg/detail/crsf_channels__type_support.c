// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from crsf_parser:msg/CRSFChannels.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "crsf_parser/msg/detail/crsf_channels__rosidl_typesupport_introspection_c.h"
#include "crsf_parser/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "crsf_parser/msg/detail/crsf_channels__functions.h"
#include "crsf_parser/msg/detail/crsf_channels__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__CRSFChannels_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  crsf_parser__msg__CRSFChannels__init(message_memory);
}

void crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__CRSFChannels_fini_function(void * message_memory)
{
  crsf_parser__msg__CRSFChannels__fini(message_memory);
}

size_t crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__size_function__CRSFChannels__channels(
  const void * untyped_member)
{
  (void)untyped_member;
  return 16;
}

const void * crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__get_const_function__CRSFChannels__channels(
  const void * untyped_member, size_t index)
{
  const uint16_t * member =
    (const uint16_t *)(untyped_member);
  return &member[index];
}

void * crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__get_function__CRSFChannels__channels(
  void * untyped_member, size_t index)
{
  uint16_t * member =
    (uint16_t *)(untyped_member);
  return &member[index];
}

void crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__fetch_function__CRSFChannels__channels(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint16_t * item =
    ((const uint16_t *)
    crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__get_const_function__CRSFChannels__channels(untyped_member, index));
  uint16_t * value =
    (uint16_t *)(untyped_value);
  *value = *item;
}

void crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__assign_function__CRSFChannels__channels(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint16_t * item =
    ((uint16_t *)
    crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__get_function__CRSFChannels__channels(untyped_member, index));
  const uint16_t * value =
    (const uint16_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__CRSFChannels_message_member_array[5] = {
  {
    "channels",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    16,  // array size
    false,  // is upper bound
    offsetof(crsf_parser__msg__CRSFChannels, channels),  // bytes offset in struct
    NULL,  // default value
    crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__size_function__CRSFChannels__channels,  // size() function pointer
    crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__get_const_function__CRSFChannels__channels,  // get_const(index) function pointer
    crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__get_function__CRSFChannels__channels,  // get(index) function pointer
    crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__fetch_function__CRSFChannels__channels,  // fetch(index, &value) function pointer
    crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__assign_function__CRSFChannels__channels,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "link_quality",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(crsf_parser__msg__CRSFChannels, link_quality),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rssi_dbm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(crsf_parser__msg__CRSFChannels, rssi_dbm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "failsafe",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(crsf_parser__msg__CRSFChannels, failsafe),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(crsf_parser__msg__CRSFChannels, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__CRSFChannels_message_members = {
  "crsf_parser__msg",  // message namespace
  "CRSFChannels",  // message name
  5,  // number of fields
  sizeof(crsf_parser__msg__CRSFChannels),
  crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__CRSFChannels_message_member_array,  // message members
  crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__CRSFChannels_init_function,  // function to initialize message memory (memory has to be allocated)
  crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__CRSFChannels_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__CRSFChannels_message_type_support_handle = {
  0,
  &crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__CRSFChannels_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_crsf_parser
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, crsf_parser, msg, CRSFChannels)() {
  if (!crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__CRSFChannels_message_type_support_handle.typesupport_identifier) {
    crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__CRSFChannels_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &crsf_parser__msg__CRSFChannels__rosidl_typesupport_introspection_c__CRSFChannels_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
