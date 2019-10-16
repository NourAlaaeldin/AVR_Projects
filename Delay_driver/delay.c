/*
 * delay.c
 *
 *  Created on: Oct 7, 2019
 *      Author: Nour
 */

#include "delay.h"

void
delay_s(uint16 sec)
{
	delay_ms(sec * 1000);
}

void
delay_ms(uint16 msec)
{
	for(uint16 i = LOW;i < msec;i++)
	{
		while(BIT_IS_CLEAR(TIFR_R,OCF1A_B));
		SET_BIT(TIFR_R,OCF1A_B);
	}
}
