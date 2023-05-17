/*
 * KEYPAD_interface.h
 *
 *  Created on: Nov 12, 2021
 *      Author: hamdy
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorstate.h"

ES_t Keypad_enuInit(void);

ES_t Keypad_enuGetPressedKey(u8 * Copy_pu8KeyValue);

#define KEYPAD_NOT_PRESSED	0xff
#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
