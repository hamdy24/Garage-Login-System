#include "DIO_config.h"
#include "DIO_priv.h"

#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorstate.h"


ES_t DIO_enuInit(void)
{
	/* not used in real projects but implemented here as a practice of driver architecture  */
	ES_t Local_enuErrorStatus = ES_NOK;

	DDRA = CONC(DIO_u8PA7_DIR , DIO_u8PA6_DIR , DIO_u8PA5_DIR , DIO_u8PA4_DIR , DIO_u8PA3_DIR , DIO_u8PA2_DIR , DIO_u8PA1_DIR , DIO_u8PA0_DIR);
	PORTA = CONC(DIO_u8PA7_VALUE , DIO_u8PA6_VALUE , DIO_u8PA5_VALUE , DIO_u8PA4_VALUE , DIO_u8PA3_VALUE , DIO_u8PA2_VALUE , DIO_u8PA1_VALUE , DIO_u8PA0_VALUE);

	DDRB = CONC(DIO_u8PB7_DIR , DIO_u8PB6_DIR , DIO_u8PB5_DIR , DIO_u8PB4_DIR , DIO_u8PB3_DIR , DIO_u8PB2_DIR , DIO_u8PB1_DIR , DIO_u8PB0_DIR);
	PORTB = CONC(DIO_u8PB7_VALUE , DIO_u8PB6_VALUE , DIO_u8PB5_VALUE , DIO_u8PB4_VALUE , DIO_u8PB3_VALUE , DIO_u8PB2_VALUE , DIO_u8PB1_VALUE , DIO_u8PB0_VALUE);

	DDRC = CONC(DIO_u8PC7_DIR , DIO_u8PC6_DIR , DIO_u8PC5_DIR , DIO_u8PC4_DIR , DIO_u8PC3_DIR , DIO_u8PC2_DIR , DIO_u8PC1_DIR , DIO_u8PC0_DIR);
	PORTC = CONC(DIO_u8PC7_VALUE , DIO_u8PC6_VALUE , DIO_u8PC5_VALUE , DIO_u8PC4_VALUE , DIO_u8PC3_VALUE , DIO_u8PC2_VALUE , DIO_u8PC1_VALUE , DIO_u8PC0_VALUE);

	DDRD = CONC(DIO_u8PD7_DIR , DIO_u8PD6_DIR , DIO_u8PD5_DIR , DIO_u8PD4_DIR , DIO_u8PD3_DIR , DIO_u8PD2_DIR , DIO_u8PD1_DIR , DIO_u8PD0_DIR);
	PORTD = CONC(DIO_u8PD7_VALUE , DIO_u8PD6_VALUE , DIO_u8PD5_VALUE , DIO_u8PD4_VALUE , DIO_u8PD3_VALUE , DIO_u8PD2_VALUE , DIO_u8PD1_VALUE , DIO_u8PD0_VALUE);

	return Local_enuErrorStatus;
}

ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PortDirection)
{
	ES_t Local_enuErrorStatus = ES_NOK;
	//if valid port AND pin AND value to be handeled...then proceed
  if(Copy_u8PortID <= DIO_u8PORTD
	  && Copy_u8PinID <= DIO_u8PIN7
	  && (Copy_u8PortDirection==DIO_u8OUTPUT||Copy_u8PortDirection==DIO_u8INPUT))
  {
	switch(Copy_u8PortID)
	{
	case DIO_u8PORTA:
		//	suppose pinId is 5, so->> DDRA &= 	~(1<<5) == ~(0001 0000) == 1110 1111
		// so exceprition be like DDRA &= 1110 1111 *********so only bit 5 is masked by AND with zero******
		DDRA &= ~(DIO_u8MASK_BIT <<Copy_u8PinID);
		DDRA |=  (Copy_u8PortDirection <<Copy_u8PinID);

		break;
	case DIO_u8PORTB:
		DDRB &= ~(DIO_u8MASK_BIT <<Copy_u8PinID);
		DDRB |=  (Copy_u8PortDirection <<Copy_u8PinID);

		break;
	case DIO_u8PORTC:
		DDRC &= ~(DIO_u8MASK_BIT <<Copy_u8PinID);
		DDRC |=  (Copy_u8PortDirection <<Copy_u8PinID);
		break;
	case DIO_u8PORTD:
		DDRD &= ~(DIO_u8MASK_BIT <<Copy_u8PinID);
		DDRD |=  (Copy_u8PortDirection <<Copy_u8PinID);
		break;
	}

  }
  else
  {
	 Local_enuErrorStatus = ES_OUT_OF_RANGE;
  }

	return Local_enuErrorStatus;
}

ES_t DIO_enuTogPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
	ES_t Local_enuErrorStatus = ES_NOK;

	if(Copy_u8PortID <= DIO_u8PORTD
				&& Copy_u8PinID <= DIO_u8PIN7)
			{
			switch(Copy_u8PortID)
			{
			case DIO_u8PORTA:
				PORTA ^= (DIO_u8MASK_BIT <<Copy_u8PinID);


				break;
			case DIO_u8PORTB:
				PORTB ^= (DIO_u8MASK_BIT <<Copy_u8PinID);


				break;
			case DIO_u8PORTC:
				PORTC ^= (DIO_u8MASK_BIT <<Copy_u8PinID);

				break;
			case DIO_u8PORTD:
				PORTD ^= (DIO_u8MASK_BIT <<Copy_u8PinID);

				break;
			}
		}
			else
			{
				 Local_enuErrorStatus = ES_OUT_OF_RANGE;

			}

	return Local_enuErrorStatus;

}

