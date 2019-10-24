/*
 * Test.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Nour
 */

#include "External_Interrupt.h"

void
App(void)
{
	TOGGLE_BIT(PORTC_R,PC0_B);
}

int
main(void)
{
	SET_BIT(SREG_R,I_B);
	SET_BIT(DDRC_R,PC0_B);
	SET_BIT(PORTC_R,PC0_B);

	Interrupt_ConfigType Interrupt_Config = {interrupt0,rising};
	Interrupt_init(&Interrupt_Config);
	INT0_setCallBack(App);

	while(TRUE)
	{
	}
}
