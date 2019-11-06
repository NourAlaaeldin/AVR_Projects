/*
 * Timer.c
 *
 *  Created on: Sep 28, 2019
 *      Author: Nour
 */

#include "Timer.h"

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_Timer0_OVF_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_Timer0_COMP_callBackPtr)(void) = NULL_PTR;

static volatile void (*g_Timer2_OVF_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_Timer2_COMP_callBackPtr)(void) = NULL_PTR;

static volatile void (*g_Timer1_OVF_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_Timer1_COMPA_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_Timer1_COMPB_callBackPtr)(void) = NULL_PTR;

ISR(TIMER0_OVF_vect)
{
	if(g_Timer0_OVF_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application  */
		(*g_Timer0_OVF_callBackPtr)();
	}
}

ISR(TIMER0_COMP_vect)
{
	if(g_Timer0_COMP_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application  */
		(*g_Timer0_COMP_callBackPtr)();
	}
}

ISR(TIMER2_OVF_vect)
{
	if(g_Timer2_OVF_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application  */
		(*g_Timer2_OVF_callBackPtr)();
	}
}

ISR(TIMER2_COMP_vect)
{
	if(g_Timer2_COMP_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application  */
		(*g_Timer2_COMP_callBackPtr)();
	}
}

ISR(TIMER1_OVF_vect)
{
	if(g_Timer1_OVF_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application  */
		(*g_Timer1_OVF_callBackPtr)();
	}
}

ISR(TIMER1_COMPA_vect)
{
	if(g_Timer1_COMPA_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application  */
		(*g_Timer1_COMPA_callBackPtr)();
	}
}

ISR(TIMER1_COMPB_vect)
{
	if(g_Timer1_COMPB_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application  */
		(*g_Timer1_COMPB_callBackPtr)();
	}
}

void
Timer0_OVF_setCallBack(void(*a_ptr)(void))
{
	g_Timer0_OVF_callBackPtr = a_ptr;
}

void
Timer0_COMP_setCallBack(void(*a_ptr)(void))
{
	g_Timer0_COMP_callBackPtr = a_ptr;
}

void
Timer2_OVF_setCallBack(void(*a_ptr)(void))
{
	g_Timer2_OVF_callBackPtr = a_ptr;
}

void
Timer2_COMP_setCallBack(void(*a_ptr)(void))
{
	g_Timer2_COMP_callBackPtr = a_ptr;
}

void
Timer1_OVF_setCallBack(void(*a_ptr)(void))
{
	g_Timer1_OVF_callBackPtr = a_ptr;
}

void
Timer1_COMPA_setCallBack(void(*a_ptr)(void))
{
	g_Timer1_COMPA_callBackPtr = a_ptr;
}
void
Timer1_COMPB_setCallBack(void(*a_ptr)(void))
{
	g_Timer1_COMPB_callBackPtr = a_ptr;
}

