/*
 * UART.c
 *
 *  Created on: Sep 25, 2019
 *      Author: Nour
 */

#include "UART.h"

#define Baud_prescale	(((F_CPU / (USART_BAUDRATE * 8UL))) - 1)

void
UART_init(const UART_ConfigType * Config_Ptr)
{
	UCSRC_R = (1 << URSEL_B)						|
			  (Config_Ptr -> parity 	<< UPM0_B)	|
			  (Config_Ptr -> stop_bit 	<< USBS_B) 	|
			  (Config_Ptr -> bits 		<< UCSZ0_B);

	UCSRB_R = (1 << RXEN_B) | (1 << TXEN_B);

	UCSRA_R = (1 << U2X_B);

	UBRRL_R	= Baud_prescale;
	UBRRH_R = Baud_prescale >> 8;
}

void
UART_sendByte(uint8 data)
{
	UDR_R = data;
	while(BIT_IS_CLEAR(UCSRA_R,TXC_B));
	SET_BIT(UCSRA_R,TXC_B);
}

void
UART_sendString(const uint8 * Str_Ptr)
{
	uint8 i = 0;
	while (Str_Ptr[i] != '\0')
	{
		UART_sendByte(Str_Ptr[i]);
		i++;
	}
}

uint8
UART_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSRA_R,RXC_B));

	if(BIT_IS_SET(UCSRA_R,FE_B))
	{
		return 0;
	}
	if(BIT_IS_SET(UCSRA_R,DOR_B))
	{
		return 0;
	}
	if(BIT_IS_SET(UCSRA_R,PE_B))
	{
		return 0;
	}

	return UDR_R;
}

void
UART_recieveString(uint8 * Str_Ptr)
{
	uint8 i = 0;
	Str_Ptr[i] = UART_recieveByte();
	do
	{
		i++;
		Str_Ptr[i] = UART_recieveByte();
	}
	while(Str_Ptr[i] != '#');

	Str_Ptr[i] = '\0';
}
