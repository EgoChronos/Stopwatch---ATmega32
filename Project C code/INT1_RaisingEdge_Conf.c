/*
 * INT1_RaisingEdge_Conf.c
 *
 *  Created on: 13 May 2024
 *      Author: ahmed
 */
#include <avr/io.h>

//Configure INTO - PullDOWN resistor - Raising Edge
void INT1_RaisingEdge_Conf(void)
{
	//Configure the INT1/PD3 as input
	DDRD &= ~(1<<PD3);
	//Setup the INT1 with raising edge
	MCUCR |= (1<<ISC10);
	MCUCR &=~(1<<ISC11);
	//enable the general INT1
	GICR |= (1<<INT1);
}
