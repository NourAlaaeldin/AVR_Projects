/*
 * main.c
 *
 *  Created on: Sep 17, 2019
 *      Author: Nour
 */

#include "LCD.h"
#include "keypad.h"

#define ARRAY_SIZE		(uint8)100
#define DELAY_TIME		500

int
main(void)
{
	uint8 key[ARRAY_SIZE] = {0};
	uint8 i;
	uint8 var1,var2,res;

	LCD_init(); /* initialize LCD */

	LCD_displayStringRowColumn(0,2,"Welcome to");
	LCD_displayStringRowColumn(1,1,"The Calculator");

	_delay_ms(DELAY_TIME); /* wait four seconds */

	LCD_clearScreen(); /* clear the LCD display */

	for(i = LOW;i < ARRAY_SIZE;i++)
	{
		key[i] = Keypad_getPressedKey();

		switch(key[i])
		{
		case 47: /* ASCII of '/' */

			var1 = key[i - 1];
			LCD_displayCharacter(' ');
			LCD_displayCharacter('/');
			LCD_displayCharacter(' ');
			_delay_ms(DELAY_TIME);
			var2 = Keypad_getPressedKey();
			LCD_intgerToString(var2);
			res = var1 / var2;
			break;

		case 42:
			var1 = key[i - 1];
			LCD_displayCharacter(' ');
			LCD_displayCharacter('*');
			LCD_displayCharacter(' ');
			_delay_ms(DELAY_TIME);
			var2 = Keypad_getPressedKey();
			LCD_intgerToString(var2);
			res = var1 * var2;
			break;

		case 45:
			var1 = key[i - 1];
			LCD_displayCharacter(' ');
			LCD_displayCharacter('-');
			LCD_displayCharacter(' ');
			_delay_ms(DELAY_TIME);
			var2 = Keypad_getPressedKey();
			LCD_intgerToString(var2);
			res = var1 - var2;
			break;

		case 43:
			var1 = key[i - 1];
			LCD_displayCharacter(' ');
			LCD_displayCharacter('+');
			LCD_displayCharacter(' ');
			_delay_ms(DELAY_TIME);
			var2 = Keypad_getPressedKey();
			LCD_intgerToString(var2);
			res = var1 + var2;
			break;

		case 61:
			LCD_displayCharacter(' ');
			LCD_displayCharacter('=');
			LCD_displayCharacter(' ');
			LCD_intgerToString(res);
			break;

		/*ASCII of ON button*/
		case 13:
			LCD_clearScreen();
			break;

		default:
			LCD_intgerToString(key[i]);
			break;
		}
		_delay_ms(DELAY_TIME);
	}
	while(TRUE)
	{
	}
}
