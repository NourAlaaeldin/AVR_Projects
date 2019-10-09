/*
 * TWI.c
 *
 *  Created on: Oct 6, 2019
 *      Author: Nour
 */

#include "TWI.h"

void
TWI_init(void)
{

	TWBR_R = TWBR_VALUE;
	TWSR_R = 0;
    /*
     * Two Wire Bus address: my address if any master device want to call me
     * General Call Recognition: Off
     */
	TWAR_R = 0x01 << TWA0_B;

	TWCR_R = (1 << TWEN_B);
}

void
TWI_start(void)
{
    /*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR_R = (1 << TWEN_B) | (1 << TWSTA_B) | (1 << TWINT_B);

    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while(BIT_IS_CLEAR(TWCR_R,TWINT_B));
}

void
TWI_stop(void)
{
    /*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR_R = (1 << TWEN_B) | (1 << TWSTO_B) | (1 << TWINT_B);
}

void
TWI_write(uint8 data)
{
    /* Put data On TWI data Register */
	TWDR_R = data;

    /*
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR_R = (1 << TWEN_B) | (1 << TWWC_B) | (1 << TWINT_B);

    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while(BIT_IS_CLEAR(TWCR_R,TWINT_B));
}

uint8
TWI_read_with_ACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR_R = (1 << TWEN_B) | (1 << TWINT_B) | (1 << TWEA_B);

    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while(BIT_IS_CLEAR(TWCR_R,TWINT_B));

    /* Read Data */
    return TWDR_R;
}

uint8
TWI_read_with_NACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR_R = (1 << TWINT_B) | (1 << TWEN_B);

    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR_R,TWINT_B));

    /* Read Data */
    return TWDR_R;
}

uint8
TWI_get_status(void)
{
    uint8 status;

    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWSR_R & 0xF8;

    return status;
}
