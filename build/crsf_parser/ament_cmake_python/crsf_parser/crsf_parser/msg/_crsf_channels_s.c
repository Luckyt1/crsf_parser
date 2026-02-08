// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from crsf_parser:msg/CRSFChannels.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "crsf_parser/msg/detail/crsf_channels__struct.h"
#include "crsf_parser/msg/detail/crsf_channels__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool crsf_parser__msg__crsf_channels__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("crsf_parser.msg._crsf_channels.CRSFChannels", full_classname_dest, 43) == 0);
  }
  crsf_parser__msg__CRSFChannels * ros_message = _ros_message;
  {  // channels
    PyObject * field = PyObject_GetAttrString(_pymsg, "channels");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_UINT16);
      Py_ssize_t size = 16;
      uint16_t * dest = ros_message->channels;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint16_t tmp = *(npy_uint16 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint16_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // link_quality
    PyObject * field = PyObject_GetAttrString(_pymsg, "link_quality");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->link_quality = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rssi_dbm
    PyObject * field = PyObject_GetAttrString(_pymsg, "rssi_dbm");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rssi_dbm = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // failsafe
    PyObject * field = PyObject_GetAttrString(_pymsg, "failsafe");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->failsafe = (Py_True == field);
    Py_DECREF(field);
  }
  {  // timestamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "timestamp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->timestamp = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * crsf_parser__msg__crsf_channels__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CRSFChannels */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("crsf_parser.msg._crsf_channels");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CRSFChannels");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  crsf_parser__msg__CRSFChannels * ros_message = (crsf_parser__msg__CRSFChannels *)raw_ros_message;
  {  // channels
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "channels");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_UINT16);
    assert(sizeof(npy_uint16) == sizeof(uint16_t));
    npy_uint16 * dst = (npy_uint16 *)PyArray_GETPTR1(seq_field, 0);
    uint16_t * src = &(ros_message->channels[0]);
    memcpy(dst, src, 16 * sizeof(uint16_t));
    Py_DECREF(field);
  }
  {  // link_quality
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->link_quality);
    {
      int rc = PyObject_SetAttrString(_pymessage, "link_quality", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rssi_dbm
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rssi_dbm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rssi_dbm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // failsafe
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->failsafe ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "failsafe", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // timestamp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->timestamp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "timestamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
