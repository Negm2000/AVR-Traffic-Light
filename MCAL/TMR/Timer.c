#include "TMR_Interface.h"
#include "TMR_Registers.h"
#include "TMR_Config.h"
#include "../../LIB/Bit_Math.h"
#include "../INT/INT_lib.h"

void TMR0_init(void) 
{
// Set Timer0 to Normal mode
#if TMR0_CMP_MODE == NORMAL
    clrPin(TCCR0, WGM00);
    clrPin(TCCR0, WGM01);

// Set Timer0 to toggle on compare 
#elif TMR0_CMP_MODE == TOGGLE
    setPin(TCCR0, WGM00);
    clrPin(TCCR0, WGM01);

// Set Timer0 to clear on compare 
#elif TMR0_CMP_MODE == CLEAR
    clrPin(TCCR0, WGM00);
    setPin(TCCR0, WGM01);

// Set Timer0 to set on compare 
#elif TMR0_CMP_MODE == SET
    setPin(TCCR0, WGM00);
    setPin(TCCR0, WGM01);
#endif

// Set Timer0 clock prescaler or source
#if TMR0_CLK_SELECT == NO_CLOCK
    clrPin(TCCR0, CS00);
    clrPin(TCCR0, CS01);
    clrPin(TCCR0, CS02);

#elif TMR0_CLK_SELECT == CLK
    setPin(TCCR0, CS00);
    clrPin(TCCR0, CS01);
    clrPin(TCCR0, CS02);

#elif TMR0_CLK_SELECT == CLK_8
    clrPin(TCCR0, CS00);
    setPin(TCCR0, CS01);
    clrPin(TCCR0, CS02);

#elif TMR0_CLK_SELECT == CLK_64
    setPin(TCCR0, CS00);
    setPin(TCCR0, CS01);
    clrPin(TCCR0, CS02);

#elif TMR0_CLK_SELECT == CLK_256
    clrPin(TCCR0, CS00);
    clrPin(TCCR0, CS01);
    setPin(TCCR0, CS02);

#elif TMR0_CLK_SELECT == CLK_1024
    setPin(TCCR0, CS00);
    clrPin(TCCR0, CS01);
    setPin(TCCR0, CS02);

#elif TMR0_CLK_SELECT == EXTERNAL_CLK_FALLING
    clrPin(TCCR0, CS00);
    setPin(TCCR0, CS01);
    setPin(TCCR0, CS02);

#elif TMR0_CLK_SELECT == EXTERNAL_CLK_RISING
    setPin(TCCR0, CS00);
    setPin(TCCR0, CS01);
    setPin(TCCR0, CS02);
#endif

// Enable Timer0 overflow interrupt
#if TMR_OVF_INTERRUPT_ENABLE == 1
    setPin(TIMSK, TOIE0);
#else
    clrPin(TIMSK, TOIE0);
#endif

// Enable Timer0 compare interrupt
#if TMR_CMP_INTERRUPT_ENABLE == 1
    setPin(TIMSK, TOIE1);
#else
    clrPin(TIMSK, TOIE1);
#endif

// Set Timer0 initial value
    TCNT0 = TMR0_PRELOAD;
    OCR0 = OCR0_VALUE;
    TMR0_OVF_Counter = 0;
    TMR0_OVF_Preload = 0;
    Elapsed_Time = 0;
}

void TMR0_setOvfCallBack(void (*func)(void))
{   // Set Timer0 overflow callback function
    TMR0_OvfCallBack = func;
}


void TMR0_setPreload(uint8_t preload)
{   // Set Timer0 preload value
    TCNT0 = preload;
}

void TMR0_setCompareVal(uint8_t val)
{   // Set Timer0 compare value
    OCR0 = val;
}

void TMR0_setInterval_ms(uint32_t time)
{    
// Calculate the number of overflows needed to generate the required time



// Number of Overflows = (Required Time) / (Timer0 Period)

// Number of Overflows = ((Prescaler) / ((F_CPU)) * (2^8) * 1000 ms))
// Number of overflows --> Integer part of the above equation
// Preload value --> 256(1 - (Fractional part of the above equation))

    float ovf_count = (float)time / (((TMR0_PRESCALER / F_CPU) * 256.0) * 1000); // 
    TMR0_OVF_Preload = 256 - ((ovf_count - (uint32_t)ovf_count) * 256);
    TMR0_setPreload(TMR0_OVF_Preload);
    TMR0_OVF_Counter = (uint32_t)ovf_count;

    /*
    Lets say we want to wait 1 second
    time = 1 second = 1000 ms
    ovf_count = desired time / overflow time --> 1000 / (((1024/8000000) * 256) * 1000) = 30.517578125
    Preload = 256- (fractional part * 256) --> fractional part =  float - int(float) = 0.517578125
     256-((30.517578125-30)*256) = 123.5 --> 123
    OVFCOUNT = 30
    */
}

ISR(TMR0_OVF) // TMR0 overflow interrupt service routine
{
    Elapsed_Time++; // Increment Overflow Counter

    if (Elapsed_Time > TMR0_OVF_Counter) // Check if the required number of overflows has occurred
    {
        if (TMR0_OvfCallBack != (void *)0) // Check if the callback function is not NULL
            TMR0_OvfCallBack();  // Call the callback function

        Elapsed_Time = 0; // Reset Overflow Counter
        TMR0_setPreload(TMR0_OVF_Preload); // Reset Timer0 Preload
    }
}

void TMR0_reset(void) // Reset Timer0
{
    Elapsed_Time = 0;  // Reset Overflow Counter
    TMR0_setPreload(TMR0_OVF_Preload); // Reset Timer0 preload value
}

void TMR0_delay_ms(uint32_t time)
{
    // Busy wait for the required time
    uint8_t temp_Preload = TMR0_OVF_Preload;   // save the current preload value
    uint32_t temp_OVFCOUNT = TMR0_OVF_Counter; // Save the current values
    uint32_t temp_ovf_counter = Elapsed_Time;  // Save the current values

    TMR0_reset();
    TMR0_setInterval_ms(time);
    while (Elapsed_Time <= TMR0_OVF_Counter){asm("NOP");}; // wait until the desired time is reached

    TMR0_setPreload(temp_Preload); // restore the previous values
    TMR0_OVF_Counter = temp_OVFCOUNT; // restore the previous values
    Elapsed_Time = temp_ovf_counter;  // restore the previous values
}
