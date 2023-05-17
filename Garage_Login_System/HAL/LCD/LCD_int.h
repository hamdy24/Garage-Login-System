/*
 * LCD_int.h
 *
 *  Created on: Oct 13, 2021
 *      Author: hamdy
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuSendData(u8 Copy_u8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);

ES_t LCD_enuSendString(const char * Copy_pcString);

ES_t LCD_enuJumpCursorTo( u8 Copy_u8StartX_Position , u8 Copy_u8StartY_Position);

ES_t LCD_enuClearDisplay(void);

ES_t LCD_enuDisplayIntNum(s32 Copy_s32IntNumber);

ES_t LCD_enuDisplayCustomArrCharachter(u8 * Copy_u8pAu8CharHEXA , u8 Copy_u8NumOfPattern , u8 Copy_u8InputDirection);
// ^^ (arr , 3 , RIGHT_INPUT)
ES_t LCD_enuDisplayCustomSingleCharachter(u8 * Copy_u8pAu8CharHEXA ,u8 Copy_u8PatternPosition,u8 Copy_u8DisplayPosition );

//ES_t LCD_enuShiftDisplay(u8 Copy_u8StartX_Position,u8 Copy_u8StartY_Position, u8 Copy_u8Num_ofShifts)

ES_t LCD_enuDisplayFloatNum(f32 Copy_f32FloatNumber);

void LCD_vidSavePattern(u8 *Copy_u8pAu8CharHEXA,u8 Copy_u8PatternPosition);

void LCD_vidPrintPattern(u8 Copy_u8PatternNum,u8 Copy_u8PositionX,u8 Copy_u8PositionY);


/******* interfacing input options *******/
#define LEFT_INPUT		0x04
#define RIGHT_INPUT 	0x06

#endif /* LCD_INT_H_ */
