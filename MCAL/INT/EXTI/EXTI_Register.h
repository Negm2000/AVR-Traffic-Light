#ifndef _EXTI_REG_H_
#define _EXTI_REG_H_
#include "../../../LIB/STD_TYPES.h"

// Define the  General Interrupt Control (GICR) register which controls the peripheral interrupts
#define GICR (*(volatile uint8_t*) 0x5B)

// Define the MCU control register which controls the interrupt sense control
#define MCUCR (*(volatile uint8_t*) 0x55)

// MCU control and status register
#define MCUCSR (*(volatile uint8_t*) 0x54) 

#endif