/*
 * potentiometer.c
 *  Created on: Sep 23, 2019
 *  Author: Nour Alaa
 */

#include "adc.h"
#include "lcd.h"

int main(void)
{
	SET_BIT(SREG_R,I_B);

	/* Create configuration structure for ADC driver */
	ADC_ConfigType ADC_Config = {AREF,_8,Interrupt};

	/* initialize LCD driver */
	LCD_init();

	 /* initialize ADC driver */
	ADC_init(&ADC_Config);

	 /* clear LCD at the beginning */
	LCD_clearScreen();

	/* display this string "ADC Value = " only once at LCD */
	LCD_displayString("ADC Value = ");

	while(TRUE)
    {
		/* display the number every time at this position */
		LCD_goToRowColumn(0,12);

		/* read channel zero where the potentiometer is connect */
		ADC_readChannel(0,&ADC_Config);

		/* display the ADC value on LCD screen */
		LCD_intgerToString(g_ADC_value);
    }
}


