/*
 * DC_Motor.c
 *
 *  Created on: Sep 29, 2019
 *      Author: Nour
 */

#include "DC_Motor.h"

void
DC_Motor_init(void)
{
	/* set the output pins */
	SET_BIT(DC_MOTOR_DIR,IN1);
	SET_BIT(DC_MOTOR_DIR,IN2);

    /* DC Motor is stopped initially */
	CLEAR_BIT(DC_MOTOR_OUT,IN1);
	CLEAR_BIT(DC_MOTOR_OUT,IN2);
}

void
DC_Motor_rotate_clockwise(void)
{
	CLEAR_BIT(DC_MOTOR_OUT,IN1);
	SET_BIT(DC_MOTOR_OUT,IN2);
}
void
DC_Motor_rotate_anti_clockwise(void)
{
	SET_BIT(DC_MOTOR_OUT,IN1);
	CLEAR_BIT(DC_MOTOR_OUT,IN2);
}
void
DC_Motor_stop(void)
{
	CLEAR_BIT(DC_MOTOR_OUT,IN1);
	CLEAR_BIT(DC_MOTOR_OUT,IN2);
}
