/*
 * Timer.h
 *
 *  Created on: Sep 28, 2019
 *      Author: Nour
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "standard_library.h"
#include "common_macros.h"
#include "AVR_registers.h"
#include <avr/interrupt.h>

typedef enum
{
	Timer0,Timer1,Timer2
}Timer;

typedef enum
{
	Overflow,CTC = 2
}Mode;

typedef enum
{
	No_clock,No_prescaling,CLK_8,CLK_64,CLK_256,CLK_1024,External_falling,External_rising
}Prescalar_Timer0,Prescalar_Timer1;

typedef enum
{
	no_clock,no_prescaling,CLK__8,CLK__32,CLK__64,CLK__128,CLK__256,CLK__1024
}Prescalar_Timer2;

typedef enum
{
	Normal,Toggle,Clear,Set
}Compare_Output_Mode;

typedef enum
{
	Channel_A,Channel_B
}Channel;

typedef struct
{
	Timer 				timer;
	Mode 				mode;
	Prescalar_Timer0 	prescalar_Timer0;
	Prescalar_Timer1 	prescalar_Timer1;
	Prescalar_Timer2 	prescalar_Timer2;
	Compare_Output_Mode COM;
	uint8				u8_comp_value;
	uint16				u16_comp_value_A;
	uint16				u16_comp_value_B;
	Channel				channel;
}Timer_ConfigType;

extern void Timer_init(Timer_ConfigType * Config_Ptr);
extern void Timer0_OVF_setCallBack(void(*a_ptr)(void));
extern void Timer0_COMP_setCallBack(void(*a_ptr)(void));
extern void Timer2_OVF_setCallBack(void(*a_ptr)(void));
extern void Timer2_COMP_setCallBack(void(*a_ptr)(void));
extern void Timer1_OVF_setCallBack(void(*a_ptr)(void));
extern void Timer1_COMPA_setCallBack(void(*a_ptr)(void));
extern void Timer1_COMPB_setCallBack(void(*a_ptr)(void));

#endif /* TIMER_H_ */
