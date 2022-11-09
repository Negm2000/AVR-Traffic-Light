#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

#include "GIE_Register.h"

#define GIE_ENABLE()  (SREG |= (1<<7)) // Enable Global Interrupt
#define GIE_DISABLE() (SREG &= ~(1<<7)) // Disable Global Interrupt

#endif