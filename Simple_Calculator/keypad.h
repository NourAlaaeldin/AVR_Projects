/*
 * keypad.h
 *
 *  Created on: Sep 16, 2019
 *      Author: Nour
 * Description: Header file for the Keypad driver
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "AVR_registers.h"
#include "standard_library.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Preprocessor Defines                                   *
 *******************************************************************************/

#define NO_OF_ROWS		4
#define NO_OF_COLUMNS		4

#define KEYPAD_DIR		DDRA_R
#define KEYPAD_OUT		PORTA_R
#define KEYPAD_IN		PINA_R


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

extern uint8 Keypad_getPressedKey(void);

#endif /* KEYPAD_H_ */
