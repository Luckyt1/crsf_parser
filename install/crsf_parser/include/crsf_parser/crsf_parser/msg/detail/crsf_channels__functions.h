// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from crsf_parser:msg/CRSFChannels.idl
// generated code does not contain a copyright notice

#ifndef CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__FUNCTIONS_H_
#define CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "crsf_parser/msg/rosidl_generator_c__visibility_control.h"

#include "crsf_parser/msg/detail/crsf_channels__struct.h"

/// Initialize msg/CRSFChannels message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * crsf_parser__msg__CRSFChannels
 * )) before or use
 * crsf_parser__msg__CRSFChannels__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_crsf_parser
bool
crsf_parser__msg__CRSFChannels__init(crsf_parser__msg__CRSFChannels * msg);

/// Finalize msg/CRSFChannels message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_crsf_parser
void
crsf_parser__msg__CRSFChannels__fini(crsf_parser__msg__CRSFChannels * msg);

/// Create msg/CRSFChannels message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * crsf_parser__msg__CRSFChannels__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_crsf_parser
crsf_parser__msg__CRSFChannels *
crsf_parser__msg__CRSFChannels__create();

/// Destroy msg/CRSFChannels message.
/**
 * It calls
 * crsf_parser__msg__CRSFChannels__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_crsf_parser
void
crsf_parser__msg__CRSFChannels__destroy(crsf_parser__msg__CRSFChannels * msg);

/// Check for msg/CRSFChannels message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_crsf_parser
bool
crsf_parser__msg__CRSFChannels__are_equal(const crsf_parser__msg__CRSFChannels * lhs, const crsf_parser__msg__CRSFChannels * rhs);

/// Copy a msg/CRSFChannels message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_crsf_parser
bool
crsf_parser__msg__CRSFChannels__copy(
  const crsf_parser__msg__CRSFChannels * input,
  crsf_parser__msg__CRSFChannels * output);

/// Initialize array of msg/CRSFChannels messages.
/**
 * It allocates the memory for the number of elements and calls
 * crsf_parser__msg__CRSFChannels__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_crsf_parser
bool
crsf_parser__msg__CRSFChannels__Sequence__init(crsf_parser__msg__CRSFChannels__Sequence * array, size_t size);

/// Finalize array of msg/CRSFChannels messages.
/**
 * It calls
 * crsf_parser__msg__CRSFChannels__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_crsf_parser
void
crsf_parser__msg__CRSFChannels__Sequence__fini(crsf_parser__msg__CRSFChannels__Sequence * array);

/// Create array of msg/CRSFChannels messages.
/**
 * It allocates the memory for the array and calls
 * crsf_parser__msg__CRSFChannels__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_crsf_parser
crsf_parser__msg__CRSFChannels__Sequence *
crsf_parser__msg__CRSFChannels__Sequence__create(size_t size);

/// Destroy array of msg/CRSFChannels messages.
/**
 * It calls
 * crsf_parser__msg__CRSFChannels__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_crsf_parser
void
crsf_parser__msg__CRSFChannels__Sequence__destroy(crsf_parser__msg__CRSFChannels__Sequence * array);

/// Check for msg/CRSFChannels message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_crsf_parser
bool
crsf_parser__msg__CRSFChannels__Sequence__are_equal(const crsf_parser__msg__CRSFChannels__Sequence * lhs, const crsf_parser__msg__CRSFChannels__Sequence * rhs);

/// Copy an array of msg/CRSFChannels messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_crsf_parser
bool
crsf_parser__msg__CRSFChannels__Sequence__copy(
  const crsf_parser__msg__CRSFChannels__Sequence * input,
  crsf_parser__msg__CRSFChannels__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CRSF_PARSER__MSG__DETAIL__CRSF_CHANNELS__FUNCTIONS_H_
