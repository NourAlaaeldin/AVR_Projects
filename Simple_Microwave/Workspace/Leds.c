/*
 * Leds.c
 *
 *  Created on: Mar 21, 2020
 *      Author: Nour
 *     Purpose: contains all leds functions needed in this project
 */

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "Leds.h"
#include "Port.h"
#include "DIO.h"

/*******************************************************************************
 *                      Function Definitions                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void leds_init(void)
*   Description:        Initialization leds.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void leds_init(void)
{
	/* initialize lamp and heater as outputs */
	set_direction(LEDS_DIR,LAMP,OUT);
	set_direction(LEDS_DIR,HEATER,OUT);

	/* initial value of lamp and heater is low */
	write_pin(LEDS_OUT,LAMP,LOW);
	write_pin(LEDS_OUT,HEATER,LOW);
}
