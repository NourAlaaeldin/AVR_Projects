/*
 * Leds.h
 *
 *  Created on: Mar 20, 2020
 *      Author: Nour
 *     Purpose: contains all leds functions needed in this project
 */

#ifndef LEDS_H_
#define LEDS_H_

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "standard_library.h"

/*******************************************************************************
 *                      Preprocessor Defines                                   *
 *******************************************************************************/

#define LEDS_DIR				DDRB_R
#define LEDS_OUT				PORTB_R
#define LAMP					PB0_B
#define HEATER					PB1_B

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void leds_init(void)
*   Description:        Initialization leds.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void leds_init(void);

#endif /* LEDS_H_ */
