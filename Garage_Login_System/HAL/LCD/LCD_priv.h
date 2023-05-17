/*
 * LCD_priv.h
 *
 *  Created on: Oct 13, 2021
 *      Author: hamdy
 */

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

static ES_t LCD_enuWriteAndLatch(u8 Copy_u8Data);

#define FOUR_BIT						44
#define EIGHT_BIT						88

#define FUNC_SET_FOUR_BIT				0x28
#define FUNC_SET_EIGHT_BIT				0x38

#define MASK_BIT						1

#define SHIFT_PIN_7						7
#define SHIFT_PIN_6						6
#define SHIFT_PIN_5						5
#define SHIFT_PIN_4						4
#define SHIFT_PIN_3						3
#define SHIFT_PIN_2						2
#define SHIFT_PIN_1						1
#define SHIFT_PIN_0						0

#define RIGHT_INPUT		0x06
#define LEFT_INPUT		0x04
/****************	LCD COMMANDS	*******************/
#define DIS_ON__CURSOR_ON_BLINKING		0x0f
#define CLEAR_DISPLAY					0x01
#define ENTRY_MOOD						0x06
#define GO_HOME							0x02
#define ARABIC_CURSOR_MODE				0x04
#define ENGLISH_CURSOR_MODE				0x06
#define SHIFT_DISPLAY_LIFT				0x07
#define SHIFT_DISPLAY_RIGHT				0x05
#define ACTIVATE_2ND_LINE				0x3C
#define DISPLAY_ON_CURSOR_BLINKING		0x0E
#define DISPLAY_ON_CURSOR_OFF			0x0C
#define DISPLAY_OFF_CURSOR_OFF			0x08
#define START_OF_LINE1					0x80//can be increased in order to place on onther position at the same line
#define START_OF_LINE2					0xC0//same option
#define START_OF_CGRAM					0x40//same option
//38	2 lines and 5×7 matrix

#define PATTERN_SIZE					8
#endif /* LCD_PRIV_H_ */
