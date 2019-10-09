/*
 * DC_Motor.h
 *
 *  Created on: Sep 29, 2019
 *      Author: Nour
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "standard_library.h"
#include "common_macros.h"
#include "AVR_registers.h"

#define DC_MOTOR_DIR	DDRD_R
#define DC_MOTOR_OUT	PORTD_R

#define IN1				PD2_B
#define IN2				PD3_B

extern void DC_Motor_init(void);
extern void DC_Motor_rotate_clockwise(void);
extern void DC_Motor_rotate_anti_clockwise(void);
extern void DC_Motor_stop(void);

#endif /* DC_MOTOR_H_ */
