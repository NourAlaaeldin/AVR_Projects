/*
 * keypad.c
 *
 *  Created on: Sep 16, 2019
 *      Author: Nour
 *     Purpose: contains all keypad functions needed in this project
 */

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/
#include "keypad.h"
#include "DIO.h"

/*******************************************************************************
 *                      Private Functions Prototypes                                   *
 *******************************************************************************/

#if(NO_OF_COLUMNS == 3)
/*****************************************************
*   Function Prototype: uint8 KeyPad_4x3_adjustKeyNumber(uint8 button_number)
*   Description:        Adjust button number of 4x3 keypad.
*   Input:              uint8 refers to keypad input number
*   Output:             uint8 refers to adjusted value
*   return:             uint8
******************************************************/
static uint8 KeyPad_4x3_adjustKeyNumber(uint8 button_number);
#elif(NO_OF_COLUMNS == 4)
/*****************************************************
*   Function Prototype: uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number)
*   Description:        Adjust button number of 4x4 keypad.
*   Input:              uint8 refers to keypad input number
*   Output:             uint8 refers to adjusted value
*   return:             uint8
******************************************************/
static uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number);
#endif

/*******************************************************************************
 *                      Function Definitions                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: uint8 Keypad_getPressedKey(void)
*   Description:        get the value of keypad pressed button.
*   Input:              None
*   Output:             uint8 refers to keypad input number
*   return:             uint8
******************************************************/
uint8 Keypad_getPressedKey(void)
{
	uint8 col,row;
	while(TRUE)
	{
		for(col = LOW;col < NO_OF_COLUMNS;col++)
		{
			KEYPAD_DIR = 0b00010000 << col;
			KEYPAD_OUT = ~(0b00010000 << col);

			for(row = LOW;row < NO_OF_ROWS;row++)
			{
				if(!(read_pin(KEYPAD_IN,row)))
				{
					#if(NO_OF_COLUMNS == 3)
						return KeyPad_4x3_adjustKeyNumber((row * NO_OF_COLUMNS) + col + 1);
					#elif(NO_OF_COLUMNS == 4)
						return KeyPad_4x4_adjustKeyNumber((row * NO_OF_COLUMNS) + col + 1);
					#endif
				}
			}
		}
	}
}

#if(NO_OF_COLUMNS == 3)
/*****************************************************
*   Function Prototype: uint8 KeyPad_4x3_adjustKeyNumber(uint8 button_number)
*   Description:        Adjust button number of 4x3 keypad.
*   Input:              uint8 refers to keypad input number
*   Output:             uint8 refers to adjusted value
*   return:             uint8
******************************************************/
static uint8 KeyPad_4x3_adjustKeyNumber(uint8 button_number)
{
	switch (button_number)
	{
	case 10:
		return '*';
		break;
	case 11:
		return 0;
		break;
	case 12:
		return '#';
		break;
	default:
		return button_number;
		break;
	}
}

#elif(NO_OF_COLUMNS == 4)
/*****************************************************
*   Function Prototype: uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number)
*   Description:        Adjust button number of 4x4 keypad.
*   Input:              uint8 refers to keypad input number
*   Output:             uint8 refers to adjusted value
*   return:             uint8
******************************************************/
static uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number)
{
	switch(button_number)
	{
	case 1:
		return 7;
		break;
	case 2:
		return 8;
		break;
	case 3:
		return 9;
		break;
	case 4:
		return '/';
		break;
	case 5:
		return 4;
		break;
	case 6:
		return 5;
		break;
	case 7:
		return 6;
		break;
	case 8:
		return '*';
		break;
	case 9:
		return 1;
		break;
	case 10:
		return 2;
		break;
	case 11:
		return 3;
		break;
	case 12:
		return '-';
		break;
	case 14:
		return 0;
		break;
	case 15:
		return '=';
		break;
	case 16:
		return '+';
		break;
	default:
		return button_number;
		break;
	}
}

#endif
