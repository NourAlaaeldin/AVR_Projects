/*
 * Buttons.c
 *
 *  Created on: Mar 21, 2020
 *      Author: Nour
 *     Purpose: contains all buttons functions needed in this project
 */

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "Buttons.h"
#include "Port.h"
#include "DIO.h"
#include "External_Interrupt.h"
#include "LCD.h"

/*******************************************************************************
 *                      Global Variables                                 	   *
 *******************************************************************************/

volatile uint8 weight_sensor_flag =	LOW;
volatile uint8 door_sensor_flag   =	LOW;
volatile uint8 cancel_button_flag =	LOW;

/*******************************************************************************
 *                      Private Functions Prototypes                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void weight_sensor_API(void)
*   Description:        Function called when external interrupt corresponding to weight sensor initiated.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
static void weight_sensor_API(void);

/*****************************************************
*   Function Prototype: void door_sensor_API(void)
*   Description:        Function called when external interrupt corresponding to door sensor initiated.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
static void door_sensor_API(void);

/*****************************************************
*   Function Prototype: void cancel_button_API(void)
*   Description:        Function called when external interrupt corresponding to cancel button initiated.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
static void cancel_button_API(void);

/*******************************************************************************
 *                      Function Definitions                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void buttons_init(void)
*   Description:        Initialization buttons.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void buttons_init(void)
{
	/* initialize start button as input */
	set_direction(START_BUTTON_DIR,START_BUTTON,IN);

	/* set interrupt configuration structures */
	Interrupt_ConfigType weight_sensor 	= {interrupt0,rising};
	Interrupt_ConfigType door_sensor 	= {interrupt1,rising};
	Interrupt_ConfigType cancel_button 	= {interrupt2,rising};

	/* initialize the interrupts */
	Interrupt_init(&weight_sensor);
	Interrupt_init(&door_sensor);
	Interrupt_init(&cancel_button);

	/* set call back functions for external interrupts */
	INT0_setCallBack(weight_sensor_API);
	INT1_setCallBack(door_sensor_API);
	INT2_setCallBack(cancel_button_API);
}

/*****************************************************
*   Function Prototype: void weight_sensor_API(void)
*   Description:        Function called when external interrupt corresponding to weight sensor initiated.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
static void weight_sensor_API(void)
{
	/* raise weight sensor flag */
	weight_sensor_flag = HIGH;
}

/*****************************************************
*   Function Prototype: void door_sensor_API(void)
*   Description:        Function called when external interrupt corresponding to door sensor initiated.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
static void door_sensor_API(void)
{
	/* raise door sensor flag */
	door_sensor_flag = HIGH;
}

/*****************************************************
*   Function Prototype: void cancel_button_API(void)
*   Description:        Function called when external interrupt corresponding to cancel button initiated.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
static void cancel_button_API(void)
{
	/* raise cancel button flag */
	cancel_button_flag = HIGH;
}
