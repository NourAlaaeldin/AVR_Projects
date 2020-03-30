/*
 * DIO.h
 *
 *  Created on: Mar 20, 2020
 *      Author: Nour
 *     Purpose: contains all DIO functions needed in this project
 */

#ifndef DIO_H_
#define DIO_H_

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
*   Macro: 				write_pin(port,pin,value)
*   Description:        Write output to a certain pin.
*   Input:              port, pin and value: high or low
*   Output:             None
******************************************************/
#define write_pin(port,pin,value)\
{\
	if(value == HIGH)\
			SET_BIT(port,pin);\
	else if(value == LOW)\
			CLEAR_BIT(port,pin);\
}

/*****************************************************
*   Macro: 				write_port(port,value)
*   Description:        Write output to a port.
*   Input:              port and value: high or low
*   Output:             None
******************************************************/
#define write_port(port,value)\
{\
	port = value;\
}

/*****************************************************
*   Macro: 				write_group(port,group,value)
*   Description:        Write output to a group.
*   Input:              port, group and value: high or low
*   Output:             None
******************************************************/
#define write_group(port,group,value)\
{\
	if(value == HIGH)\
		port |= group;\
	else if(value == LOW)\
		port &= ~group;\
}

/*****************************************************
*   Macro: 				read_pin(port,pin)
*   Description:        Read input from a pin.
*   Input:              port and pin
*   Output:             value of the pin
******************************************************/
#define read_pin(port,pin)\
	(BIT_IS_SET(port,pin))\

#endif /* DIO_H_ */
