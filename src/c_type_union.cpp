#include <cstdint>
#include <stdio.h>

#ifdef WIN32
    #define DLLEXPORT _declspec(dllexport)
#else
    #define DLLEXPORT
#endif

extern "C"
{
    struct point
    {
        float x;
        float y;
    };

    enum value_type
    {
        vt_int8 = 1,
        vt_int16,
        vt_int32,
        vt_int64,
        vt_uint8,
        vt_uint16,
        vt_uint32,
        vt_uint64,
        vt_bool,
        vt_point
    };

    struct value
    {
        value_type vt;
        union
        {
            bool bVal;
            int8_t i8Val;
            int16_t i16Val;
            int32_t i32Val;
            int64_t i64Val;
            uint8_t ui8Val;
            uint16_t ui16Val;
            uint32_t ui32Val;
            uint64_t ui64Val;
            point pointVal;
        };
    };
}

struct value_impl : virtual value
{
    value_impl(bool val)
    {
        vt = vt_bool;
        bVal = val;
    }

    value_impl(int8_t val)
    {
        vt = vt_int8;
        i8Val = val;
    }

    value_impl(int16_t val)
    {
        vt = vt_int16;
        i16Val = val;
    }

    value_impl(int32_t val)
    {
        vt = vt_int32;
        i32Val = val;
    }

    value_impl(int64_t val)
    {
        vt = vt_int64;
        i64Val = val;
    }

    value_impl(uint8_t val)
    {
        vt = vt_uint8;
        ui8Val = val;
    }

    value_impl(uint16_t val)
    {
        vt = vt_uint16;
        ui16Val = val;
    }

    value_impl(uint32_t val)
    {
        vt = vt_uint32;
        ui32Val = val;
    }

    value_impl(uint64_t val)
    {
        vt = vt_uint64;
        ui64Val = val;
    }

    value_impl(point val)
    {
        vt = vt_point;
        pointVal = val;
    }

};

extern "C"
{
    DLLEXPORT void print_value(value v)
    {
        switch (v.vt)
        {
        case vt_int8:
            printf("int8_t %d\n", v.i8Val);
            break;
        case vt_int16:
            printf("int16_t %d\n", v.i16Val);
            break;
        case vt_int32:
            printf("int32_t %d\n", v.i32Val);
            break;
        case vt_int64:
            printf("int64_t %lld\n", v.i64Val);
            break;
        case vt_uint8:
            printf("uint8_t %u\n", v.ui8Val);
            break;
        case vt_uint16:
            printf("uint16_t %u\n", v.ui16Val);
            break;
        case vt_uint32:
            printf("uint32_t %u\n", v.ui32Val);
            break;
        case vt_uint64:
            printf("uint64_t %llu\n", v.ui64Val);
            break;
        case vt_bool:
            printf("bool %s\n", v.bVal ? "true" : "false");
            break;
        case vt_point:
            printf("point (%f, %f)\n", v.pointVal.x, v.pointVal.y);
            break;
        }
    }

    DLLEXPORT value get_bool_value(bool val)
    {
        return value_impl(val);
    }

    DLLEXPORT value get_int8_value(int8_t val)
    {
        return value_impl(val);
    }

    DLLEXPORT value get_int16_value(int16_t val)
    {
        return value_impl(val);
    }

    DLLEXPORT value get_int32_value(int32_t val)
    {
        return value_impl(val);
    }

    DLLEXPORT value get_int64_value(int64_t val)
    {
        return value_impl(val);
    }

    DLLEXPORT value get_uint8_value(uint8_t val)
    {
        return value_impl(val);
    }

    DLLEXPORT value get_uint16_value(uint16_t val)
    {
        return value_impl(val);
    }

    DLLEXPORT value get_uint32_value(uint32_t val)
    {
        return value_impl(val);
    }

    DLLEXPORT value get_uint64_value(uint64_t val)
    {
        return value_impl(val);
    }

    DLLEXPORT value get_point_value(point val)
    {
        return value_impl(val);
    }

}
