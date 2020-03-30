/*
 * External_Interrupt.c
 *
 *  Created on: Oct 24, 2019
 *      Author: Nour
 *     Purpose: contains all external interrupt functions needed in this project
 */

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "External_Interrupt.h"
#include "Port.h"

/*******************************************************************************
 *                      Global Variables                                 	   *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_INT0_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_INT1_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_INT2_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                      Interrupt Service Routines                             *
 *******************************************************************************/

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

/*******************************************************************************
 *                      Function Definitions                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void INT0_setCallBack(void(*a_ptr)(void))
*   Description:        call back function when interrupt0 is initiated.
*   Input:              void(*a_ptr)(void) refers to function called by the call-back function in upper layer
*   Output:             None
*   return:             void
******************************************************/
void INT0_setCallBack(void(*a_ptr)(void))
{
	g_INT0_callBackPtr = a_ptr;
}

/*****************************************************
*   Function Prototype: void INT1_setCallBack(void(*a_ptr)(void))
*   Description:        call back function when interrupt1 is initiated.
*   Input:              void(*a_ptr)(void) refers to function called by the call-back function in upper layer
*   Output:             None
*   return:             void
******************************************************/
void INT1_setCallBack(void(*a_ptr)(void))
{
	g_INT1_callBackPtr = a_ptr;
}

/*****************************************************
*   Function Prototype: void INT2_setCallBack(void(*a_ptr)(void))
*   Description:        call back function when interrupt2 is initiated.
*   Input:              void(*a_ptr)(void) refers to function called by the call-back function in upper layer
*   Output:             None
*   return:             void
******************************************************/
void INT2_setCallBack(void(*a_ptr)(void))
{
	g_INT2_callBackPtr = a_ptr;
}

/*****************************************************
*   Function Prototype: void Interrupt_init(Interrupt_ConfigType * Config_Ptr);
*   Description:        Initialization external interrupts.
*   Input:              Interrupt_ConfigType represents pointer to interrupt configuration structure
*   Output:             None
*   return:             void
******************************************************/
void Interrupt_init(Interrupt_ConfigType * Config_Ptr)
{
	if(Config_Ptr -> interrupt == interrupt0)
	{
		/* set the interrupt state */
		MCUCR_R |= Config_Ptr -> state;

		/* set pin corresponding to INT0 as input pin */
		set_direction(DDRD_R,PD2_B,IN);

		/* enable INT0 */
		SET_BIT(GICR_R,INT0_B);
	}
	else if(Config_Ptr -> interrupt == interrupt1)
	{
		/* set the interrupt state */
		MCUCR_R |= (Config_Ptr -> state) << ISC10_B;

		/* set pin corresponding to INT1 as input pin */
		set_direction(DDRD_R,PD3_B,IN);

		/* enable INT1 */
		SET_BIT(GICR_R,INT1_B);
	}
	else if(Config_Ptr -> interrupt == interrupt2)
	{
		/* set the interrupt state */
		MCUCSR_R |= ((Config_Ptr -> state) & 0x1) << ISC2_B;

		/* set pin corresponding to INT2 as input pin */
		set_direction(DDRB_R,PB2_B,IN);

		/* enable INT2 */
		SET_BIT(GICR_R,INT2_B);
	}
}

/*****************************************************
*   Function Prototype: void Interrupt0_setEdgeDetectionType(State state)
*   Description:        set edge of external interrupt0.
*   Input:              State refers to rising or falling edge
*   Output:             None
*   return:             void
******************************************************/
void Interrupt0_setEdgeDetectionType(State state)
{
	/* set the interrupt state */
	MCUCR_R |= state;
}

/*****************************************************
*   Function Prototype: void Interrupt1_setEdgeDetectionType(State state)
*   Description:        set edge of external interrupt1.
*   Input:              State refers to rising or falling edge
*   Output:             None
*   return:             void
******************************************************/
void Interrupt1_setEdgeDetectionType(State state)
{
	/* set the interrupt state */
	MCUCR_R |= state << ISC10_B;
}

/*****************************************************
*   Function Prototype: void Interrupt2_setEdgeDetectionType(State state)
*   Description:        set edge of external interrupt2.
*   Input:              State refers to rising or falling edge
*   Output:             None
*   return:             void
******************************************************/
void Interrupt2_setEdgeDetectionType(State state)
{
	/* set the interrupt state */
	MCUCSR_R |= (state & 0x1) << ISC2_B;
}

/*****************************************************
*   Function Prototype: void Interrupt0_DeInit(void)
*   Description:        De-initialize interrupt0.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void Interrupt0_DeInit(void)
{
	CLEAR_BIT(GICR_R,INT0_B);
}

/*****************************************************
*   Function Prototype: void Interrupt1_DeInit(void)
*   Description:        De-initialize interrupt1.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void Interrupt1_DeInit(void)
{
	CLEAR_BIT(GICR_R,INT1_B);
}

/*****************************************************
*   Function Prototype: void Interrupt2_DeInit(void)
*   Description:        De-initialize interrupt2.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void Interrupt2_DeInit(void)
{
	CLEAR_BIT(GICR_R,INT2_B);
}
