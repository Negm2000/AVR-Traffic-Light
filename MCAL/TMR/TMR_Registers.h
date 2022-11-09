#ifndef __TIMER_REGISTERS_H__
#define __TIMER_REGISTERS_H__
#include "../../LIB/STD_TYPES.h"

#define OCR0 *(volatile uint8_t*) 0x5C
#define TCCR0 *(volatile uint8_t*) 0x53
#define TCNT0 *(volatile uint8_t*) 0x52
#define TIMSK *(volatile uint8_t*) 0x59

// Pins

#define CS00 0
#define CS01 1
#define CS02 2

#define WGM01 3
#define WGM00 6

#define TOIE0 0
#define TOIE1 1



#endif // __TIMER_REGISTERS_H__
