#include "app.h"
#if DEBUG_MODE == 0


int main(void)
{
    APP_start(); // Initialize the application
    while (1) {
        if (CarTrafficLightState == YELLOW || CarTrafficLightState == YELLOW2) {
            TL_blinkYellow(); // Blink the yellow lights
        }
    }
}

#endif