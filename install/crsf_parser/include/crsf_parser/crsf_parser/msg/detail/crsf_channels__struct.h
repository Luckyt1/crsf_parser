// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from crsf_parser:msg/CRSFChannels.idl
// generated code does not contain a copyright notice

#ifndef CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__STRUCT_H_
#define CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/CRSFChannels in the package crsf_parser.
/**
  * CRSF通道数据（11位分辨率）
 */
typedef struct crsf_parser__msg__CRSFChannels
{
  uint16_t channels[16];
  /// 链路质量百分比
  uint8_t link_quality;
  /// RSSI dBm值
  uint8_t rssi_dbm;
  /// 失控保护状态
  bool failsafe;
  /// 时间戳
  uint32_t timestamp;
} crsf_parser__msg__CRSFChannels;

// Struct for a sequence of crsf_parser__msg__CRSFChannels.
typedef struct crsf_parser__msg__CRSFChannels__Sequence
{
  crsf_parser__msg__CRSFChannels * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} crsf_parser__msg__CRSFChannels__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__STRUCT_H_
