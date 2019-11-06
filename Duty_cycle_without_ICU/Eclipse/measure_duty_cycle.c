/*
 * measure_duty_cycle.c
 *
 *  Created on: Jan 10, 2018
 *  Author: Mohamed Tarek
 */

#include "LCD.h"
#include "Timer.h"
#include "External_Interrupt.h"

uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;
uint16 g_timePeriod = 0;
uint16 g_timePeriodPlusHigh = 0;

/* Create configuration structure for external_interrupt driver */
Interrupt_ConfigType Interrupt_Config = {interrupt0,rising};

void APP_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		Timer1_clearTimerValue();
		/* Detect falling edge */
		Interrupt_setEdgeDetectionType(&Interrupt_Config,falling);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeHigh = Timer1_getTimerValue();
		//LCD_intgerToString(g_timeHigh);
		/* Detect rising edge */
		Interrupt_setEdgeDetectionType(&Interrupt_Config,rising);
	}
	else if(g_edgeCount == 3)
	{
		/* Store the Period time value */
		g_timePeriod = Timer1_getTimerValue();
		//LCD_intgerToString(g_timePeriod);
		/* Detect falling edge */
		Interrupt_setEdgeDetectionType(&Interrupt_Config,falling);
	}
	else if(g_edgeCount == 4)
	{
		/* Store the Period time value + High time value */
		g_timePeriodPlusHigh = Timer1_getTimerValue();
		//LCD_intgerToString(g_timePeriodPlusHigh);
		/* Clear the timer counter register to start measurements again */
		Timer1_clearTimerValue();
		/* Detect rising edge */
		Interrupt_setEdgeDetectionType(&Interrupt_Config,rising);
	}
}

int main()
{
	uint32 dutyCycle = 0;

	/* Enable Global Interrupt I-Bit */
	SREG_R |= (1<<7);
	/* Create configuration structure for Timer driver */
	Timer_ConfigType Timer_Config = {Timer1,Overflow,0,No_prescaling,0,0,0,0,0,0};

	/* Create configuration structure for external_interrupt driver */
	Interrupt_ConfigType Interrupt_Config = {interrupt0,rising};

	/* Initialize the drivers */
	LCD_init();
	Timer_init(&Timer_Config);
	Interrupt_init(&Interrupt_Config);

	//LCD_displayString("HELLO");
	/* Set the Call back function pointer in the external_interrupt driver */
	INT0_setCallBack(APP_edgeProcessing);


	while(1)
	{
		if(g_edgeCount == 4)
		{
			Timer1_DeInit(); /* Disable Timer1 Driver */
			Interrupt0_DeInit(); /* Disable external_interrupt Driver */
			g_edgeCount = 0;
			LCD_displayString("Duty = ");
			/* calculate the dutyCycle */
			dutyCycle = ((float)(g_timePeriodPlusHigh-g_timePeriod) / (g_timePeriodPlusHigh - g_timeHigh)) * 100;
			/* display the dutyCycle on LCD screen */
			LCD_intgerToString(dutyCycle);
			LCD_displayCharacter('%');
		}
	}
}
