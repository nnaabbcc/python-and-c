#include <cstdint>
#include <stdio.h>
#include <memory>

#ifdef WIN32
    #define DLLEXPORT _declspec(dllexport)
#else
    #define DLLEXPORT
#endif

extern "C"
{

struct test_struct
{
    int32_t x;
    int32_t y;
    float z;
};

DLLEXPORT void print_struct_pointer(test_struct* t)
{
    printf("%d %d %f\n", t->x, t->y, t->z);
}

DLLEXPORT void print_struct(test_struct t)
{
    print_struct_pointer(&t);
}

DLLEXPORT test_struct get_struct(int32_t x, int32_t y, float z)
{
    return test_struct{x, y, z};
}

DLLEXPORT test_struct* get_struct_pointer(int32_t x, int32_t y, float z)
{
    auto t = static_cast<test_struct*>(malloc(sizeof(test_struct)));
    t->x = x;
    t->y = y;
    t->z = z;
    return t;
}

DLLEXPORT void free_struct_pointer(test_struct* t)
{
    free(t);
}

DLLEXPORT int32_t add_test(int32_t x, int32_t y)
{
    return x + y;
}

}