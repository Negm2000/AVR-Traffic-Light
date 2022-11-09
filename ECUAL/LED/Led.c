#include "Led.h"
#include "../../MCAL/DIO/dio.h"

void LED_init (uint8_t port, uint8_t pin)  // Initialize LED
{
    DIO_pinMode(port, pin, OUT); // Set pin direction --> Output
}
void LED_on (uint8_t port, uint8_t pin){ // Turn LED on
    DIO_pinWrite(port, pin, HIGH); // Set pin value --> High
}
void LED_off (uint8_t port, uint8_t pin){ // Turn LED off
    DIO_pinWrite(port, pin, LOW); // Set pin value --> Low
}
void LED_toggle (uint8_t port, uint8_t pin){ // Toggle LED
    DIO_pinToggle(port, pin); // Toggle pin value
}