void
Timer_init(Timer_ConfigType * Config_Ptr)
{
	if(Config_Ptr -> timer == Timer0)
	{
		/* Timer initial value */
		TCNT0_R = 0;

		/* In case of overflow or CTC mode */

		/* Note: WGM00 and WGM01 are not followed in registers arrangement */
		TCCR0_R = (1 << FOC0_B) 									|
				  ((Config_Ptr -> mode & 0x1) << WGM00_B) 			|
				  (((Config_Ptr -> mode & 0x2) >> 1) << WGM01_B) 	|
				  (Config_Ptr -> prescalar_Timer0 << CS00_B);

		if(Config_Ptr -> mode == Overflow)
		{
			/* Enable Timer0 overflow interrupt */
			SET_BIT(TIMSK_R,TOIE0_B);
		}
		else if(Config_Ptr -> mode == CTC)
		{
			/* Compare value */
			OCR0_R  = Config_Ptr -> u8_comp_value;

			/* Check if we are not producing a square wave on OCO pin */
			if(Config_Ptr -> COM == Normal)
			{
				/* Enable Timer0 CTC interrupt */
				SET_BIT(TIMSK_R,OCIE0_B);
			}
			else
			{
				TCCR0_R = (1 << FOC0_B) 									|
						  ((Config_Ptr -> mode & 0x1) << WGM00_B) 			|
						  (((Config_Ptr -> mode & 0x2) >> 1) << WGM01_B) 	|
						  (Config_Ptr -> prescalar_Timer0 << CS00_B)		|
						  (Config_Ptr -> COM << COM00_B);

				/* Set OC0 as output pin */
				SET_BIT(DDRB_R,PB3_B);
			}
		}
	}
	else if(Config_Ptr -> timer == Timer2)
	{
		/* Timer initial value */
		TCNT2_R = 0;

		/* In case of overflow or CTC mode */

		/* Note: WGM20 and WGM21 are not followed in registers arrangement */
		TCCR2_R = (1 << FOC2_B) 									|
				  ((Config_Ptr -> mode & 0x1) << WGM20_B) 			|
				  (((Config_Ptr -> mode & 0x2) >> 1) << WGM21_B) 	|
				  (Config_Ptr -> prescalar_Timer2 << CS20_B);

		if(Config_Ptr -> mode == Overflow)
		{
			/* Enable Timer2 overflow interrupt */
			SET_BIT(TIMSK_R,TOIE2_B);
		}
		else if(Config_Ptr -> mode == CTC)
		{
			/* Compare value */
			OCR2_R  = Config_Ptr -> u8_comp_value;

			/* Check if we are not producing a square wave on OC2 pin */
			if(Config_Ptr -> COM == Normal)
			{
				/* Enable Timer2 CTC interrupt */
				SET_BIT(TIMSK_R,OCIE2_B);
			}
			else
			{
				TCCR2_R = (1 << FOC2_B) 									|
						  ((Config_Ptr -> mode & 0x1) << WGM20_B) 			|
						  (((Config_Ptr -> mode & 0x2) >> 1) << WGM21_B) 	|
						  (Config_Ptr -> prescalar_Timer2 << CS20_B)		|
						  (Config_Ptr -> COM << COM20_B);

				/* Set OC2 as output pin */
				SET_BIT(DDRD_R,PD7_B);
			}
		}
	}
	else if(Config_Ptr -> timer == Timer1)
	{
		/* Timer initial value */
		TCNT1_R = 0;

		/* In case of overflow or CTC mode */
		TCCR1A_R = (1 << FOC1A_B) | (1 << FOC1B_B);

		TCCR1B_R = (Config_Ptr -> prescalar_Timer1 << CS10_B) |
				   ((Config_Ptr -> mode >> 1) << WGM12_B);


		if(Config_Ptr -> mode == Overflow)
		{
			//SET_BIT(TIMSK_R,TOIE1_B);
		}

		/* We have two channels Channel A and Channel B */
		else if(Config_Ptr -> mode == CTC)
		{
			if(Config_Ptr -> channel == Channel_A)
			{
				/* Compare value */
				OCR1A_R = Config_Ptr -> u16_comp_value_A;

				/* Check if we are not producing a square wave on OC1A pin */
				if(Config_Ptr -> COM == Normal)
				{
					/* Enable Timer1_A CTC interrupt */
					SET_BIT(TIMSK_R,OCIE1A_B);
				}
				else
				{
					TCCR1A_R = (1 << FOC1A_B) | (1 << FOC1B_B) |
							   (Config_Ptr -> COM << COM1A0_B);

					/* Set OC1A as output pin */
					SET_BIT(DDRD_R,PD5_B);
				}
			}
			else if(Config_Ptr -> channel == Channel_B)
			{
				/* Compare value */
				OCR1B_R = Config_Ptr -> u16_comp_value_B;

				/* Check if we are not producing a square wave on OC1B pin */
				if(Config_Ptr -> COM == Normal)
				{
					/* Enable Timer1_B CTC interrupt */
					SET_BIT(TIMSK_R,OCIE1B_B);
				}
				else
				{
					TCCR1A_R = (1 << FOC1A_B) | (1 << FOC1B_B) |
							   (Config_Ptr -> COM << COM1B0_B);

					/* Set OC1B as output pin */
					SET_BIT(DDRD_R,PD4_B);
				}
			}
		}
	}
}

void
Timer2_DeInit(void)
{
	TCNT2_R = 0;
	TCCR2_R = 0;
}

void
Timer0_DeInit(void)
{
	TCNT0_R = 0;
	TCCR0_R = 0;
}

void
Timer1_DeInit(void)
{
	TCNT1_R = 0;
	TCCR1A_R = 0;
	TCCR1B_R = 0;
}

void
Timer0_clearTimerValue(void)
{
	TCNT0_R = 0;
}

void
Timer1_clearTimerValue(void)
{
	TCNT1_R = 0;
}

void
Timer2_clearTimerValue(void)
{
	TCNT2_R = 0;
}

uint8
Timer0_getTimerValue(void)
{
	return TCNT0_R;
}

uint16
Timer1_getTimerValue(void)
{
	return TCNT1_R;
}

uint8
Timer2_getTimerValue(void)
{
	return TCNT2_R;
}
