/*
 * KEYPAD_config.h
 *
 *  Created on: Nov 12, 2021
 *      Author: hamdy
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_


#define COL_NUM		4
#define ROW_NUM		4

#define KEYPAD_NOT_PRESSED 	0xff

#define KEYPAD_CONFIG_VALUES	{							\
								 {'1' , '2' , '3' , '-' },	\
								 {'4' , '5' , '6' , 'x' },	\
								 {'7' , '8' , '9' , '÷' },	\
								 {'c' , '0' , '=' , '+' }	\
								}


/********** Rows Configuration ***********/
#define ROW1_PORT		DIO_u8PORTC
#define ROW1_PIN		DIO_u8PIN0

#define ROW2_PORT		DIO_u8PORTC
#define ROW2_PIN		DIO_u8PIN1

#define ROW3_PORT		DIO_u8PORTC
#define ROW3_PIN		DIO_u8PIN2

#define ROW4_PORT		DIO_u8PORTC
#define ROW4_PIN		DIO_u8PIN3
/************* Columns Configuration ************/

#define COL1_PORT		DIO_u8PORTC
#define COL1_PIN		DIO_u8PIN4

#define COL2_PORT		DIO_u8PORTC
#define COL2_PIN		DIO_u8PIN5

#define COL3_PORT		DIO_u8PORTC
#define COL3_PIN		DIO_u8PIN6

#define COL4_PORT		DIO_u8PORTC
#define COL4_PIN		DIO_u8PIN7




#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
