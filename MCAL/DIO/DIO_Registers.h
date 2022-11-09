#ifndef REGS_H_
#define REGS_H_


// Data Direction Registers (8-bit)
#define _ddra (PORT 0x3A)
#define _ddrb (PORT 0x37)
#define _ddrc (PORT 0x34)
#define _ddrd (PORT 0x31)
// PORTs (8-bit)
#define _porta (PORT 0x3B)
#define _portb (PORT 0x38)
#define _portc (PORT 0x35)
#define _portd (PORT 0x32)
// PORTs (8-bit)
#define _pina (PORT 0x39)
#define _pinb (PORT 0x36)
#define _pinc (PORT 0x33)
#define _pind (PORT 0x30)
//PINS
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
enum Registers{PORTA,PORTB,PORTC,PORTD};
#endif