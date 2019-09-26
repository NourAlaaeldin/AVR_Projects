/*
 * AVR_registers.h
 *
 *  Created on: Sep 16, 2019
 *      Author: Nour
 */

#ifndef AVR_REGISTERS_H_
#define AVR_REGISTERS_H_

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

#define WDP0_B		0
#define WDP1_B		1
#define WDP2_B		2
#define WDE_B		3
#define WDTOE_B		4

/* Timer 1 */


/* ADC registers and bits */

#define ADMUX_R		(*(volatile uint8 * const)0x0027)

#define MUX0_B		0
#define MUX1_B		1
#define MUX2_B		2
#define MUX3_B		3
#define MUX4_B		4
#define ADLAR_B		5
#define REFS0_B		6
#define REFS1_B		7

#define ADCSRA_R	(*(volatile uint8 * const)0x0026)

#define ADPS0_B		0
#define ADPS1_B		1
#define ADPS2_B		2
#define ADIE_B		3
#define ADIF_B		4
#define ADATE_B		5
#define ADSC_B		6
#define ADEN_B		7

#define ADCL_R		(*(volatile uint8 * const)0x0024)
#define ADCH_R		(*(volatile uint8 * const)0x0025)

#define ADC_R		(*(volatile uint16 * const)0x0024)

#define SFIOR_R		(*(volatile uint8 * const)0x0050)

#define ADTS0_B		5
#define ADTS1_B		6
#define ADTS2_B		7

/* SPI registers and bits */

#define SPCR_R		(*(volatile uint8 * const)0x002D)

#define SPR0_B		0
#define SPR1_B		1
#define CPHA_B		2
#define CPOL_B		3
#define MSTR_B		4
#define DORD_B		5
#define SPE_B		6
#define SPIE_B		7

#define SPSR_R		(*(volatile uint8 * const)0x002E)

#define SPI2X_B		0
#define WCOL_B		6
#define SPIF_B		7

#define SPDR_R		(*(volatile uint8 * const)0x002F)

#define LSB_B		0
#define MSB_B		7

/* UART registers and bits */

#define	UDR_R		(*(volatile uint8 * const)0x002C)

#define UCSRA_R		(*(volatile uint8 * const)0x002B)

#define	MPCM_B		0
#define U2X_B		1
#define PE_B		2
#define DOR_B		3
#define FE_B		4
#define UDRE_B		5
#define TXC_B		6
#define RXC_B		7

#define UCSRB_R		(*(volatile uint8 * const)0x002A)

#define TXB8_B		0
#define RXB8_B		1
#define UCSZ2_B		2
#define TXEN_B		3
#define RXEN_B		4
#define UDRIE_B		5
#define TXCIE_B		6
#define RXCIE_B		7

#define UCSRC_R		(*(volatile uint8 * const)0x0040)

#define	UCPOL_B		0
#define UCSZ0_B		1
#define UCSZ1_B		2
#define USBS_B		3
#define UPM0_B		4
#define UPM1_B		5
#define UMSEL_B		6
#define URSEL_B		7

#define UBRRL_R		(*(volatile uint8 * const)0x0029)
#define UBRRH_R		(*(volatile uint8 * const)0x0040)

#endif /* AVR_REGISTERS_H_ */
