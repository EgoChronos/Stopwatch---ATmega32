/*
 * INIT2_FallingEdge_Conf.c
 *
 *  Created on: 13 May 2024
 *      Author: ahmed
 */
#include <avr/io.h>

//Configure INT2 - PullUP resistor - Falling Edge
void INIT2_FallingEdge_Conf(void)
{
	//Configure the INT2/PB2 as input
	DDRB &= ~(1<<PB2);
	//Setup the INT2 with falling edge
	MCUCSR &= ~(1<<ISC2);
	//enable the general INT2
	GICR |= (1<<INT2);

}
