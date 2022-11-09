#include "app.h"


    /*
    APP_start function
    Description: Initialize the application
    
     Start in normal mode
     Initialize External Interrupt 0 for the push button (Pull up, and  falling edge)
     Set the callback function for the interrupt --> On press enable pedestrian mode
     Initialize the timer 
     Set the callback function for the timer overflow --> On overflow, update the traffic light state, re-enable EXTI0.
     Set the timer overflow interval to 5 seconds
     Initialize traffic lights to output, set initial state --> Green for cars, Red for pedestrians
     Enable global interrupts

    */

void APP_start(void){ // Initialize the application

    EXTI0_voidInit(); // Initialize External Interrupt 0 for the push button (Pull up, and  falling edge)
    EXTI0_setCallBack(APP_pedestrianMode); // Set the callback function for the interrupt --> On press enable pedestrian mode
    TL_init(); // Initialize traffic lights to output, set initial state --> Green for cars, Red for pedestrians
    TMR0_setOvfCallBack(APP_enableButtonOnUpdate); // Set the callback function for the timer overflow --> On overflow, update the traffic light state, re-enable EXTI0.
    TMR0_init();// Initialize the timer
    TMR0_setInterval_ms(5000);// Set the timer overflow interval to 5 seconds
    GIE_ENABLE();// Enable global interrupts
}

void APP_enableButtonOnUpdate(void) // Update the traffic light state, re-enable EXTI0 (disabled on button press)
{
    TL_update();// Update the traffic light state
    EXTI0_ENABLE();// Enable the external interrupt 0
}

void APP_pedestrianMode(void)  // Pedestrian mode, refer to system flow chart for logic.
{
    EXTI0_DISABLE(); // Disable the button to prevent multiple presses
    switch (CarTrafficLightState)  // Check the current state of the car traffic light

    {
    case YELLOW: // If the car traffic light is yellow-red, do nothing.
        return;

    case YELLOW2: // If the car traffic light is yellow-green, set car to yellow-red, ped to yellow-green.
        TL_setStateCar(YELLOW);
        TL_setStatePed(YELLOW2);
        break;

    case GREEN: // If the car traffic light is green, set car to yellow-red, ped to yellow-green.
        TL_setStateCar(YELLOW); 
        TL_setStatePed(YELLOW2);
        break;

    case RED: // If the car traffic light is red, do nothing.
        return;

    default: // If the car traffic light is in an unknown state, do nothing.
        return;
    }
    TMR0_reset(); // Reset the timer to start counting from 0 again.
    return;
}
