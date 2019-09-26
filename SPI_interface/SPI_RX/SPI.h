/*
 * SPI.h
 *
 *  Created on: Sep 25, 2019
 *      Author: Nour
 */

#ifndef SPI_H_
#define SPI_H_

#include "AVR_registers.h"
#include "common_macros.h"
#include "standard_library.h"

typedef enum
{
	_4,_16,_64,_128,_2,_8,_32
}SCK_Frequency;

typedef struct
{
	SCK_Frequency frequency;
}SPI_ConfigType;

extern void SPI_initMaster(const SPI_ConfigType * Config_Ptr);
extern void SPI_initSlave(const SPI_ConfigType * Config_Ptr);
extern void SPI_sendByte(uint8 byte);
extern void SPI_sendString(const uint8 * Str_Ptr);
extern uint8 SPI_recieveByte(void);
extern void SPI_recieveString(uint8 * Str_Ptr);

#endif /* SPI_H_ */
