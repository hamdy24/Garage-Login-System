/*
 * GIE_prog.c
 *
 *  Created on: Oct 30, 2021
 *      Author: hamdy
 */

#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorstate.h"

#include "GIE_priv.h"

ES_t GIE_enuInit(void)
{
	ES_t Local_ErorrState = ES_NOK ;

	SREG &= ~(1<<7);

	Local_ErorrState = ES_OK;
	return Local_ErorrState;
}
ES_t GIE_enuEnable(void)
{
	ES_t Local_ErorrState = ES_NOK ;

	SREG |= (1<<7);

	Local_ErorrState = ES_OK;
	return Local_ErorrState;
}

ES_t GIE_enuDisable(void)
{
	ES_t Local_ErorrState = ES_NOK ;

	SREG &= ~(1<<7);

	Local_ErorrState = ES_OK;
	return Local_ErorrState;
}

