#ifndef __TIMER_H__
#define __TIMER_H__
#include "../../LIB/STD_TYPES.h"

void TMR0_init(void); // Initialize the timer
void TMR0_setOvfCallBack(void (*func)(void)); // Set the callback function for the timer overflow interrupt
void TMR0_setInterval_ms(uint32_t time); // Set the timer interval in milliseconds
void TMR0_reset(void); // Reset the timer
void TMR0_delay_ms(uint32_t time);  // Busy wait delay in milliseconds

uint32_t TMR0_OVF_Counter; // Timer overflow limit
uint8_t TMR0_OVF_Preload;  // Timer overflow pre-load value
uint32_t Elapsed_Time;  // Elapsed time in overflow counts --> 1 ovf is roughly 33 ms at 1024 prescaler

void (*TMR0_OvfCallBack)(void);  // Pointer to the timer overflow callback function


#endif // __TIMER_H__
