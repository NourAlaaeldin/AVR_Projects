/*
 * LCD.h
 *
 *  Created on: Sep 16, 2019
 *      Author: Nour
 *     Purpose: contains all LCD functions needed in this project
 */

#ifndef LCD_H_
#define LCD_H_

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "standard_library.h"

/*******************************************************************************
 *                      Preprocessor Defines                                   *
 *******************************************************************************/

#define TWO_LINE_LCD_8_BIT_MODE

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

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void LCD_init(void)
*   Description:        Initialization LCD.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void LCD_init(void);

/*****************************************************
*   Function Prototype: void LCD_sendCommand(uint8 cmd)
*   Description:        Send command.
*   Input:              uint8 refers to command
*   Output:             None
*   return:             void
******************************************************/
extern void LCD_sendCommand(uint8 cmd);

/*****************************************************
*   Function Prototype: void LCD_displayCharacter(uint8 data)
*   Description:        Display character.
*   Input:              uint8 refers to data
*   Output:             None
*   return:             void
******************************************************/
extern void LCD_displayCharacter(uint8 data);

/*****************************************************
*   Function Prototype: void LCD_displayString(const uint8 *str)
*   Description:        Display string.
*   Input:              uint8* refers to string
*   Output:             None
*   return:             void
******************************************************/
extern void LCD_displayString(const uint8 *str);

/*****************************************************
*   Function Prototype: void LCD_displayStringRowColumn(uint8 row,uint8 col,const uint8 *str)
*   Description:        Display string at certain row and column.
*   Input:              uint8* refers to string,uint8 refers to row and uint8 refers to column
*   Output:             None
*   return:             void
******************************************************/
extern void LCD_displayStringRowColumn(uint8 row,uint8 col,const uint8 *str);

/*****************************************************
*   Function Prototype: void LCD_goToRowColumn(uint8 row,uint8 col)
*   Description:        Go to a certain row and column.
*   Input:              uint8 refers to row and uint8 refers to column
*   Output:             None
*   return:             void
******************************************************/
extern void LCD_goToRowColumn(uint8 row,uint8 col);

/*****************************************************
*   Function Prototype: void LCD_intgerToString(uint8 data)
*   Description:        Converts integer data to string.
*   Input:              uint8 refers to data
*   Output:             None
*   return:             void
******************************************************/
extern void LCD_intgerToString(uint8 data);

/*****************************************************
*   Function Prototype: void LCD_clearScreen(void)
*   Description:        Clear LCD screen.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void LCD_clearScreen(void);

#endif /* LCD_H_ */
