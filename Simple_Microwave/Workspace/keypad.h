/*
 * keypad.h
 *
 *  Created on: Sep 16, 2019
 *      Author: Nour
 * 	   Purpose: contains all keypad functions needed in this project
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "standard_library.h"
#include "AVR_registers.h"

/*******************************************************************************
 *                      Preprocessor Defines                                   *
 *******************************************************************************/

#define NO_OF_ROWS			4
#define NO_OF_COLUMNS		4

#define KEYPAD_DIR		DDRA_R
#define KEYPAD_OUT		PORTA_R
#define KEYPAD_IN		PINA_R


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: uint8 Keypad_getPressedKey(void)
*   Description:        Get the value of keypad pressed button.
*   Input:              None
*   Output:             uint8 refers to keypad input number
*   return:             uint8
******************************************************/
extern uint8 Keypad_getPressedKey(void);

#endif /* KEYPAD_H_ */
