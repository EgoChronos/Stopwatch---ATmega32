/*
 * Timer1_CTC_Conf.c
 *
 *  Created on: 13 May 2024
 *      Author: ahmed
 */
#include <avr/io.h>
#include <avr/interrupt.h>

void Timer1_CTC_Conf_INT(unsigned short compMatch, unsigned short preScaler)
{
	TCNT1 = 0;
	OCR1A = compMatch;
	TCCR1A |= (1<<FOC1A);
	TCCR1B |= (1<<WGM12);

	TCCR1B &= 0xF8;
	switch (preScaler)
	{
	case 1:
		TCCR1B |= 0x01;
		break;
	case 8:
		TCCR1B |= 0x02;
		break;
	case 64:
		TCCR1B |= 0x03;
		break;
	case 256:
		TCCR1B |= 0x04;
		break;
	case 1024:
		TCCR1B |= 0x05;
		break;
	}

	TIMSK |= (1<<OCIE1A);
}