ES_t DIO_enuSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinValue)
{
	ES_t Local_enuErrorStatus = ES_NOK;

	if(Copy_u8PortID <= DIO_u8PORTD
			&& Copy_u8PinID <= DIO_u8PIN7
			&& (Copy_u8PinValue <= DIO_u8HIGH ||Copy_u8PinValue <= DIO_u8PULL_UP ))
		{
		switch(Copy_u8PortID)
		{
		case DIO_u8PORTA:

			PORTA &= ~(DIO_u8MASK_BIT <<Copy_u8PinID);

			PORTA |=  (Copy_u8PinValue <<Copy_u8PinID);

			break;
		case DIO_u8PORTB:
			PORTB &= ~(DIO_u8MASK_BIT <<Copy_u8PinID);

			PORTB |=  (Copy_u8PinValue <<Copy_u8PinID);

			break;
		case DIO_u8PORTC:
			PORTC &= ~(DIO_u8MASK_BIT <<Copy_u8PinID);

			PORTC |=  (Copy_u8PinValue <<Copy_u8PinID);
			break;
		case DIO_u8PORTD:
			PORTD &= ~(DIO_u8MASK_BIT <<Copy_u8PinID);

			PORTD |=  (Copy_u8PinValue <<Copy_u8PinID);
			break;
		}
		}
		else
		{
			 Local_enuErrorStatus = ES_OUT_OF_RANGE;

		}

	return Local_enuErrorStatus;

}

ES_t DIO_enuGetPinValue (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 * Copy_pu8PinValue)
{
	ES_t Local_enuErrorStatus = ES_NOK;
	if( Copy_pu8PinValue != NULL)
	{
		 if (Copy_u8PortID <= DIO_u8PORTD
				&& Copy_u8PinID <= DIO_u8PIN7)
		 {
				switch(Copy_u8PortID)
				{
				case DIO_u8PORTA:
					*Copy_pu8PinValue = ( (PINA >>Copy_u8PinID) & DIO_u8MASK_BIT);

					break;
				case DIO_u8PORTB:
					*Copy_pu8PinValue = ( (PINB >>Copy_u8PinID)&DIO_u8MASK_BIT);

					break;
				case DIO_u8PORTC:
					*Copy_pu8PinValue = ( (PINC >>Copy_u8PinID)&DIO_u8MASK_BIT);
					break;
				case DIO_u8PORTD:
					*Copy_pu8PinValue = ( (PIND >>Copy_u8PinID)&DIO_u8MASK_BIT);
					break;
				}
				Local_enuErrorStatus = ES_OUT_OF_RANGE;
		}
	}

		else
		{
	    	 Local_enuErrorStatus = ES_POINTER_TO_VOID;

		}


	return Local_enuErrorStatus;

}

ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8PortDirection)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_u8PortID <= DIO_u8PORTD
		&& (Copy_u8PortDirection==DIO_u8OUTPUT||Copy_u8PortDirection==DIO_u8INPUT)){
		switch(Copy_u8PortID)
		{
		case DIO_u8PORTA :
			if(Copy_u8PortDirection==DIO_u8OUTPUT){
				DDRA = DIO_u8PORT_OUTPUT;
			}
			else{
				DDRA = DIO_u8PORT_INPUT;
			}
			break;
		case DIO_u8PORTB :
			if(Copy_u8PortDirection==DIO_u8OUTPUT){
				DDRB = DIO_u8PORT_OUTPUT;
			}
			else{
				DDRB = DIO_u8PORT_INPUT;
			}
			break;
		case DIO_u8PORTC :
			if(Copy_u8PortDirection==DIO_u8OUTPUT){
				DDRC = DIO_u8PORT_OUTPUT;
			}
			else{
				DDRC = DIO_u8PORT_INPUT;
			}
			break;
		case DIO_u8PORTD :
			if(Copy_u8PortDirection==DIO_u8OUTPUT){
				DDRD = DIO_u8PORT_OUTPUT;
			}
			else{
				DDRD = DIO_u8PORT_INPUT;
			}
			break;
		}
	}
	else{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_u8ErrorState;
}

ES_t DIO_enuSetPortValue    (u8 Copy_u8PortID , u8 Copy_u8PortValue)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_u8PortID <= DIO_u8PORTD
		&& (Copy_u8PortValue <= DIO_u8PORT_HIGH && Copy_u8PortValue >= DIO_u8PORT_LOW)){
		switch(Copy_u8PortID)
				{
				case DIO_u8PORTA :
					PORTA = Copy_u8PortValue;
					break;
				case DIO_u8PORTB :
					PORTB = Copy_u8PortValue;
					break;
				case DIO_u8PORTC :
					PORTC = Copy_u8PortValue;
					break;
				case DIO_u8PORTD :
					PORTD = Copy_u8PortValue;
					break;
				}
	}
	else{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_u8ErrorState;
}

ES_t DIO_enuGetPortValue(u8 Copy_u8PortID , u8 * Copy_u8PortValue)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_u8PortValue != NULL){
		if(Copy_u8PortID <= DIO_u8PORTD){
			switch(Copy_u8PortID)
			{
			case DIO_u8PORTA :
				*Copy_u8PortValue = PORTA;
				break;
			case DIO_u8PORTB :
				*Copy_u8PortValue = PORTB;
				break;
			case DIO_u8PORTC :
				*Copy_u8PortValue = PORTC;
				break;
			case DIO_u8PORTD :
				*Copy_u8PortValue = PORTD;
				break;
			}
		}
		else{
			Local_u8ErrorState = ES_OUT_OF_RANGE;
		  }
	}
	else{
		Local_u8ErrorState = ES_POINTER_TO_VOID;
	}
	return Local_u8ErrorState;
}
