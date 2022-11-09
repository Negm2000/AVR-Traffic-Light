#ifndef __TRAFFIC_LIGHT_H__
#define __TRAFFIC_LIGHT_H__
#include "../../LIB/STD_Types.h"

typedef enum EN_TrafficLightState_t
{
    GREEN,
    YELLOW,
    RED,
    YELLOW2
} EN_TrafficLightState_t;



EN_TrafficLightState_t CarTrafficLightState;
EN_TrafficLightState_t PedTrafficLightState;


void TL_init(void); // Initialize the traffic lights
void TL_update(void);  // Update the traffic lights
void TL_setStateCar(EN_TrafficLightState_t state); // Set the state of the car traffic light
void TL_setStatePed(EN_TrafficLightState_t state); // Set the state of the pedestrian traffic light
void TL_blinkYellow(void); // Blink the yellow light of the car traffic light


#endif // __TRAFFIC_LIGHT_H__
