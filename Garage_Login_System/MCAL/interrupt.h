/*
 * interrupt.h
 *
 *  Created on: Nov 15, 2021
 *      Author: hamdy
 */

#ifndef MCAL_INTERRUPT_H_
#define MCAL_INTERRUPT_H_

#define ISR(vect_num) 		void vect_num (void)__attribute__((signal));\
							void vect_num (void)
#ifndef VECT_INT0
#define VECT_INT0			__vector_1
#endif
#define VECT_INT1			__vector_2
#define VECT_INT2			__vector_3

#define VECT_TIMER2_COM		__vector_4
#define VECT_TIMER2_OVF		__vector_5

#define VECT_TIMER1_CAPT	__vector_6
#define VECT_TIMER1_COMA	__vector_7
#define VECT_TIMER1_COMB	__vector_8
#define VECT_TIMER1_OVF		__vector_9

#ifndef VECT_TIMER0_OVF
#define VECT_TIMER0_COM		__vector_10
#define VECT_TIMER0_OVF		__vector_11
#endif

#define VECT_ADC			__vector_16

#define VECT_UART			__vector_13


#endif /* MCAL_INTERRUPT_H_ */
