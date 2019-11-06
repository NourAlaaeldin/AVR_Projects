/*
 * External_Interrupt.h
 *
 *  Created on: Oct 24, 2019
 *      Author: Nour
 */

#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

#include "standard_library.h"
#include "common_macros.h"
#include "AVR_registers.h"
#include <avr/interrupt.h>

typedef enum
{
	interrupt0,interrupt1,interrupt2
}Interrupt;

typedef enum
{
	low,high,falling,rising
}State;

typedef struct
{
	Interrupt interrupt;
	State state;
}Interrupt_ConfigType;

extern void Interrupt_init(Interrupt_ConfigType * Config_Ptr);
extern void Interrupt0_DeInit(void);
extern void Interrupt1_DeInit(void);
extern void Interrupt2_DeInit(void);
extern void Interrupt_setEdgeDetectionType(Interrupt_ConfigType * Config_Ptr,State state);
extern void INT0_setCallBack(void(*a_ptr)(void));
extern void INT1_setCallBack(void(*a_ptr)(void));
extern void INT2_setCallBack(void(*a_ptr)(void));

#endif /* EXTERNAL_INTERRUPT_H_ */
