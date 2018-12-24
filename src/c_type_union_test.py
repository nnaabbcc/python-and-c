from ctypes import (cdll, Structure, Union, POINTER, byref, pointer,
    c_bool, c_byte, c_short, c_int, c_longlong, c_ubyte, c_ushort, c_uint, c_ulonglong, c_float)

# point type
class point(Structure):
    _fields_ = [
        ('x', c_float),
        ('y', c_float)
    ]

# value type
(vt_int8, vt_int16, vt_int32, vt_int64, vt_uint8, vt_uint16, vt_uint32, vt_uint64, vt_bool, vt_point) = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

# value union
class value_union(Union):
    _fields_ = [
        ('bVal', c_bool),
        ('i8Val', c_byte),
        ('i16Val', c_short),
        ('i32Val', c_int),
        ('i64Val', c_longlong),
        ('ui8Val', c_ubyte),
        ('ui16Val', c_ushort),
        ('ui32Val', c_uint),
        ('ui64Val', c_ulonglong),
        ('pointVal', point)
    ]

# value type
class value(Structure):
    _anonymous_ = ('u',)
    _fields_ = [
        ('vt', c_int),
        ('u', value_union)
    ]

lib = cdll.LoadLibrary("bin/c_type_test.dll")

lib.get_bool_value.restype = value
lib.get_int8_value.restype = value
lib.get_int16_value.restype = value
lib.get_int32_value.restype = value
lib.get_int64_value.restype = value
lib.get_uint8_value.restype = value
lib.get_uint16_value.restype = value
lib.get_uint32_value.restype = value
lib.get_uint64_value.restype = value
lib.get_point_value.restype = value

v = lib.get_bool_value(True)
lib.print_value(v) # true

v = lib.get_bool_value(False)
lib.print_value(v) # false

v = lib.get_int8_value(10)
lib.print_value(v) # 10

v = lib.get_int8_value(127)
lib.print_value(v) # 127

v = lib.get_int8_value(128)
lib.print_value(v) # -128

v = lib.get_int8_value(129)
lib.print_value(v) # -127

v = lib.get_int8_value(0)
lib.print_value(v) # 0

v = lib.get_int16_value(-1)
lib.print_value(v)

v = lib.get_int32_value(-1)
lib.print_value(v)

v = lib.get_int64_value(-1)
lib.print_value(v)

v = lib.get_uint8_value(-1)
lib.print_value(v)

v = lib.get_uint16_value(-1)
lib.print_value(v)

v = lib.get_uint32_value(-1)
lib.print_value(v)

v = lib.get_uint64_value(-1)
lib.print_value(v)

v = lib.get_point_value(point(21.0, 22.0))
lib.print_value(v)
