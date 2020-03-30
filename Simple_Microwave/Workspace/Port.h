/*
 * Port.h
 *
 *  Created on: Mar 20, 2020
 *      Author: Nour
 *     Purpose: contains all port functions needed in this project
 */

#ifndef PORT_H_
#define PORT_H_

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "common_macros.h"
#include "standard_library.h"
#include "AVR_registers.h"

/*******************************************************************************
 *                      Preprocessor Defines                                   *
 *******************************************************************************/

#define FIRST_FOUR_PINS					0x0F
#define SECOND_FOUR_PINS				0xF0

/*******************************************************************************
 *                      Functions-Like Macros                                  *
 *******************************************************************************/

/*****************************************************
*   Macro: 				set_direction(port,pin,direction)
*   Description:        set the direction of a pin.
*   Input:              port, pin and direction: output or input
*   Output:             None
******************************************************/
#define set_direction(port,pin,direction)\
{\
	if(direction == OUT)\
		SET_BIT(port,pin);\
	else if(direction == IN)\
		CLEAR_BIT(port,pin);\
}

/*****************************************************
*   Macro: 				set_direction_group(port,group,direction)
*   Description:        set the direction of a group.
*   Input:              port, group and direction: output or input
*   Output:             None
******************************************************/
#define set_direction_group(port,group,direction)\
{\
	if(direction == OUT)\
		port |= group;\
	else if(direction == IN)\
		port &= ~group;\
}

/*****************************************************
*   Macro: 				set_direction_port(port,direction)
*   Description:        set the direction of a port.
*   Input:              port and direction: output or input
*   Output:             None
******************************************************/
#define set_direction_port(port,direction)\
{\
	if(direction == OUT)\
		port = 0xFF;\
	else if(direction == IN)\
		port = 0;\
}

#endif /* PORT_H_ */
