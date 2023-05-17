/*
 * Handlers.c
 *
 *  Created on: May 14, 2023
 *      Author: Hamdy
 */

#include "../LIBRARIES/stdTypes.h"
#include "../LIBRARIES/errorstate.h"

#include "../MCAL/DIO/DIO_int.h"

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KEYPAD/KEYPAD_interface.h"

#include "Handlers_config.h"

#include <util/delay.h>



ES_t  LoginSystem_enuGetDataFromUserByKeypad( u8 *Copy_Au8Password)
	{
		ES_t Local_enuErrorState = ES_NOK;
		u8 Local_u8PressedKey;
		u8 Local_u8Iterator;

		LCD_enuJumpCursorTo(2,0);

		for (Local_u8Iterator=0; Local_u8Iterator < 4; Local_u8Iterator++)
		{
			Keypad_enuGetPressedKey(&Local_u8PressedKey);
			LCD_enuSendData(Local_u8PressedKey);
			_delay_ms(100);
			LCD_enuJumpCursorTo(2,0+Local_u8Iterator);
			LCD_enuSendData('*');
			Copy_Au8Password[Local_u8Iterator] = Local_u8PressedKey;

		}
		Copy_Au8Password[Local_u8Iterator] ='\0';
		Local_enuErrorState = ES_OK;
		return Local_enuErrorState;
	}

	u8 LoginSystem_u8Strcmp (char *Copy_Au8Sring1, char *Copy_Au8Sring2)
	{
		u8 Local_u8Iterator=0;
		while(Copy_Au8Sring1[Local_u8Iterator]==Copy_Au8Sring2[Local_u8Iterator])
		{
			if (Copy_Au8Sring1[Local_u8Iterator]=='\0' || Copy_Au8Sring2[Local_u8Iterator]=='\0')
				break;
			Local_u8Iterator++;
		}

		if (Copy_Au8Sring1[Local_u8Iterator]=='\0' && Copy_Au8Sring2[Local_u8Iterator]=='\0')
			return 1;
		else
			return 0;
	}



