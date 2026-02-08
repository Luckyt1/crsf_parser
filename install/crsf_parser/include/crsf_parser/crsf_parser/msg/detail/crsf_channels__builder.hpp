// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from crsf_parser:msg/CRSFChannels.idl
// generated code does not contain a copyright notice

#ifndef CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__BUILDER_HPP_
#define CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "crsf_parser/msg/detail/crsf_channels__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace crsf_parser
{

namespace msg
{

namespace builder
{

class Init_CRSFChannels_timestamp
{
public:
  explicit Init_CRSFChannels_timestamp(::crsf_parser::msg::CRSFChannels & msg)
  : msg_(msg)
  {}
  ::crsf_parser::msg::CRSFChannels timestamp(::crsf_parser::msg::CRSFChannels::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::crsf_parser::msg::CRSFChannels msg_;
};

class Init_CRSFChannels_failsafe
{
public:
  explicit Init_CRSFChannels_failsafe(::crsf_parser::msg::CRSFChannels & msg)
  : msg_(msg)
  {}
  Init_CRSFChannels_timestamp failsafe(::crsf_parser::msg::CRSFChannels::_failsafe_type arg)
  {
    msg_.failsafe = std::move(arg);
    return Init_CRSFChannels_timestamp(msg_);
  }

private:
  ::crsf_parser::msg::CRSFChannels msg_;
};

class Init_CRSFChannels_rssi_dbm
{
public:
  explicit Init_CRSFChannels_rssi_dbm(::crsf_parser::msg::CRSFChannels & msg)
  : msg_(msg)
  {}
  Init_CRSFChannels_failsafe rssi_dbm(::crsf_parser::msg::CRSFChannels::_rssi_dbm_type arg)
  {
    msg_.rssi_dbm = std::move(arg);
    return Init_CRSFChannels_failsafe(msg_);
  }

private:
  ::crsf_parser::msg::CRSFChannels msg_;
};

class Init_CRSFChannels_link_quality
{
public:
  explicit Init_CRSFChannels_link_quality(::crsf_parser::msg::CRSFChannels & msg)
  : msg_(msg)
  {}
  Init_CRSFChannels_rssi_dbm link_quality(::crsf_parser::msg::CRSFChannels::_link_quality_type arg)
  {
    msg_.link_quality = std::move(arg);
    return Init_CRSFChannels_rssi_dbm(msg_);
  }

private:
  ::crsf_parser::msg::CRSFChannels msg_;
};

class Init_CRSFChannels_channels
{
public:
  Init_CRSFChannels_channels()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CRSFChannels_link_quality channels(::crsf_parser::msg::CRSFChannels::_channels_type arg)
  {
    msg_.channels = std::move(arg);
    return Init_CRSFChannels_link_quality(msg_);
  }

private:
  ::crsf_parser::msg::CRSFChannels msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::crsf_parser::msg::CRSFChannels>()
{
  return crsf_parser::msg::builder::Init_CRSFChannels_channels();
}

}  // namespace crsf_parser

#endif  // CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__BUILDER_HPP_
