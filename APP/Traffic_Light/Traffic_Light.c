#include "Traffic_Light.h"
#include "Traffic_Light_Config.h"
#include "../../ECUAL/LED/Led.h"
#include "../../MCAL/TMR/TMR_Interface.h"
#include "../../MCAL/DIO/DIO_Registers.h"

void setState(uint8_t TL_Type, EN_TrafficLightState_t state) // Core function
{                                                            // This function is called by the application to change the state of the traffic light.
                                                             // Takes the type of traffic light and the state to be set as arguments.
                                                             // The state is set by calling the appropriate function from the LED module.
    switch (state)
    {
    case GREEN:
        LED_on(TL_Type, GREEN);
        LED_off(TL_Type, YELLOW);
        LED_off(TL_Type, RED);
        break;

    case YELLOW2:
    case YELLOW:
        LED_off(TL_Type, GREEN);
        LED_on(TL_Type, YELLOW);
        LED_off(TL_Type, RED);
        break;

    case RED:
        LED_off(TL_Type, GREEN);
        LED_off(TL_Type, YELLOW);
        LED_on(TL_Type, RED);
        break;

    default:
        break;
    }
}

void update(uint8_t TL_Type, EN_TrafficLightState_t *state) // Core function
{                                                           // Takes the type of traffic light and the state it is in as arguments.
    *state == YELLOW2 ? *state = GREEN : (*state)++;        // Increment the state of the traffic light. If the state is YELLOW2, set it to GREEN.
    setState(TL_Type, *state);                              // Set the new state of the traffic light.
}

void TL_setStateCar(EN_TrafficLightState_t state) // API
{                                                 // This function is called by the application to change the state of the car traffic light.

    CarTrafficLightState = state; // Set the state of the car traffic light to the state passed as an argument.
    setState(CAR, state);         // Set the state of the car traffic light.
}

void TL_setStatePed(EN_TrafficLightState_t state) // API
{
    PedTrafficLightState = state; // Set the state of the pedestrian traffic light to the state passed as an argument.
    setState(PED, state);         // Set the state of the pedestrian traffic light.
}

void TL_init(void) // API
{
    CarTrafficLightState = GREEN; // Store the initial state of the car traffic light to green.
    PedTrafficLightState = RED;   // Store the initial state of the pedestrian traffic light to red.

    // Initialize the car traffic light to output.
    LED_init(CAR, GREEN);
    LED_init(CAR, YELLOW);
    LED_init(CAR, RED);
    // Initialize the pedestrian traffic light to output.
    LED_init(PED, GREEN);
    LED_init(PED, YELLOW);
    LED_init(PED, RED);

    setState(CAR, CarTrafficLightState); // Set the initial state of the car traffic light.
    setState(PED, PedTrafficLightState); // Set the initial state of the pedestrian traffic light.
}

void TL_updateCar(void) // Core
{
    update(CAR, &CarTrafficLightState); // Update the state of the car traffic light.
}

void TL_updatePed(void) // Core
{
    update(PED, &PedTrafficLightState); // Update the state of the pedestrian traffic light.
}

void TL_update(void) // API
{                    // This function is called by the ISR to update the state of both traffic lights.
    TL_updateCar();
    TL_updatePed();
}

void TL_blinkYellow(void) // API
{ // This function is called by the application to blink the yellow LED on both traffic lights.
    static uint32_t TimeOfLastToggle; // To prevent the yellow LED from blinking too fast, we need to keep track of the time of the last toggle.
    if (Elapsed_Time % 10 == 0 && Elapsed_Time != TimeOfLastToggle)
    {
        LED_toggle(CAR, YELLOW); // Toggle the yellow LED on the car traffic light.
        LED_toggle(PED, YELLOW); // Toggle the yellow LED on the pedestrian traffic light.
        TimeOfLastToggle = Elapsed_Time; // Update the time of the last toggle.
    }
}
