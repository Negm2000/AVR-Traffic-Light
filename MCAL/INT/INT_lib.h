#ifndef __INT_LIB_H__
#define __INT_LIB_H__

//*****************************************************************************
// ISR declaration macro
//*****************************************************************************
#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal, used));\
                      void INT_VECT (void) 

// Vector names
#define EXTI0_vect  __vector_1
#define EXTI1_vect  __vector_2
#define EXTI2_vect  __vector_3 
#define TMR0_OVF __vector_11

#endif // __INT_LIB_H__
