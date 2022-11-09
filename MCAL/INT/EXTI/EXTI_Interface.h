#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
#include "EXTI_Register.h"

#define EXTI0_ENABLE()  (GICR |= (1<<6))
#define EXTI0_DISABLE() (GICR &= ~(1<<6))

// ---------------------------------------

void EXTI0_voidInit(void);
void EXTI0_setCallBack(void (*func)(void));

void (*EXTI0_CallBack)(void);


#endif