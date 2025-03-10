/*
 * Project2.c
 *
 *  Created on: 13 May 2024
 *      Author: ahmed
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Conf_7SEG_CommonAnode_7447.h"
#include "StopWatch_clock.h"
#include "Set_Clock_On_7SEG.h"
#include "INT_Conf_fcn.h"

#define INITIAL_VALUE_CLK 0
#define FLAG_UP 1
#define FLAG_DOWN 0

unsigned char g_flag = FLAG_DOWN;
unsigned char g_reset_flag = FLAG_DOWN;
unsigned char seconds = 0;
unsigned char minutes = 0;
unsigned char hours = 0;


ISR(TIMER1_COMPA_vect)
{
	/*this interrupt raise the flag every one second to increment the CLK*/
	g_flag = FLAG_UP;
}

ISR(INT0_vect)
{
	/*this interrupt sets a flag to reset the stop watch when button pressed*/
	g_reset_flag = FLAG_UP;
}

ISR(INT1_vect)
{
	/*this interrupt pauses the stop watch when button pressed*/
	TIMSK &= ~(1<<OCIE1A);
}

ISR(INT2_vect)
{
	/*this interrupt pauses the stop watch when button pressed*/
	TIMSK |= (1<<OCIE1A);
}

int main(void)
{

	//Configure all interrupts
	INT_Conf_fcn();

	//Configure six 7SEG common Anode using Decoder
	Conf_7SEG_CommonAnode_7447();

	while (1)
	{
		//increment the clock over time
		//if interrupt happened - one second passed
		if (g_flag)
		{
			StopWatch_clock(&seconds, &minutes, &hours);
			g_flag = FLAG_DOWN;
		}

		//Set the current clock to the 7SEG
		Set_Clock_On_7SEG(seconds, minutes, hours);

		//checks the rest flag to reset the StopWatch
		if (g_reset_flag)
		{
			PORTC &= 0xF0;
			seconds = 0;
			minutes = 0;
			hours = 0;
			g_reset_flag = FLAG_DOWN;
		}

	}


}
