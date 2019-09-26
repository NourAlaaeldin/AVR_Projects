/*
 * SPI_TX.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Nour
 */

#include "SPI.h"
#include "keypad.h"
#include <util\delay.h>

int
main(void)
{
	uint8 key;
	SPI_ConfigType SPI_Config = {_4};

	SPI_initMaster(&SPI_Config);

	while(TRUE)
	{
		key = Keypad_getPressedKey();

		SPI_sendByte(key);

		_delay_ms(500);
	}
}
