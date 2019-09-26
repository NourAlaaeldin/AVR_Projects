/*
 * SPI.c
 *
 *  Created on: Sep 25, 2019
 *      Author: Nour
 */

#include "SPI.h"

void
SPI_initMaster(const SPI_ConfigType * Config_Ptr)
{
	/* SS output */
	SET_BIT(DDRB_R,PB4_B);

	/* MOSI output and MISO input */
	SET_BIT(DDRB_R,PB5_B);
	CLEAR_BIT(DDRB_R,PB6_B);

	/* SCK output */
	SET_BIT(DDRB_R,PB7_B);

	/*
	 * Enable SPI
	 * Enable Master
	 * Set SPI frequency
	 */
	SPCR_R = (1 << SPE_B) 							|
			 (1 << MSTR_B) 							|
			 (Config_Ptr -> frequency << SPR0_B);
}

void
SPI_initSlave(const SPI_ConfigType * Config_Ptr)
{
	/* SS input */
	CLEAR_BIT(DDRB_R,PB4_B);

	/* MOSI input and MISO output */
	CLEAR_BIT(DDRB_R,PB5_B);
	SET_BIT(DDRB_R,PB6_B);

	/* SCK input */
	CLEAR_BIT(DDRB_R,PB7_B);

	/*
	 * Enable SPI
	 * Enable Master
	 * Set SPI frequency
	 */
	SPCR_R = (1 << SPE_B) 							|
			 (Config_Ptr -> frequency << SPR0_B);
}

void
SPI_sendByte(uint8 byte)
{
	SPDR_R = byte;
	while(BIT_IS_CLEAR(SPSR_R,SPIF_B));
}

void
SPI_sendString(const uint8 * Str_Ptr)
{
	uint8 i = 0;
	while (Str_Ptr[i] != '\0')
	{
		SPI_sendByte(Str_Ptr[i]);
		i++;
	}
}

uint8
SPI_recieveByte(void)
{
	while(BIT_IS_CLEAR(SPSR_R,SPIF_B));
	return SPDR_R;
}

void
SPI_recieveString(uint8 * Str_Ptr)
{
	uint8 i = 0;
	Str_Ptr[i] = SPI_recieveByte();
	do
	{
		i++;
		Str_Ptr[i] = SPI_recieveByte();
	}
	while(Str_Ptr[i] != '#');

	Str_Ptr[i] = '\0';
}
