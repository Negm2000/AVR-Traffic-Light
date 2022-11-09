#ifndef DIO_H_
#define DIO_H_
#include "DIO_Registers.h"
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"

#define PU   2  // Pull up
#define OUT  1 // Output Mode
#define IN  0 // Input Mode
#define HIGH  1 // High Voltage
#define LOW  0 // Low Voltage

void DIO_pinMode (uint8_t reg, uint8_t pin, uint8_t direction); // Set pin direction
void DIO_pinWrite (uint8_t reg, uint8_t pin, uint8_t value); // Set pin value
void DIO_pinToggle (uint8_t reg, uint8_t pin); // Toggle pin value
uint8_t DIO_pinRead (uint8_t reg, uint8_t pin); // Get pin status


void DIO_portMode (uint8_t reg, uint8_t direction); // Set port direction
void DIO_portWrite (uint8_t reg, uint8_t value); // Set port value
uint8_t DIO_portRead (uint8_t reg); // Get port status


#endif