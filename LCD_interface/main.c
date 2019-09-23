/*
 * main.c
 *
 *  Created on: Sep 17, 2019
 *      Author: Nour
 */

#include "LCD.h"

int
main(void)
{
	SET_BIT(DDRA_R,PA0_B);
	LCD_init(); /* initialize LCD */
	LCD_displayCharacter('A');
//	LCD_displayStringRowColumn(0,2,"My LCD Driver");
//	LCD_displayStringRowColumn(1,3,"Embedded WS");
//	_delay_ms(4000); /* wait four seconds */
//
//	LCD_clearScreen(); /* clear the LCD display */
//	LCD_displayString("Interf. Course");
//    LCD_displayStringRowColumn(1,5,"Group ");
//    LCD_intgerToString(40);
	while(TRUE)
	{
		SET_BIT(PORTA_R,PA0_B);
	}
}
