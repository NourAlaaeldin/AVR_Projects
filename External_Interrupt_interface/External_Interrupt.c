/*
 * External_Interrupt.c
 *
 *  Created on: Oct 24, 2019
 *      Author: Nour
 */

#include "External_Interrupt.h"

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_INT0_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_INT1_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_INT2_callBackPtr)(void) = NULL_PTR;

ISR(INT0_vect)
{
	if(g_INT0_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application  */
		(*g_INT0_callBackPtr)();
	}
}

ISR(INT1_vect)
{
	if(g_INT1_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application  */
		(*g_INT1_callBackPtr)();
	}
}

ISR(INT2_vect)
{
	if(g_INT2_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application  */
		(*g_INT2_callBackPtr)();
	}
}

void
INT0_setCallBack(void(*a_ptr)(void))
{
	g_INT0_callBackPtr = a_ptr;
}

void
INT1_setCallBack(void(*a_ptr)(void))
{
	g_INT1_callBackPtr = a_ptr;
}

void
INT2_setCallBack(void(*a_ptr)(void))
{
	g_INT2_callBackPtr = a_ptr;
}

void
Interrupt_init(Interrupt_ConfigType * Config_Ptr)
{
	if(Config_Ptr -> interrupt == interrupt0)
	{
		MCUCR_R = Config_Ptr -> state;
		CLEAR_BIT(DDRD_R,PD2_B);
		SET_BIT(GICR_R,INT0_B);
	}
	else if(Config_Ptr -> interrupt == interrupt1)
	{
		MCUCR_R = (Config_Ptr -> state) << ISC10_B;
		CLEAR_BIT(DDRD_R,PD3_B);
		SET_BIT(GICR_R,INT1_B);
	}
	else if(Config_Ptr -> interrupt == interrupt2)
	{
		MCUCSR_R = ((Config_Ptr -> state) & 0x1) << ISC2_B;
		CLEAR_BIT(DDRB_R,PB2_B);
		SET_BIT(GICR_R,INT2_B);
	}
}
