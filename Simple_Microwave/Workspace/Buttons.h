/*
 * Buttons.h
 *
 *  Created on: Mar 21, 2020
 *      Author: Nour
 *     Purpose: contains all buttons functions needed in this project
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "standard_library.h"

/*******************************************************************************
 *                      Preprocessor Defines                                   *
 *******************************************************************************/

#define START_BUTTON_DIR				DDRB_R
#define START_BUTTON_IN					PINB_R
#define START_BUTTON					PB3_B

/*******************************************************************************
 *                      Extern Module Shared Global Variables                  *
 *******************************************************************************/

extern volatile uint8 weight_sensor_flag;
extern volatile uint8 door_sensor_flag;
extern volatile uint8 cancel_button_flag;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void buttons_init(void)
*   Description:        Initialization buttons.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void buttons_init(void);

#endif /* BUTTONS_H_ */
