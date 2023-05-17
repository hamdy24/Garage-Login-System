/*
 * KeyPad_Prog.c
 *
 *  Created on: Sep 16, 2022
 *      Author: hamdy
 */


#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorstate.h"

#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

#include "../../MCAL/DIO/DIO_int.h"

#include <util/delay.h>

ES_t Keypad_enuInit(void)
{
	ES_t Local_enuerrorStates = ES_NOK;

	DIO_enuSetPinDirection(COL1_PORT , COL1_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(COL2_PORT , COL2_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(COL3_PORT , COL3_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(COL4_PORT , COL4_PIN , DIO_u8OUTPUT);

	DIO_enuSetPinDirection(ROW1_PORT , ROW1_PIN , DIO_u8INPUT);
	DIO_enuSetPinDirection(ROW2_PORT , ROW2_PIN , DIO_u8INPUT);
	DIO_enuSetPinDirection(ROW3_PORT , ROW3_PIN , DIO_u8INPUT);
	DIO_enuSetPinDirection(ROW4_PORT , ROW4_PIN , DIO_u8INPUT);

	DIO_enuSetPinValue(COL1_PORT , COL1_PIN , DIO_u8HIGH);
	DIO_enuSetPinValue(COL2_PORT , COL2_PIN , DIO_u8HIGH);
	DIO_enuSetPinValue(COL3_PORT , COL3_PIN , DIO_u8HIGH);
	DIO_enuSetPinValue(COL4_PORT , COL4_PIN , DIO_u8HIGH);

	DIO_enuSetPinValue(ROW1_PORT , ROW1_PIN , DIO_u8PULL_UP);
	DIO_enuSetPinValue(ROW2_PORT , ROW2_PIN , DIO_u8PULL_UP);
	DIO_enuSetPinValue(ROW3_PORT , ROW3_PIN , DIO_u8PULL_UP);
	DIO_enuSetPinValue(ROW4_PORT , ROW4_PIN , DIO_u8PULL_UP);

	return Local_enuerrorStates;
}

ES_t Keypad_enuGetPressedKey(u8 * Copy_pu8KeyValue)
{
	ES_t Local_enuerrorStates = ES_NOK;

	u8 Local_Au8ColPorts [COL_NUM] = {COL1_PORT,COL2_PORT,COL3_PORT,COL4_PORT};
	u8 Local_Au8ColPins  [COL_NUM] = {COL1_PIN, COL2_PIN, COL3_PIN, COL4_PIN};

	u8 Local_Au8RowPorts [ROW_NUM] = {ROW1_PORT,ROW2_PORT,ROW3_PORT,ROW4_PORT};
	u8 Local_Au8RowPins  [ROW_NUM] = {ROW1_PIN, ROW2_PIN, ROW3_PIN, ROW4_PIN};

	u8 Local_u8ColIter , Local_u8RowIter , Local_u8PinValue;
	*Copy_pu8KeyValue = KEYPAD_NOT_PRESSED;
	while (*Copy_pu8KeyValue == KEYPAD_NOT_PRESSED)
	{
	for (Local_u8ColIter=0; Local_u8ColIter < COL_NUM ; Local_u8ColIter++ )
	{
		DIO_enuSetPinValue(Local_Au8ColPorts[Local_u8ColIter], Local_Au8ColPins[Local_u8ColIter], DIO_u8LOW);
		for (Local_u8RowIter=0; Local_u8RowIter < ROW_NUM ; Local_u8RowIter++)
		{
			DIO_enuGetPinValue(Local_Au8RowPorts[Local_u8RowIter], Local_Au8RowPins[Local_u8RowIter], &Local_u8PinValue);
			if (! Local_u8PinValue)
			{
				_delay_ms(10);
				DIO_enuGetPinValue(Local_Au8RowPorts[Local_u8RowIter], Local_Au8RowPins[Local_u8RowIter], &Local_u8PinValue);
				if (! Local_u8PinValue)
				{
					while (! Local_u8PinValue)
						DIO_enuGetPinValue(Local_Au8RowPorts[Local_u8RowIter], Local_Au8RowPins[Local_u8RowIter], &Local_u8PinValue);

					u8 Local_Au8Values[ROW_NUM][COL_NUM] = KEYPAD_CONFIG_VALUES;
					*Copy_pu8KeyValue = Local_Au8Values[Local_u8RowIter][Local_u8ColIter];
					return ES_OK;
				}
			}
		}
		DIO_enuSetPinValue(Local_Au8ColPorts[Local_u8ColIter], Local_Au8ColPins[Local_u8ColIter], DIO_u8HIGH);
	}
	}
	return Local_enuerrorStates;
}
