/*
 * UART_RX.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Nour
 */

#include "UART.h"
#include "LCD.h"

int
main(void)
{
	uint8 Byte;
	UART_ConfigType UART_Config = {Disabled,_1_bit,_8_bit};

	UART_init(&UART_Config);
	LCD_init();

	while(TRUE)
	{
		Byte =  UART_recieveByte();  //receive the pressed key from spi

		if((Byte >= 0) && (Byte <= 9))
		{
			LCD_intgerToString(Byte); //display the pressed key
		}

		else
		{
			LCD_displayCharacter(Byte);
		}
	}
}
