// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from crsf_parser:msg/CRSFChannels.idl
// generated code does not contain a copyright notice

#ifndef CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__TRAITS_HPP_
#define CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "crsf_parser/msg/detail/crsf_channels__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace crsf_parser
{

namespace msg
{

inline void to_flow_style_yaml(
  const CRSFChannels & msg,
  std::ostream & out)
{
  out << "{";
  // member: channels
  {
    if (msg.channels.size() == 0) {
      out << "channels: []";
    } else {
      out << "channels: [";
      size_t pending_items = msg.channels.size();
      for (auto item : msg.channels) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: link_quality
  {
    out << "link_quality: ";
    rosidl_generator_traits::value_to_yaml(msg.link_quality, out);
    out << ", ";
  }

  // member: rssi_dbm
  {
    out << "rssi_dbm: ";
    rosidl_generator_traits::value_to_yaml(msg.rssi_dbm, out);
    out << ", ";
  }

  // member: failsafe
  {
    out << "failsafe: ";
    rosidl_generator_traits::value_to_yaml(msg.failsafe, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CRSFChannels & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: channels
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.channels.size() == 0) {
      out << "channels: []\n";
    } else {
      out << "channels:\n";
      for (auto item : msg.channels) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: link_quality
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "link_quality: ";
    rosidl_generator_traits::value_to_yaml(msg.link_quality, out);
    out << "\n";
  }

  // member: rssi_dbm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rssi_dbm: ";
    rosidl_generator_traits::value_to_yaml(msg.rssi_dbm, out);
    out << "\n";
  }

  // member: failsafe
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "failsafe: ";
    rosidl_generator_traits::value_to_yaml(msg.failsafe, out);
    out << "\n";
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CRSFChannels & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace crsf_parser

namespace rosidl_generator_traits
{

[[deprecated("use crsf_parser::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const crsf_parser::msg::CRSFChannels & msg,
  std::ostream & out, size_t indentation = 0)
{
  crsf_parser::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use crsf_parser::msg::to_yaml() instead")]]
inline std::string to_yaml(const crsf_parser::msg::CRSFChannels & msg)
{
  return crsf_parser::msg::to_yaml(msg);
}

template<>
inline const char * data_type<crsf_parser::msg::CRSFChannels>()
{
  return "crsf_parser::msg::CRSFChannels";
}

template<>
inline const char * name<crsf_parser::msg::CRSFChannels>()
{
  return "crsf_parser/msg/CRSFChannels";
}

template<>
struct has_fixed_size<crsf_parser::msg::CRSFChannels>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<crsf_parser::msg::CRSFChannels>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<crsf_parser::msg::CRSFChannels>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__TRAITS_HPP_
