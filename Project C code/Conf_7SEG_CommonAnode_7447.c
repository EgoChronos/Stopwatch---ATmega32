/*
 * Conf_7SEG_CommonAnode_7447.c
 *
 *  Created on: 13 May 2024
 *      Author: ahmed
 */
#include <avr/io.h>

void Conf_7SEG_CommonAnode_7447(void)
{
	//Connect 7447 decoder to the first 4-pins in PORTC
	//Set the DDR of first 4-pins to be OUTPUT
	DDRC |= 0x0F;
	//Clear PORT of the 4 pins to send a zero to the decoder initially
	PORTC &= 0xF0;

	//First 6-pins in PORTA control which 7SEG enabled and disabled
	//set the DDR of the 6-pins to be OUTPUT
	DDRA |= 0x3F;
	//SET all 6-pins to make all 7SEG ENABLED.
	PORTA |= 0x3F;

}
