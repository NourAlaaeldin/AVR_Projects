/*
 * External_Interrupt.h
 *
 *  Created on: Oct 24, 2019
 *      Author: Nour
 *     Purpose: contains all external interrupt functions needed in this project
 */

#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "common_macros.h"
#include "standard_library.h"
#include "AVR_registers.h"
#include <avr/interrupt.h>

/*******************************************************************************
 *                      ENUMS                                 			       *
 *******************************************************************************/

typedef enum
{
	interrupt0,interrupt1,interrupt2
}Interrupt;

typedef enum
{
	low,high,falling,rising
}State;

/*******************************************************************************
 *                      Structures                                 			   *
 *******************************************************************************/

/*****************************************************
*   Structure Name: 	Interrupt_ConfigType
*   Description:        This structure is responsible for dynamic configuration of external interrupt module.
******************************************************/
typedef struct
{
	Interrupt interrupt;
	State state;
}Interrupt_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void Interrupt_init(Interrupt_ConfigType * Config_Ptr);
*   Description:        Initialization external interrupts.
*   Input:              Interrupt_ConfigType represents pointer to interrupt configuration structure
*   Output:             None
*   return:             void
******************************************************/
extern void Interrupt_init(Interrupt_ConfigType * Config_Ptr);

/*****************************************************
*   Function Prototype: void Interrupt0_DeInit(void)
*   Description:        De-initialize interrupt0.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Interrupt0_DeInit(void);

/*****************************************************
*   Function Prototype: void Interrupt1_DeInit(void)
*   Description:        De-initialize interrupt1.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Interrupt1_DeInit(void);

/*****************************************************
*   Function Prototype: void Interrupt2_DeInit(void)
*   Description:        De-initialize interrupt2.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Interrupt2_DeInit(void);

/*****************************************************
*   Function Prototype: void Interrupt0_setEdgeDetectionType(State state)
*   Description:        set edge of external interrupt0.
*   Input:              State refers to rising or falling edge
*   Output:             None
*   return:             void
******************************************************/
extern void Interrupt0_setEdgeDetectionType(State state);

/*****************************************************
*   Function Prototype: void Interrupt1_setEdgeDetectionType(State state)
*   Description:        set edge of external interrupt1.
*   Input:              State refers to rising or falling edge
*   Output:             None
*   return:             void
******************************************************/
extern void Interrupt1_setEdgeDetectionType(State state);

/*****************************************************
*   Function Prototype: void Interrupt2_setEdgeDetectionType(State state)
*   Description:        set edge of external interrupt2.
*   Input:              State refers to rising or falling edge
*   Output:             None
*   return:             void
******************************************************/
extern void Interrupt2_setEdgeDetectionType(State state);

/*****************************************************
*   Function Prototype: void INT0_setCallBack(void(*a_ptr)(void))
*   Description:        call back function when interrupt0 is initiated.
*   Input:              void(*a_ptr)(void) refers to function called by the call-back function in upper layer
*   Output:             None
*   return:             void
******************************************************/
extern void INT0_setCallBack(void(*a_ptr)(void));

/*****************************************************
*   Function Prototype: void INT1_setCallBack(void(*a_ptr)(void))
*   Description:        call back function when interrupt1 is initiated.
*   Input:              void(*a_ptr)(void) refers to function called by the call-back function in upper layer
*   Output:             None
*   return:             void
******************************************************/
extern void INT1_setCallBack(void(*a_ptr)(void));

/*****************************************************
*   Function Prototype: void INT2_setCallBack(void(*a_ptr)(void))
*   Description:        call back function when interrupt2 is initiated.
*   Input:              void(*a_ptr)(void) refers to function called by the call-back function in upper layer
*   Output:             None
*   return:             void
******************************************************/
extern void INT2_setCallBack(void(*a_ptr)(void));

#endif /* EXTERNAL_INTERRUPT_H_ */
