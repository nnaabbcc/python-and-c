
from ctypes import cdll, Structure, c_int, c_float, byref, pointer, POINTER

class test_struct(Structure):
    _fields_ = [
        ("x", c_int),
        ("y", c_int),
        ("z", c_float)
    ]


lib = cdll.LoadLibrary("bin/c_type_test.dll")


c = lib.add_test(32, 23)
print(c)

t = test_struct(10, 20, 30.0)
lib.print_struct(t)
lib.print_struct(byref(t))
lib.print_struct_pointer(pointer(t))

lib.get_struct.argtypes = [c_int, c_int, c_float]
lib.get_struct.restype = test_struct

t1 = lib.get_struct(1, 2, 3.0)
lib.print_struct(t1)

lib.get_struct_pointer.argtypes = [c_int, c_int, c_float]
lib.get_struct_pointer.restype = POINTER(test_struct)

lib.free_struct_pointer = lib.free_struct_pointer
lib.free_struct_pointer.argtypes = [POINTER(test_struct)]

t2 = lib.get_struct_pointer(100, 200, 300.0)
lib.print_struct_pointer(t2)
lib.free_struct_pointer(t2)

lib.add_test_struct.restype = test_struct

t3 = lib.add_test_struct(t, t1)
lib.print_struct(t3)
