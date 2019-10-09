/*
 * TWI.h
 *
 *  Created on: Oct 6, 2019
 *      Author: Nour
 */

#ifndef TWI_H_
#define TWI_H_

#include "AVR_registers.h"
#include "common_macros.h"
#include "standard_library.h"

/* I2C Status Bits in the TWSR Register */
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave

#define NORMAL			 100000
#define FAST			 400000

#define SCL				 FAST

/* F_CPU=8Mhz */
#define TWBR_VALUE		 (uint8)(((F_CPU/SCL) - 16) / 2)

extern void TWI_init(void);
extern void TWI_start(void);
extern void TWI_stop(void);
extern void TWI_write(uint8 data);
extern uint8 TWI_read_with_ACK(void);
extern uint8 TWI_read_with_NACK(void);
extern uint8 TWI_get_status(void);

#endif /* TWI_H_ */
