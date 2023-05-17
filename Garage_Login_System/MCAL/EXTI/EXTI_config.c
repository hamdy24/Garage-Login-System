/*
 * EXTI_config.c
 *
 *  Created on: Oct 30, 2021
 *      Author: hamdy
 */
#include "../../LIBRARIES/errorstate.h"
#include "../../LIBRARIES/stdTypes.h"

#include "EXTI_config.h"
#include "EXTI_priv.h"

/******* Interrupts Configuration *************/

EXTI_T EXTI_enuAstrEXTI_CONFIG[INTERRUPT_NUM] =
{
		{ENABELED  , ANY_LOGICAL},		//INT0
		{DISABELED , DISABELED},	//INT1
		{DISABELED , DISABELED}		//INT2
};
