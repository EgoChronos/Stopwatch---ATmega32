/*
 * StopWatch_clock.c
 *
 *  Created on: 13 May 2024
 *      Author: ahmed
 */

#define Max_CLK_DEG 60
void StopWatch_clock(unsigned char* const seconds, unsigned char* const minutes, unsigned char* const hours)
{

		//increase seconds by 1:
		++*seconds;
		if (*seconds == Max_CLK_DEG)
		{
			*seconds = 0;
			++*minutes;
			if (*minutes == Max_CLK_DEG)
			{
				*minutes = 0;
				++*hours;
			}
		}
}

