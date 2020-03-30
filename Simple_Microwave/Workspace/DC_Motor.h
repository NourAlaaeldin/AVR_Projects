/*
 * DC_Motor.h
 *
 *  Created on: Sep 29, 2019
 *      Author: Nour
 *     Purpose: contains all DC Motor functions needed in this project
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "standard_library.h"

/*******************************************************************************
 *                      Preprocessor Defines                                   *
 *******************************************************************************/

#define DC_MOTOR_DIR	DDRD_R
#define DC_MOTOR_OUT	PORTD_R

#define IN1				PD0_B
#define IN2				PD1_B

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void DC_Motor_init(void)
*   Description:        Initialization DC motor.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void DC_Motor_init(void);

/*****************************************************
*   Function Prototype: void DC_Motor_rotate_clockwise(void)
*   Description:        Rotate DC motor clockwise.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void DC_Motor_rotate_clockwise(void);

/*****************************************************
*   Function Prototype: void DC_Motor_rotate_anti_clockwise(void)
*   Description:        Rotate DC motor anti_clockwise.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void DC_Motor_rotate_anti_clockwise(void);

/*****************************************************
*   Function Prototype: void DC_Motor_stop(void)
*   Description:        Stop DC motor.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void DC_Motor_stop(void);

#endif /* DC_MOTOR_H_ */
