// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from crsf_parser:msg/CRSFChannels.idl
// generated code does not contain a copyright notice
#include "crsf_parser/msg/detail/crsf_channels__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
crsf_parser__msg__CRSFChannels__init(crsf_parser__msg__CRSFChannels * msg)
{
  if (!msg) {
    return false;
  }
  // channels
  // link_quality
  // rssi_dbm
  // failsafe
  // timestamp
  return true;
}

void
crsf_parser__msg__CRSFChannels__fini(crsf_parser__msg__CRSFChannels * msg)
{
  if (!msg) {
    return;
  }
  // channels
  // link_quality
  // rssi_dbm
  // failsafe
  // timestamp
}

bool
crsf_parser__msg__CRSFChannels__are_equal(const crsf_parser__msg__CRSFChannels * lhs, const crsf_parser__msg__CRSFChannels * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // channels
  for (size_t i = 0; i < 16; ++i) {
    if (lhs->channels[i] != rhs->channels[i]) {
      return false;
    }
  }
  // link_quality
  if (lhs->link_quality != rhs->link_quality) {
    return false;
  }
  // rssi_dbm
  if (lhs->rssi_dbm != rhs->rssi_dbm) {
    return false;
  }
  // failsafe
  if (lhs->failsafe != rhs->failsafe) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  return true;
}

bool
crsf_parser__msg__CRSFChannels__copy(
  const crsf_parser__msg__CRSFChannels * input,
  crsf_parser__msg__CRSFChannels * output)
{
  if (!input || !output) {
    return false;
  }
  // channels
  for (size_t i = 0; i < 16; ++i) {
    output->channels[i] = input->channels[i];
  }
  // link_quality
  output->link_quality = input->link_quality;
  // rssi_dbm
  output->rssi_dbm = input->rssi_dbm;
  // failsafe
  output->failsafe = input->failsafe;
  // timestamp
  output->timestamp = input->timestamp;
  return true;
}

crsf_parser__msg__CRSFChannels *
crsf_parser__msg__CRSFChannels__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  crsf_parser__msg__CRSFChannels * msg = (crsf_parser__msg__CRSFChannels *)allocator.allocate(sizeof(crsf_parser__msg__CRSFChannels), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(crsf_parser__msg__CRSFChannels));
  bool success = crsf_parser__msg__CRSFChannels__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
crsf_parser__msg__CRSFChannels__destroy(crsf_parser__msg__CRSFChannels * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    crsf_parser__msg__CRSFChannels__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
crsf_parser__msg__CRSFChannels__Sequence__init(crsf_parser__msg__CRSFChannels__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  crsf_parser__msg__CRSFChannels * data = NULL;

  if (size) {
    data = (crsf_parser__msg__CRSFChannels *)allocator.zero_allocate(size, sizeof(crsf_parser__msg__CRSFChannels), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = crsf_parser__msg__CRSFChannels__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        crsf_parser__msg__CRSFChannels__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
crsf_parser__msg__CRSFChannels__Sequence__fini(crsf_parser__msg__CRSFChannels__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      crsf_parser__msg__CRSFChannels__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

crsf_parser__msg__CRSFChannels__Sequence *
crsf_parser__msg__CRSFChannels__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  crsf_parser__msg__CRSFChannels__Sequence * array = (crsf_parser__msg__CRSFChannels__Sequence *)allocator.allocate(sizeof(crsf_parser__msg__CRSFChannels__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = crsf_parser__msg__CRSFChannels__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
crsf_parser__msg__CRSFChannels__Sequence__destroy(crsf_parser__msg__CRSFChannels__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    crsf_parser__msg__CRSFChannels__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
crsf_parser__msg__CRSFChannels__Sequence__are_equal(const crsf_parser__msg__CRSFChannels__Sequence * lhs, const crsf_parser__msg__CRSFChannels__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!crsf_parser__msg__CRSFChannels__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
crsf_parser__msg__CRSFChannels__Sequence__copy(
  const crsf_parser__msg__CRSFChannels__Sequence * input,
  crsf_parser__msg__CRSFChannels__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(crsf_parser__msg__CRSFChannels);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    crsf_parser__msg__CRSFChannels * data =
      (crsf_parser__msg__CRSFChannels *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!crsf_parser__msg__CRSFChannels__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          crsf_parser__msg__CRSFChannels__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!crsf_parser__msg__CRSFChannels__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
