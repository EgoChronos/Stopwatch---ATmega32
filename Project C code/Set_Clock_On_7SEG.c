/*
 * Set_Clock_On_7SEG.C
 *
 *  Created on: 13 May 2024
 *      Author: ahmed
 */
#include <avr/io.h>
#include <avr/delay.h>

void Set_Clock_On_7SEG(const unsigned char seconds, const unsigned char minutes, const unsigned char hours)
{

	//disable all the 7Segments
	PORTA = (PORTA & 0xC0)|( 0x00);
	//send the first cell of the seconds
	PORTC = (PORTC & 0xF0)|((seconds%10));
	//enable the 7SEG of the first cell of the seconds
	PORTA = (PORTA & 0xC0)|( 0x20 & (0x3F));
	_delay_ms(2);
	//disable all the 7Segments
	PORTA = (PORTA & 0xC0)|( 0x00);
	//send the first cell of the seconds
	PORTC = (PORTC & 0xF0)|(seconds/10);
	//enable the 7SEG of the second cell of seconds
	PORTA = (PORTA & 0xC0)|( 0x10 & (0x3F));
	_delay_ms(2);

	//disable all the 7Segments
	PORTA = (PORTA & 0xC0)|( 0x00);
	//enable the 7SEG of the first cell of the minutes
	PORTA = (PORTA & 0xC0)|( 0x08 & (0x3F));
	//send the first cell of the minutes
	PORTC = (PORTC & 0xF0)|(minutes%10);
	_delay_ms(2);
	//disable all the 7Segments
	PORTA = (PORTA & 0xC0)|( 0x00);
	//enable the second cell of the minutes
	PORTA = (PORTA & 0xC0)|( 0x04 & (0x3F));
	//send the second cell of the minutes
	PORTC = (PORTC & 0xF0)|((minutes/10) & (0x0F));
	_delay_ms(2);

	//disable all the 7Segments
	PORTA = (PORTA & 0xC0)|( 0x00);
	//enable the 7SEG of first cell of hours
	PORTA = (PORTA & 0xC0)|( 0x02 & (0x3F));
	//send the first cell of the hours
	PORTC = (PORTC & 0xF0)|((hours%10) & (0x0F));
	_delay_ms(2);
	//disable all the 7Segments
	PORTA = (PORTA & 0xC0)|( 0x00);
	//enable the 7SEG of first cell of hours
	PORTA = (PORTA & 0xC0)|( 0x01 & (0x3F));
	//send the first cell of the hours
	PORTC = (PORTC & 0xF0)|((hours/10) & (0x0F));
	_delay_ms(2);
}
