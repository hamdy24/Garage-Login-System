/*
 * main.h
 *
 *  Created on: May 15, 2023
 *      Author: Hamdy
 */

#ifndef APP_MAIN_H_
#define APP_MAIN_H_

#include "../LIBRARIES/stdTypes.h"
#include "../LIBRARIES/errorstate.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXTI/EXTI_int.h"

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"

#include "../Services/Handlers_interface.h"
#include "../MCAL/interrupt.h"
#include "../MCAL/AVR_REG.H"

#include <util/delay.h>
extern EXTI_T EXTI_enuAstrEXTI_CONFIG[3];
#define  ApplicationRunFlagPort  DIO_u8PORTD
#define  ApplicationRunFlagPin   DIO_u8PIN5


#define MOTOR_PORT		DIO_u8PORTA
#define MOTOR_PIN		DIO_u8PIN2

u8 TIMER0_enuInit(void);
volatile void APP_enuActivation(void);
volatile void Timer_enuActivation(void);

#endif /* APP_MAIN_H_ */
