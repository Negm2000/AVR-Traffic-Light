#ifndef __TMR_CONFIG_H__
#define __TMR_CONFIG_H__

#define F_CPU 8000000UL
#define TMR0_PRESCALER  1024.0
#define TMR0_PRELOAD    0
#define OCR0_VALUE      0


//Compare Match Output Mode


    #define NORMAL 0 
    #define TOGGLE 1
    #define CLEAR 2
    #define SET 3



#define TMR0_CMP_MODE NORMAL


    #define NO_CLOCK 0
    #define CLK 1
    #define CLK_8 2
    #define CLK_64 3
    #define CLK_256 4
    #define CLK_1024 5
    #define EXTERNAL_CLK_FALLING 6
    #define EXTERNAL_CLK_RISING 7


#define TMR0_CLK_SELECT CLK_1024


#define TMR_CMP_INTERRUPT_ENABLE 0
#define TMR_OVF_INTERRUPT_ENABLE 1





#endif // __TMR_CONFIG_H__
