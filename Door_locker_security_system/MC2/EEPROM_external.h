/*
 * EEPROM_external.h
 *
 *  Created on: Oct 6, 2019
 *      Author: Nour
 */

#ifndef EEPROM_EXTERNAL_H_
#define EEPROM_EXTERNAL_H_

#include "standard_library.h"

#define ERROR   0
#define SUCCESS 1


extern void EEPROM_external_init(void);
extern uint8 EEPROM_external_write_byte(uint16 u16addr,uint8 u8data);
extern uint8 EEPROM_external_read_byte(uint16 u16addr,uint8 * u8data);

#endif /* EEPROM_EXTERNAL_H_ */
