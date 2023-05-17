/*
 * main.c
 *
 *  Created on: Oct 30, 2021
 *      Author: hamdy
 */
#include "main.h"

volatile u16 milliseconds = 0; // Global variable to count milliseconds

u8 pass=0;
char password[5];
u8 activeTimer = 0;
u8 counter = 0;
u8 entranceFlag =1;
int main()
{
	TIMER0_enuInit();
	LCD_enuInit();
	Keypad_enuInit();
	EXTI_enuInit(EXTI_enuAstrEXTI_CONFIG);

	__asm("sei");// enable global interrupt

	EXTI_enuCallBack((volatile void (*) (void))APP_enuActivation , 0);

	while(1)
	{

	}

return 0;
}

volatile void APP_enuActivation(void){

				DIO_enuSetPinDirection(MOTOR_PORT,MOTOR_PIN,DIO_u8OUTPUT);
		if(entranceFlag){
			entranceFlag=0;
				LCD_enuClearDisplay();
				LCD_enuJumpCursorTo(1,0);
				LCD_enuSendString("Welcome to Garage");
				_delay_ms(1000);
				Enter:
				LCD_enuClearDisplay();
				LCD_enuJumpCursorTo(1,0);
			 	LCD_enuSendString("Enter Password    ");

				LoginSystem_enuGetDataFromUserByKeypad(&password);

				pass = LoginSystem_u8Strcmp(&password,"1234");

				}
				entranceFlag=1;
		}
}

volatile void Timer_enuActivation(void)
{
	milliseconds += 16; // 16 is the final calculation of using timer 0 with prescaler 1024
	if(activeTimer){
		milliseconds = 0; //Reseted to make the timer delay for full 4sec
		DIO_enuSetPinValue(MOTOR_PORT,MOTOR_PIN,DIO_u8HIGH); // turn on motor and will not be off till the 4 sec is completed below
		activeTimer = 0; // reset flag so that we not enter the condition again and reset the timer again
	}

	    if (milliseconds >= 4000  )
	    {
	        DIO_enuSetPinValue(MOTOR_PORT,MOTOR_PIN,DIO_u8LOW); ///stop motor after the 4 sec is completed
	        milliseconds = 0; // Reset milliseconds counter
	        activeTimer = 0;
	    }
}



ISR(VECT_TIMER0_OVF){
	Timer_enuActivation();
}
u8 TIMER0_enuInit(void)
{


	/************* Watch window help **************
	 * FOC0	WGM00 COM01	COM00 WGM01	CS02 CS01 CS00
	 *   0	  0	    0 	  0	   0	 1	  0	   1	TCCR0 = 0x05 = 0000 0101
	 **********************************************/

	TCNT0 = 0; // reset the counter register to 0

	TCCR0 = 0x05; //turn timer on with prescaler 1024

    TIMSK |= (1 << 0); // Enable timer overflow interrupt which is bit number 0 in the register


	return 0;
}


//ISR(VECT_INT0)
//{
//
//	APP_enuActivation();
//
//}
