/*
 * LCD.c
 *
 *  Created on: Sep 16, 2019
 *      Author: Nour
 *     Purpose: contains all LCD functions needed in this project
 */

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "LCD.h"
#include "Port.h"
#include "DIO.h"
#include <util/delay.h>

/*******************************************************************************
 *                      Function Definitions                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void LCD_init(void)
*   Description:        Initialization LCD.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void LCD_init(void)
{

	#ifdef	TWO_LINE_LCD_8_BIT_MODE
	set_direction_port(LCD_DATA_DIR,OUT); /* 8 bit mode */
	#endif

    #ifdef	TWO_LINE_LCD_4_BIT_MODE
	#ifdef FIRST_4_PINS
	set_direction_group(LCD_DATA_DIR,FIRST_FOUR_PINS,OUT);
	#endif
	#endif

	#ifdef	TWO_LINE_LCD_4_BIT_MODE
	#ifdef SECOND_4_PINS
	set_direction_group(LCD_DATA_DIR,SECOND_FOUR_PINS,OUT);
	#endif
    #endif

	/* set RS corresponding pin as output */
	set_direction(LCD_CTRL_DIR,RS,OUT);

	/* set RW corresponding pin as output */
	set_direction(LCD_CTRL_DIR,RW,OUT);

	/* set E corresponding pin as output */
	set_direction(LCD_CTRL_DIR,E,OUT);

	#ifdef	TWO_LINE_LCD_4_BIT_MODE
	/* initialize LCD in 4-bit mode */
	LCD_sendCommand(FOUR_BITS_DATA_MODE);

	/* use 2-line lcd + 4-bit Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(TWO_LINE_LCD_Four_BIT_MODE);
	#endif

	#ifdef	TWO_LINE_LCD_8_BIT_MODE
	/* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
	#endif

	/* cursor off */
	LCD_sendCommand(CURSOR_OFF);

	/* clear LCD at the beginning */
	LCD_sendCommand(CLEAR_COMMAND);
}

/*****************************************************
*   Function Prototype: void LCD_sendCommand(uint8 cmd)
*   Description:        Send command.
*   Input:              uint8 refers to command
*   Output:             None
*   return:             void
******************************************************/
void LCD_sendCommand(uint8 cmd)
{
	/* Instruction Mode RS=0 */
	write_pin(LCD_CTRL_OUT,RS,LOW);

	/* write data to LCD so RW=0 */
	write_pin(LCD_CTRL_OUT,RW,LOW);

	/* delay for processing Tas = 50ns */
	_delay_ms(1);

	/* Enable LCD E=1 */
	write_pin(LCD_CTRL_OUT,E,HIGH);

	 /* delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);

	#ifdef	TWO_LINE_LCD_4_BIT_MODE
	#ifdef FIRST_4_PINS

	LCD_DATA_OUT = (LCD_DATA_OUT & ~FIRST_FOUR_PINS) | ((cmd & ~FIRST_FOUR_PINS) >> 4);

	/* delay for processing Tdsw = 100ns */
	_delay_ms(1);

	/* disable LCD E=0 */
	write_pin(LCD_CTRL_OUT,E,LOW);

	/* delay for processing Th = 13ns */
	_delay_ms(1);

	/* Enable LCD E=1 */
	write_pin(LCD_CTRL_OUT,E,HIGH);

	 /* delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);

	LCD_DATA_OUT = (LCD_DATA_OUT & ~FIRST_FOUR_PINS) | (cmd & FIRST_FOUR_PINS);

	#endif
	#endif

	#ifdef	TWO_LINE_LCD_4_BIT_MODE
	#ifdef	SECOND_4_PINS
	LCD_DATA_OUT = (LCD_DATA_OUT & ~SECOND_FOUR_PINS) | ((cmd & SECOND_FOUR_PINS) >> 4);
	/* delay for processing Tdsw = 100ns */
	_delay_ms(1);

	/* disable LCD E=0 */
	write_pin(LCD_CTRL_OUT,E,LOW);

	/* delay for processing Th = 13ns */
	_delay_ms(1);

	/* Enable LCD E=1 */
	write_pin(LCD_CTRL_OUT,E,HIGH);

	 /* delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);

	LCD_DATA_OUT = (LCD_DATA_OUT & ~SECOND_FOUR_PINS) | ((cmd & ~SECOND_FOUR_PINS) << 4);

	#endif
	#endif

	#ifdef	TWO_LINE_LCD_8_BIT_MODE

	/* out the required command to the data bus D0 --> D7 */
	write_port(LCD_DATA_OUT,cmd);

	#endif

	/* delay for processing Tdsw = 100ns */
	_delay_ms(1);

	/* disable LCD E=0 */
	write_pin(LCD_CTRL_OUT,E,LOW);

	/* delay for processing Th = 13ns */
	_delay_ms(1);
}

