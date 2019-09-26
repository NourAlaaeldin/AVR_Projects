/*
 * UART.h
 *
 *  Created on: Sep 25, 2019
 *      Author: Nour
 */

#ifndef UART_H_
#define UART_H_

#include "AVR_registers.h"
#include "common_macros.h"
#include "standard_library.h"

#define USART_BAUDRATE 9600

typedef enum
{
	Disabled,Even = 2,Odd
}UART_Parity;

typedef enum
{
	_1_bit,_2_bit
}UART_StopBit;

typedef enum
{
	_5_bit,_6_bit,_7_bit,_8_bit
}UART_Bits;

typedef struct
{
	UART_Parity		parity;
	UART_StopBit	stop_bit;
	UART_Bits		bits;
}UART_ConfigType;

extern void UART_init(const UART_ConfigType * Config_Ptr);
extern void UART_sendByte(uint8 data);
extern void UART_sendString(const uint8 * Str_Ptr);
extern uint8 UART_recieveByte(void);
extern void UART_recieveString(uint8 * Str_Ptr);

#endif /* UART_H_ */
