// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from crsf_parser:msg/CRSFChannels.idl
// generated code does not contain a copyright notice

#ifndef CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__STRUCT_HPP_
#define CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__crsf_parser__msg__CRSFChannels __attribute__((deprecated))
#else
# define DEPRECATED__crsf_parser__msg__CRSFChannels __declspec(deprecated)
#endif

namespace crsf_parser
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CRSFChannels_
{
  using Type = CRSFChannels_<ContainerAllocator>;

  explicit CRSFChannels_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint16_t, 16>::iterator, uint16_t>(this->channels.begin(), this->channels.end(), 0);
      this->link_quality = 0;
      this->rssi_dbm = 0;
      this->failsafe = false;
      this->timestamp = 0ul;
    }
  }

  explicit CRSFChannels_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : channels(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint16_t, 16>::iterator, uint16_t>(this->channels.begin(), this->channels.end(), 0);
      this->link_quality = 0;
      this->rssi_dbm = 0;
      this->failsafe = false;
      this->timestamp = 0ul;
    }
  }

  // field types and members
  using _channels_type =
    std::array<uint16_t, 16>;
  _channels_type channels;
  using _link_quality_type =
    uint8_t;
  _link_quality_type link_quality;
  using _rssi_dbm_type =
    uint8_t;
  _rssi_dbm_type rssi_dbm;
  using _failsafe_type =
    bool;
  _failsafe_type failsafe;
  using _timestamp_type =
    uint32_t;
  _timestamp_type timestamp;

  // setters for named parameter idiom
  Type & set__channels(
    const std::array<uint16_t, 16> & _arg)
  {
    this->channels = _arg;
    return *this;
  }
  Type & set__link_quality(
    const uint8_t & _arg)
  {
    this->link_quality = _arg;
    return *this;
  }
  Type & set__rssi_dbm(
    const uint8_t & _arg)
  {
    this->rssi_dbm = _arg;
    return *this;
  }
  Type & set__failsafe(
    const bool & _arg)
  {
    this->failsafe = _arg;
    return *this;
  }
  Type & set__timestamp(
    const uint32_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    crsf_parser::msg::CRSFChannels_<ContainerAllocator> *;
  using ConstRawPtr =
    const crsf_parser::msg::CRSFChannels_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<crsf_parser::msg::CRSFChannels_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<crsf_parser::msg::CRSFChannels_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      crsf_parser::msg::CRSFChannels_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<crsf_parser::msg::CRSFChannels_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      crsf_parser::msg::CRSFChannels_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<crsf_parser::msg::CRSFChannels_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<crsf_parser::msg::CRSFChannels_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<crsf_parser::msg::CRSFChannels_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__crsf_parser__msg__CRSFChannels
    std::shared_ptr<crsf_parser::msg::CRSFChannels_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__crsf_parser__msg__CRSFChannels
    std::shared_ptr<crsf_parser::msg::CRSFChannels_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CRSFChannels_ & other) const
  {
    if (this->channels != other.channels) {
      return false;
    }
    if (this->link_quality != other.link_quality) {
      return false;
    }
    if (this->rssi_dbm != other.rssi_dbm) {
      return false;
    }
    if (this->failsafe != other.failsafe) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const CRSFChannels_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CRSFChannels_

// alias to use template instance with default allocator
using CRSFChannels =
  crsf_parser::msg::CRSFChannels_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace crsf_parser

#endif  // CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__STRUCT_HPP_