/*****************************************************
*   Function Prototype: void LCD_displayCharacter(uint8 data)
*   Description:        Display character.
*   Input:              uint8 refers to data
*   Output:             None
*   return:             void
******************************************************/
void LCD_displayCharacter(uint8 data)
{
	/* Instruction Mode RS=1 */
	write_pin(LCD_CTRL_OUT,RS,HIGH);

	/* write data to LCD so RW=0 */
	write_pin(LCD_CTRL_OUT,RW,LOW);

	/* delay for processing Tas = 50ns */
	_delay_ms(1);

	/* Enable LCD E=1 */
	write_pin(LCD_CTRL_OUT,E,HIGH);

	 /* delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);

	#ifdef	TWO_LINE_LCD_4_BIT_MODE
	#ifdef FIRST_4_PINS

	LCD_DATA_OUT = (LCD_DATA_OUT & ~FIRST_FOUR_PINS) | ((data & ~FIRST_FOUR_PINS) >> 4);

	/* delay for processing Tdsw = 100ns */
	_delay_ms(1);

	/* disable LCD E=0 */
	write_pin(LCD_CTRL_OUT,E,LOW);

	/* delay for processing Th = 13ns */
	_delay_ms(1);

	/* Enable LCD E=1 */
	write_pin(LCD_CTRL_OUT,E,HIGH);

	 /* delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);

	LCD_DATA_OUT = (LCD_DATA_OUT & ~FIRST_FOUR_PINS) | (data & FIRST_FOUR_PINS);

	#endif
	#endif

	#ifdef	TWO_LINE_LCD_4_BIT_MODE
	#ifdef	SECOND_4_PINS
	LCD_DATA_OUT = (LCD_DATA_OUT & ~SECOND_FOUR_PINS) | ((data & SECOND_FOUR_PINS) >> 4);
	/* delay for processing Tdsw = 100ns */
	_delay_ms(1);

	/* disable LCD E=0 */
	write_pin(LCD_CTRL_OUT,E,LOW);

	/* delay for processing Th = 13ns */
	_delay_ms(1);

	/* Enable LCD E=1 */
	write_pin(LCD_CTRL_OUT,E,HIGH);

	 /* delay for processing Tpw - Tdws = 190ns */
	_delay_ms(1);

	LCD_DATA_OUT = (LCD_DATA_OUT & ~SECOND_FOUR_PINS) | ((cmd & ~SECOND_FOUR_PINS) << 4);

	#endif
	#endif

	#ifdef	TWO_LINE_LCD_8_BIT_MODE

	/* out the required command to the data bus D0 --> D7 */
	write_port(LCD_DATA_OUT,data);

	#endif

	/* delay for processing Tdsw = 100ns */
	_delay_ms(1);

	/* disable LCD E=0 */
	write_pin(LCD_CTRL_OUT,E,LOW);

	/* delay for processing Th = 13ns */
	_delay_ms(1);
}

/*****************************************************
*   Function Prototype: void LCD_displayString(const uint8 *str)
*   Description:        Display string.
*   Input:              uint8* refers to string
*   Output:             None
*   return:             void
******************************************************/
void LCD_displayString(const uint8 *str)
{
	uint8 i = 0;

	/* loop to the end of the string */
	while(str[i] != '\0')
	{
		LCD_displayCharacter(str[i]);
		i++;
	}
}

/*****************************************************
*   Function Prototype: void LCD_displayStringRowColumn(uint8 row,uint8 col,const uint8 *str)
*   Description:        Display string at certain row and column.
*   Input:              uint8* refers to string,uint8 refers to row and uint8 refers to column
*   Output:             None
*   return:             void
******************************************************/
void LCD_displayStringRowColumn(uint8 row,uint8 col,const uint8 *str)
{
	/* go to to the required LCD position */
	LCD_goToRowColumn(row,col);

	/* display the string */
	LCD_displayString(str);
}

/*****************************************************
*   Function Prototype: void LCD_goToRowColumn(uint8 row,uint8 col)
*   Description:        Go to a certain row and column.
*   Input:              uint8 refers to row and uint8 refers to column
*   Output:             None
*   return:             void
******************************************************/
void LCD_goToRowColumn(uint8 row,uint8 col)
{
	uint8 Address;

	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
	}
	/*
	 * to write to a specific address in the LCD
	 * we need to apply the corresponding command 0b10000000+Address
	 */
	LCD_sendCommand(Address | SET_CURSOR_LOCATION);
}

/*****************************************************
*   Function Prototype: void LCD_intgerToString(uint8 data)
*   Description:        Converts integer data to string.
*   Input:              uint8 refers to data
*   Output:             None
*   return:             void
******************************************************/
void LCD_intgerToString(uint8 data)
{
	/* String to hold the ascii result */
	uint8 buff[16];

	/* 10 for decimal */
	itoa(data,buff,10);

	/* display converted decimal */
	LCD_displayString(buff);
}

/*****************************************************
*   Function Prototype: void LCD_clearScreen(void)
*   Description:        Clear LCD screen.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void LCD_clearScreen(void)
{
	/* send clear command */
	LCD_sendCommand(CLEAR_COMMAND);
}
