#include "../../DIO/DIO.h"
#include "../INT_lib.h"
#include "EXTI_Config.h"
#include "EXTI_Register.h"
#include"EXTI_Interface.h"


void EXTI0_voidInit(void){ //  Initialize the external interrupt 0
    
    DIO_pinMode(PORTD, PIN2 , PU); // Enable the pull up resistor on the pin
    // Select the sense control mode based on the configuration
    #if EXTI0_SENSE_MODE == LOW_LEVEL
    clrPin(MCUCR,0);
    clrPin(MCUCR,1);
    #elif EXTI0_SENSE_MODE == IOC
    setPin(MCUCR,0);
    clrPin(MCUCR,1);
    #elif EXTI0_SENSE_MODE == FALLING_EDGE
    clrPin(MCUCR,0);
    setPin(MCUCR,1);
    #elif EXTI0_SENSE_MODE == RISING_EDGE
    setPin(MCUCR,0);
    setPin(MCUCR,1);
    #endif
    EXTI0_ENABLE(); // PIE ---> Active
}

void EXTI0_setCallBack(void (*func)(void)){
    // Set the call back function
    EXTI0_CallBack = func;
}


ISR(EXTI0_vect){
    if(EXTI0_CallBack != (void*) 0){// Check if the call back function is not null
        EXTI0_CallBack(); // Call the call back function
    }
}
