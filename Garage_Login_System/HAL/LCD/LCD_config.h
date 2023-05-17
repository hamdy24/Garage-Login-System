/*
 * LCD_config.h
 *
 *  Created on: Oct 13, 2021
 *      Author: hamdy
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_MODE	FOUR_BIT	// FOUR_BIT		or 	EIGHT_BIT


/*********** control pins ***********/

#define RS_PORT		DIO_u8PORTB
#define RS_PIN		DIO_u8PIN1

#define RW_PORT		DIO_u8PORTB
#define RW_PIN		DIO_u8PIN2

#define EN_PORT		DIO_u8PORTB
#define EN_PIN		DIO_u8PIN3

/*********** data pins ***********/


#define D0_PORT		DIO_u8PORTC
#define D0_PIN		DIO_u8PIN0

#define D1_PORT		DIO_u8PORTC
#define D1_PIN		DIO_u8PIN1

#define D2_PORT		DIO_u8PORTC
#define D2_PIN		DIO_u8PIN2

#define D3_PORT		DIO_u8PORTC
#define D3_PIN		DIO_u8PIN3
/* 4-bit pins */
#define D4_PORT		DIO_u8PORTA
#define D4_PIN		DIO_u8PIN4

#define D5_PORT		DIO_u8PORTA
#define D5_PIN		DIO_u8PIN5

#define D6_PORT		DIO_u8PORTA
#define D6_PIN		DIO_u8PIN6

#define D7_PORT		DIO_u8PORTA
#define D7_PIN		DIO_u8PIN7


#endif /* LCD_CONFIG_H_ */
