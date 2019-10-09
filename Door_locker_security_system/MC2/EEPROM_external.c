/*
 * EEPROM_external.c
 *
 *  Created on: Oct 6, 2019
 *      Author: Nour
 */

#include "EEPROM_external.h"
#include "TWI.h"

void
EEPROM_external_init(void)
{
	TWI_init();
}

uint8
EEPROM_external_write_byte(uint16 u16addr,uint8 u8data)
{
	TWI_start();

    if (TWI_get_status() != TW_START)
        return ERROR;

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    TWI_write((uint8)(0xA0 | ((u16addr & 0x0700) >> 7)));

    if (TWI_get_status() != TW_MT_SLA_W_ACK)
        return ERROR;

    /* Send the required memory location address */
    TWI_write((uint8)(u16addr));

    if (TWI_get_status() != TW_MT_DATA_ACK)
        return ERROR;

    /* write byte to EEPROM */
    TWI_write(u8data);

    if (TWI_get_status() != TW_MT_DATA_ACK)
        return ERROR;

    /* Send the Stop Bit */
    TWI_stop();

    return SUCCESS;
}

uint8
EEPROM_external_read_byte(uint16 u16addr,uint8 * u8data)
{
	/* Send the Start Bit */
    TWI_start();

    if (TWI_get_status() != TW_START)
        return ERROR;

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    TWI_write((uint8)((0xA0) | ((u16addr & 0x0700)>>7)));

    if (TWI_get_status() != TW_MT_SLA_W_ACK)
        return ERROR;

    /* Send the required memory location address */
    TWI_write((uint8)(u16addr));

    if (TWI_get_status() != TW_MT_DATA_ACK)
        return ERROR;

    /* Send the Repeated Start Bit */
    TWI_start();
    if (TWI_get_status() != TW_REP_START)
        return ERROR;

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=1 (Read) */
    TWI_write((uint8)((0xA0) | ((u16addr & 0x0700)>>7) | 1));

    if (TWI_get_status() != TW_MT_SLA_R_ACK)
        return ERROR;

    /* Read Byte from Memory without send ACK */
    *u8data = TWI_read_with_NACK();

    if (TWI_get_status() != TW_MR_DATA_NACK)
        return ERROR;

    /* Send the Stop Bit */
    TWI_stop();

    return SUCCESS;
}
