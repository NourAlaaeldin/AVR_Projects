/*
 * delay.h
 *
 *  Created on: Oct 7, 2019
 *      Author: Nour
 */

#ifndef DELAY_H_
#define DELAY_H_

#include "standard_library.h"
#include "common_macros.h"
#include "AVR_registers.h"

extern void delay_ms(uint16 msec);
extern void delay_s(uint16 sec);

#endif /* DELAY_H_ */
