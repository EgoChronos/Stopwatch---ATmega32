/*
 * INT0_FallingEdge_Conf.c
 *
 *  Created on: 13 May 2024
 *      Author: ahmed
 */
#include <avr/io.h>
#include <avr/interrupt.h>
//Configure INT0 - PullUP resistor - Falling Edge
void INT0_FallingEdge_Conf(void)
{
	//Configure the INT0/PD2 as input
	DDRD &= ~(1<<PD2);
	//Setup the INT0 with falling edge
	MCUCR |= (1<<ISC01);
	MCUCR &=~(1<<ISC00);
	//enable the general INT0
	GICR |= (1<<INT0);
}
