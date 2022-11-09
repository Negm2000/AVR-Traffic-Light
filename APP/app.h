#ifndef __APP_H__
#define __APP_H__

#include "Traffic_Light/Traffic_Light.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/INT/GIE/GIE_Interface.h"
#include "../MCAL/TMR/TMR_Interface.h"
#include "../MCAL/INT/EXTI/EXTI_Interface.h"
#include "../ECUAL/LED/Led.h"

#define DEBUG_MODE 0

void APP_start(void);
void APP_pedestrianMode(void);
void APP_enableButtonOnUpdate (void);

#endif // __APP_H__
