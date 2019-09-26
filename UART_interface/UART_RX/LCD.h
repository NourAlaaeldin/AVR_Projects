/*
 * LCD.h
 *
 *  Created on: Sep 16, 2019
 *      Author: Nour
 */

#ifndef LCD_H_
#define LCD_H_

#include <util/delay.h>

#include "standard_library.h"
#include "common_macros.h"
#include "AVR_registers.h"

//#define FIRST_4_PINS
#define TWO_LINE_LCD_8_BIT_MODE

#ifdef	FIRST_4_PINS
#define FIRST_FOUR_PINS					0x0F
#endif

#ifdef	SECOND_4_PINS
#define SECOND_FOUR_PINS				0xF0
#endif

#define LCD_CTRL_DIR					DDRD_R
#define LCD_CTRL_OUT					PORTD_R

#define LCD_DATA_DIR					DDRC_R
#define LCD_DATA_OUT					PORTC_R

#define RS								PD4_B
#define RW								PD5_B
#define E								PD6_B

/* LCD Commands */

#ifdef  TWO_LINE_LCD_4_BIT_MODE
#define TWO_LINE_LCD_Four_BIT_MODE 	    0x28
#define FOUR_BITS_DATA_MODE 			0x02
#endif

#ifdef	TWO_LINE_LCD_8_BIT_MODE
#define TWO_LINE_LCD_Eight_BIT_MODE 	0x38
#endif

#define CLEAR_COMMAND 					0x01
#define CURSOR_OFF 						0x0C
#define CURSOR_ON 						0x0E
#define SET_CURSOR_LOCATION 			0x80

extern void LCD_init(void);
extern void LCD_sendCommand(uint8 cmd);
extern void LCD_displayCharacter(uint8 data);
extern void LCD_displayString(const uint8 *str);
extern void LCD_displayStringRowColumn(uint8 row,uint8 col,const uint8 *str);
extern void LCD_goToRowColumn(uint8 row,uint8 col);
extern void LCD_intgerToString(uint8 data);
extern void LCD_clearScreen(void);

#endif /* LCD_H_ */
