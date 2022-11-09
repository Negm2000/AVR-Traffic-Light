#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__

typedef unsigned char uint8_t; // 0 to 255
typedef unsigned short uint16_t; // 0 to 65535
typedef unsigned int uint32_t;  // 0 to 4294967295
typedef unsigned long long uint64_t;  // 0 to 18446744073709551615
typedef signed char int8_t; // -128 to 127
typedef signed short int16_t; // -32768 to 32767
typedef signed int int32_t; // -2147483648 to 2147483647
typedef signed long long int64_t; // -9223372036854775808 to 9223372036854775807
typedef float float32_t; // 1.2E-38 to 3.4E+38
typedef double float64_t; // 2.3E-308 to 1.7E+308

typedef volatile uint8_t *const PORT_ADDRESS;  //  Pointer to a volatile 8 bit memory location (Location is constant)
#define PORT *(PORT_ADDRESS) // Dereference the pointer to get the value at the address

#endif // __STD_TYPES_H__
