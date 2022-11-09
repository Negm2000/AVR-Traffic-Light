#include "DIO.h"
#include "../../LIB/STD_Types.h"


void DIO_pinMode (uint8_t reg, uint8_t pin, uint8_t direction) // Set pin direction
{
    if (direction == OUT) // Output Mode
    {
        switch(reg)
        { // Set pin direction --> Output based on the port
            case PORTA: setPin(_ddra, pin); break;
            case PORTB: setPin(_ddrb, pin); break;
            case PORTC: setPin(_ddrc, pin); break;
            case PORTD: setPin(_ddrd, pin); break;
            default: break;
        }
    }
    else if (direction == IN) // Input Mode
    {
        switch(reg)
        {// Set pin direction --> Input based on the port
            case PORTA: clrPin(_ddra, pin); break;
            case PORTB: clrPin(_ddrb, pin); break;
            case PORTC: clrPin(_ddrc, pin); break;
            case PORTD: clrPin(_ddrd, pin); break;
            default: break;
        }
    }

    else if (direction == PU) // Input + Pull Up
    {// Set pin direction --> Input + Pull Up based on the port
        switch(reg)
        {
            case PORTA: clrPin(_ddra, pin); setPin(_porta,pin) ; break;
            case PORTB: clrPin(_ddrb, pin);  setPin(_portb,pin) ; break;
            case PORTC: clrPin(_ddrc, pin);  setPin(_portc,pin) ; break;
            case PORTD: clrPin(_ddrd, pin);  setPin(_portd,pin) ; break;
            default: break;
        }
    }

    else
        return; // Invalid direction do nothing
}

void DIO_pinWrite (uint8_t reg, uint8_t pin, uint8_t value) // Set pin value
{
    if (value == HIGH)
    {
        switch(reg)
        {// Set pin value --> High based on the port
            case PORTA: setPin(_porta, pin); break;
            case PORTB: setPin(_portb, pin); break;
            case PORTC: setPin(_portc, pin); break;
            case PORTD: setPin(_portd, pin); break;
            default: break;
        }
    }
    else if (value == LOW)
    {
        switch(reg)
        {// Set pin value --> Low based on the port
            case PORTA: clrPin(_porta, pin); break;
            case PORTB: clrPin(_portb, pin); break;
            case PORTC: clrPin(_portc, pin); break;
            case PORTD: clrPin(_portd, pin); break;
            default: break;
        }
    }
    else
        return;
}

uint8_t DIO_pinRead (uint8_t reg, uint8_t pin) // Get pin status
{
    switch(reg)
    {// Get pin status based on the port
        case PORTA: return getPin(_pina, pin);
        case PORTB: return getPin(_pinb, pin);
        case PORTC: return getPin(_pinc, pin);
        case PORTD: return getPin(_pind, pin);
        default: return -1; // Invalid port
    }
}

void DIO_pinToggle (uint8_t reg, uint8_t pin) // Toggle pin value
{
    switch(reg)
    {// Toggle pin value based on the port
        case PORTA: togPin(_porta, pin); break;
        case PORTB: togPin(_portb, pin); break;
        case PORTC: togPin(_portc, pin); break;
        case PORTD: togPin(_portd, pin); break;
        default: break;
    }
}

void DIO_portMode (uint8_t reg, uint8_t direction) // Set port direction
{
    if (direction == OUT)
    {
        switch(reg)
        { // Set port direction --> Output 
            case PORTA: _ddra = 255; break;
            case PORTB: _ddrb = 255; break;
            case PORTC: _ddrc = 255; break;
            case PORTD: _ddrd = 255; break;
            default: break;
        }
    }
    else if (direction == IN)
    {
        switch(reg)
        {// Set port direction --> Input
            case PORTA: _ddra = 0; break;
            case PORTB: _ddrb = 0; break;
            case PORTC: _ddrc = 0; break;
            case PORTD: _ddrd = 0; break;
            default: break;
        }
    }

    else if (direction == PU)
    {
        switch(reg)
        {// Set port direction --> Input + Pull Up
            case PORTA: _ddra = 0; _porta = 255; break;
            case PORTB: _ddrb = 0; _portb = 255; break;
            case PORTC: _ddrc = 0; _portc = 255; break;
            case PORTD: _ddrd = 0; _portd = 255; break;
            default: break;
        }
    }
    else
        return; // Error
}

void DIO_portWrite (uint8_t reg, uint8_t value) // Set PORT value
{
    switch(reg)
    {// Set port = value
        case PORTA: _porta = value; break;
        case PORTB: _portb = value; break;
        case PORTC: _portc = value; break;
        case PORTD: _portd = value; break;
        default: break;
    }
}
uint8_t DIO_portRead (uint8_t reg) // Get port status
{
    switch(reg)
    { // Return port status
        case PORTA: return _pina;
        case PORTB: return _pinb;
        case PORTC: return _pinc;
        case PORTD: return _pind;
        default: return -1; // Invalid port
    }
}