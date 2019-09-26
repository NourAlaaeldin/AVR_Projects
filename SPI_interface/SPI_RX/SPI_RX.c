/*
 * SPI_RX.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Nour
 */

#include "SPI.h"
#include "LCD.h"

int
main(void)
{
	uint8 Byte;
	SPI_ConfigType SPI_Config = {_4};

	SPI_initSlave(&SPI_Config);
	LCD_init();

	while(TRUE)
	{
		Byte =  SPI_recieveByte();  //receive the pressed key from spi

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
