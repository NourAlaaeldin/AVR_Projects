/*
 * DC_Motor.c
 *
 *  Created on: Sep 29, 2019
 *      Author: Nour
 *     Purpose: contains all DC Motor functions needed in this project
 */

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "DC_Motor.h"
#include "Port.h"
#include "DIO.h"

/*******************************************************************************
 *                      Function Definitions                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void DC_Motor_init(void)
*   Description:        Initialization DC motor.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void DC_Motor_init(void)
{
	/* set output pins */
	set_direction(DC_MOTOR_DIR,IN1,OUT);
	set_direction(DC_MOTOR_DIR,IN2,OUT);

	/* set default value of output is low */
	write_pin(DC_MOTOR_OUT,IN1,LOW);
	write_pin(DC_MOTOR_OUT,IN2,LOW);
}

/*****************************************************
*   Function Prototype: void DC_Motor_rotate_clockwise(void)
*   Description:        Rotate DC motor clockwise.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void DC_Motor_rotate_clockwise(void)
{
	/* set IN1 low */
	write_pin(DC_MOTOR_OUT,IN1,LOW);

	/* set IN2 high */
	write_pin(DC_MOTOR_OUT,IN2,HIGH);
}

/*****************************************************
*   Function Prototype: void DC_Motor_rotate_anti_clockwise(void)
*   Description:        Rotate DC motor anti_clockwise.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void DC_Motor_rotate_anti_clockwise(void)
{
	/* set IN1 high */
	write_pin(DC_MOTOR_OUT,IN1,HIGH);

	/* set IN2 low */
	write_pin(DC_MOTOR_OUT,IN2,LOW);
}

/*****************************************************
*   Function Prototype: void DC_Motor_stop(void)
*   Description:        Stop DC motor.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void DC_Motor_stop(void)
{
	/* set value of output is low */
	write_pin(DC_MOTOR_OUT,IN1,LOW);
	write_pin(DC_MOTOR_OUT,IN2,LOW);
}
