/*
 * AVR_registers.h
 *
 *  Created on: Sep 16, 2019
 *      Author: Nour
 */

#ifndef AVR_REGISTERS_H_
#define AVR_REGISTERS_H_

#include "standard_library.h"

/* General purpose I/O registers and bits */

#define PORTA_R 	(*(volatile uint8 * const)0x003B)
#define PORTB_R 	(*(volatile uint8 * const)0x0038)
#define PORTC_R 	(*(volatile uint8 * const)0x0035)
#define PORTD_R 	(*(volatile uint8 * const)0x0032)

#define DDRA_R		(*(volatile uint8 * const)0x003A)
#define DDRB_R		(*(volatile uint8 * const)0x0037)
#define DDRC_R		(*(volatile uint8 * const)0x0034)
#define DDRD_R		(*(volatile uint8 * const)0x0031)

#define PINA_R		(*(volatile uint8 * const)0x0039)
#define PINB_R		(*(volatile uint8 * const)0x0036)
#define PINC_R		(*(volatile uint8 * const)0x0033)
#define PIND_R		(*(volatile uint8 * const)0x0030)

#define PA0_B		0
#define PA1_B		1
#define PA2_B		2
#define PA3_B		3
#define PA4_B		4
#define PA5_B		5
#define PA6_B		6
#define PA7_B		7

#define PB0_B		0
#define PB1_B		1
#define PB2_B		2
#define PB3_B		3
#define PB4_B		4
#define PB5_B		5
#define PB6_B		6
#define PB7_B		7

#define PC0_B		0
#define PC1_B		1
#define PC2_B		2
#define PC3_B		3
#define PC4_B		4
#define PC5_B		5
#define PC6_B		6
#define PC7_B		7

#define PD0_B		0
#define PD1_B		1
#define PD2_B		2
#define PD3_B		3
#define PD4_B		4
#define PD5_B		5
#define PD6_B		6
#define PD7_B		7

/* Interrupts registers and bits */

/* Global interrupt (I-bit) */

#define SREG_R		(*(volatile uint8 * const)0x005F)

#define I_B			7

/* External interrupt */

#define MCUCR_R     (*(volatile uint8 * const)0x0055)

#define ISC01_B		0
#define ISC10_B		1
#define ISC11_B		2

#define MCUCSR_R    (*(volatile uint8 * const)0x0054)

#define ISC2_B		6

#define GICR_R     	(*(volatile uint8 * const)0x005B)

#define INT0_B		6
#define INT1_B		7
#define INT2_B		5

#define GIFR_R     	(*(volatile uint8 * const)0x005A)

#define INTF0_B		6
#define INTF1_B		7
#define INTF2_B		5

/* Timers registers and bits */

/* Watchdog Timer */

#define WDTCR_R		(*(volatile uint8 * const)0x0041)

#define WDP0		0
#define WDP1		1
#define WDP2		2
#define WDE			3
#define WDTOE		4

#endif /* AVR_REGISTERS_H_ */
