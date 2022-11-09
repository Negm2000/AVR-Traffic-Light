

#include "Traffic_Light/Traffic_Light.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/INT/GIE/GIE_Interface.h"
#include "../MCAL/TMR/TMR_Interface.h"
#include "../MCAL/INT/EXTI/EXTI_Interface.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/Bit_Math.h"
#include "../ECUAL/LED/Led.h"
#include "app.h"

#if DEBUG_MODE == 1

#define DIO 0
#define LED 1
#define EXTI 2
#define TMR 3
#define TRAFFIC 4

#define TEST_MODULE TRAFFIC

void led_tog(void){
    LED_toggle(PORTB, PIN0);
}

int main(void)
{
//----------------
#if TEST_MODULE == DIO
//----------------
    DIO_pinMode(PORTA, PIN0, OUT); // PORTA, PIN0, OUT
    DIO_pinMode(PORTD, PIN2, PU);  // PORT D, PIN 2, (INPUT+PULL UP)
    DIO_portMode(PORTB, OUT);      // PORTB, OUT
    DIO_portMode(PORTC, IN);       // PORTC, IN

    while (1)
    {
        if (DIO_pinRead(PORTD, PIN2) == 0)
            DIO_pinWrite(PORTA, PIN0, HIGH);
        else
            DIO_pinWrite(PORTA, PIN0, LOW);

        uint8_t val = DIO_portRead(PORTC);
        DIO_portWrite(PORTB, val);
    }
#endif

//----------------
#if TEST_MODULE == LED
//----------------
    LED_init(PORTA, PIN0);
    while (1)

    {
    uint8_t val = DIO_portRead(PORTC);
    if (val == 1)
        LED_on(PORTA, PIN0);
    else if (val == 0)
        LED_off(PORTA, PIN0);
    else if (val == 2)
        LED_toggle(PORTA, PIN0);
    }

#endif
    

//----------------
#if TEST_MODULE == EXTI
//----------------

    DIO_pinMode(PORTB, PIN0, OUT); // PORTA, PIN0, OUT
    EXTI0_voidInit();
    EXTI0_setCallBack(led_tog);
    GIE_ENABLE();
    while (1); // There is no code here that can trigger the LED yet the press of the button will toggle the LED.
#endif

//----------------
#if TEST_MODULE == TMR
    //----------------

    DIO_pinMode(PORTB, PIN0, OUT);
    DIO_pinMode(PORTD, PIN2, PU);
    TMR0_init();
    TMR0_setOvfCallBack(led_tog);
    TMR0_setInterval_ms(5000);
    GIE_ENABLE();
    while (1)
    {
        if (DIO_pinRead(PORTD, PIN2) == 0)
            TMR0_reset(); // Reset the timer to start counting from 0 again.
    }

#endif

//----------------
#if TEST_MODULE == TRAFFIC
    //----------------
    DIO_pinMode(PORTD, PIN2, PU);
    TL_init();
    TL_setStateCar(RED);
    TL_setStatePed(GREEN);

    while (1)
    {
        if (DIO_pinRead(PORTD, PIN2) == 0)
            TL_update();
    }

#endif
}

#endif