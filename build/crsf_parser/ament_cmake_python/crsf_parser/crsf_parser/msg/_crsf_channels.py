# generated from rosidl_generator_py/resource/_idl.py.em
# with input from crsf_parser:msg/CRSFChannels.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'channels'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CRSFChannels(type):
    """Metaclass of message 'CRSFChannels'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('crsf_parser')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'crsf_parser.msg.CRSFChannels')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__crsf_channels
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__crsf_channels
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__crsf_channels
            cls._TYPE_SUPPORT = module.type_support_msg__msg__crsf_channels
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__crsf_channels

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CRSFChannels(metaclass=Metaclass_CRSFChannels):
    """Message class 'CRSFChannels'."""

    __slots__ = [
        '_channels',
        '_link_quality',
        '_rssi_dbm',
        '_failsafe',
        '_timestamp',
    ]

    _fields_and_field_types = {
        'channels': 'uint16[16]',
        'link_quality': 'uint8',
        'rssi_dbm': 'uint8',
        'failsafe': 'boolean',
        'timestamp': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint16'), 16),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'channels' not in kwargs:
            self.channels = numpy.zeros(16, dtype=numpy.uint16)
        else:
            self.channels = kwargs.get('channels')
        self.link_quality = kwargs.get('link_quality', int())
        self.rssi_dbm = kwargs.get('rssi_dbm', int())
        self.failsafe = kwargs.get('failsafe', bool())
        self.timestamp = kwargs.get('timestamp', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if any(self.channels != other.channels):
            return False
        if self.link_quality != other.link_quality:
            return False
        if self.rssi_dbm != other.rssi_dbm:
            return False
        if self.failsafe != other.failsafe:
            return False
        if self.timestamp != other.timestamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def channels(self):
        """Message field 'channels'."""
        return self._channels

    @channels.setter
    def channels(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint16, \
                "The 'channels' numpy.ndarray() must have the dtype of 'numpy.uint16'"
            assert value.size == 16, \
                "The 'channels' numpy.ndarray() must have a size of 16"
            self._channels = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 16 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 65536 for val in value)), \
                "The 'channels' field must be a set or sequence with length 16 and each value of type 'int' and each unsigned integer in [0, 65535]"
        self._channels = numpy.array(value, dtype=numpy.uint16)

    @builtins.property
    def link_quality(self):
        """Message field 'link_quality'."""
        return self._link_quality

    @link_quality.setter
    def link_quality(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'link_quality' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'link_quality' field must be an unsigned integer in [0, 255]"
        self._link_quality = value

    @builtins.property
    def rssi_dbm(self):
        """Message field 'rssi_dbm'."""
        return self._rssi_dbm

    @rssi_dbm.setter
    def rssi_dbm(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rssi_dbm' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'rssi_dbm' field must be an unsigned integer in [0, 255]"
        self._rssi_dbm = value

    @builtins.property
    def failsafe(self):
        """Message field 'failsafe'."""
        return self._failsafe

    @failsafe.setter
    def failsafe(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'failsafe' field must be of type 'bool'"
        self._failsafe = value

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'timestamp' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'timestamp' field must be an unsigned integer in [0, 4294967295]"
        self._timestamp = value
