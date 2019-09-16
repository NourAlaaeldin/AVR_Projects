/*
 * seven_segment.h
 *
 *  Created on: Sep 16, 2019
 *      Author: Nour
 * Description: Header file for the seven_segment driver
 */

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "AVR_registers.h"
#include "standard_library.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Preprocessor Defines                                   *
 *******************************************************************************/

#define SEVEN_SEGMENT_DIR	DDRC_R
#define SEVEN_SEGMENT_OUT	PORTC_R

#define FIRST_4_PINS

#ifdef	FIRST_4_PINS
#define FIRST_FOUR_PINS		0x0F
#endif

#ifdef	SECOND_FOUR_PINS
#define SECOND_FOUR_PINS	0xF0
#endif

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

extern void seven_segment_init(void);

#endif /* SEVEN_SEGMENT_H_ */
