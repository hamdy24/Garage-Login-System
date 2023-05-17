#ifndef _PRIV_H_
#define _PRIV_H_

#define PORTA	*((u8*)0x3B)
#define DDRA	*((u8*)0x3A)
#define PINA	*((volatile u8*)0x39)

#define PORTB	*((u8*)0x38)
#define DDRB	*((u8*)0x37)
#define PINB	*((volatile u8*)0x36)

#define PORTC	*((u8*)0x35)
#define DDRC	*((u8*)0x34)
#define PINC	*((volatile u8*)0x33)

#define PORTD	*((u8*)0x32)
#define DDRD	*((u8*)0x31)
#define PIND	*((volatile u8*)0x30)

#define DIO_u8PORTA 			0
#define DIO_u8PORTB 			1
#define DIO_u8PORTC 			2
#define DIO_u8PORTD 			3

#define DIO_u8PIN0				0
#define DIO_u8PIN1				1
#define DIO_u8PIN2				2
#define DIO_u8PIN3				3
#define DIO_u8PIN4				4
#define DIO_u8PIN5				5
#define DIO_u8PIN6				6
#define DIO_u8PIN7				7

#define DIO_u8INPUT 			0
#define DIO_u8OUTPUT 			1

#define DIO_u8HIGH				1
#define DIO_u8LOW				0

#define DIO_u8PULL_UP			0
#define DIO_u8FLOAT		     	1

#define DIO_u8MASK_BIT			1

#define DIO_u8PORT_HIGH			255
#define DIO_u8PORT_LOW			0
#define DIO_u8PORT_OUTPUT		255
#define DIO_u8PORT_INPUT		0


// this concatinates the macros itself like DIO_u8HIGHDIO_u8LOWDIO_u8LOW
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0) 		 0##b##b7##b6##b5##b4##b3##b2##b1##b0
// but here macros are replaced by their defined values
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)			CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#endif
