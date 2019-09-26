/*
 * UART_TX.c
 *
 *  Created on: Sep 26, 2019
 *      Author: Nour
 */

#include "UART.h"
#include "keypad.h"
#include <util\delay.h>

int
main(void)
{
	uint8 key;
	UART_ConfigType UART_Config = {Disabled,_1_bit,_8_bit};

	UART_init(&UART_Config);

	while(TRUE)
	{
		key = Keypad_getPressedKey();

		UART_sendByte(key);

		_delay_ms(500);
	}
}
