/*
 * INT_Conf_fcn.c
 *
 *  Created on: 14 May 2024
 *      Author: ahmed
 */
#include <avr/io.h>
#include "Timer1_CTC_Conf.h"
#include "INT0_FallingEdge_Conf.h"
#include "INT1_RaisingEdge_Conf.h"
#include "INIT2_FallingEdge_Conf.h"

#define TIMER1_COMP_MATCH 15625
#define CLK_PRESCALER 64

//Configure all interrupts
void INT_Conf_fcn(void)
{
	//Enable general interrupts
	SREG |= (1<<7);
	//Configure Timer1
	Timer1_CTC_Conf_INT(TIMER1_COMP_MATCH,CLK_PRESCALER);

	//INIT0_Conf
	INT0_FallingEdge_Conf();

	//INIT1_Conf
	INT1_RaisingEdge_Conf();

	//INIT2_Conf
	INIT2_FallingEdge_Conf();
}

