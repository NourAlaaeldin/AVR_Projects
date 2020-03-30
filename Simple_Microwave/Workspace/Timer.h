/*
 * Timer.h
 *
 *  Created on: Sep 28, 2019
 *      Author: Nour
 *     Purpose: contains all timer functions needed in this project
 */

#ifndef TIMER_H_
#define TIMER_H_

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
	no_interrupt,interrupt
}interrupt_state;

typedef enum
{
	Channel_A,Channel_B
}Channel;

/*******************************************************************************
 *                      Structures                                 			   *
 *******************************************************************************/

/*****************************************************
*   Structure Name: 	Timer_ConfigType
*   Description:        This structure is responsible for dynamic configuration of timer module.
******************************************************/
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
	interrupt_state     state;
}Timer_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void Timer_init(Timer_ConfigType * Config_Ptr)
*   Description:        Initialization timers.
*   Input:              Timer_ConfigType represents pointer to timer configuration structure
*   Output:             None
*   return:             void
******************************************************/
extern void Timer_init(Timer_ConfigType * Config_Ptr);

/*****************************************************
*   Function Prototype: void Timer0_DeInit(void)
*   Description:        De-initialize timer0.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer0_DeInit(void);

/*****************************************************
*   Function Prototype: void Timer1_DeInit(void)
*   Description:        De-initialize timer1.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer1_DeInit(void);

/*****************************************************
*   Function Prototype: void Timer2_DeInit(void)
*   Description:        De-initialize timer2.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer2_DeInit(void);

/*****************************************************
*   Function Prototype: void Timer0_clearTimerValue(void)
*   Description:        clear timer0 value.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer0_clearTimerValue(void);

/*****************************************************
*   Function Prototype: void Timer1_clearTimerValue(void)
*   Description:        clear timer1 value.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer1_clearTimerValue(void);

/*****************************************************
*   Function Prototype: void Timer2_clearTimerValue(void)
*   Description:        clear timer2 value.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer2_clearTimerValue(void);

/*****************************************************
*   Function Prototype: uint8 Timer0_getTimerValue(void)
*   Description:        get timer0 value.
*   Input:              None
*   Output:             uint8 represents timer0 value
*   return:             uint8
******************************************************/
extern uint8 Timer0_getTimerValue(void);

/*****************************************************
*   Function Prototype: uint16 Timer1_getTimerValue(void)
*   Description:        get timer1 value.
*   Input:              None
*   Output:             uint16 represents timer1 value
*   return:             uint16
******************************************************/
extern uint16 Timer1_getTimerValue(void);

/*****************************************************
*   Function Prototype: uint8 Timer2_getTimerValue(void)
*   Description:        get timer2 value.
*   Input:              None
*   Output:             uint8 represents timer2 value
*   return:             uint8
******************************************************/
extern uint8 Timer2_getTimerValue(void);

/*****************************************************
*   Function Prototype: void Timer0_OVF_setInterrupt(void)
*   Description:        set interrupt for timer0 overflow mode.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer0_OVF_setInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer0_COMP_setInterrupt(void)
*   Description:        set interrupt for timer0 CTC mode.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer0_COMP_setInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer1_OVF_setInterrupt(void)
*   Description:        set interrupt for timer1 overflow mode.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer1_OVF_setInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer1_COMPA_setInterrupt(void)
*   Description:        set interrupt for timer1 CTC mode channelA.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer1_COMPA_setInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer1_COMPB_setInterrupt(void)
*   Description:        set interrupt for timer1 CTC mode channelB.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer1_COMPB_setInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer2_OVF_setInterrupt(void)
*   Description:        set interrupt for timer2 overflow mode.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer2_OVF_setInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer2_COMP_setInterrupt(void)
*   Description:        set interrupt for timer2 CTC mode.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer2_COMP_setInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer0_OVF_clearInterrupt(void)
*   Description:        clear interrupt for timer0 overflow mode.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer0_OVF_clearInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer0_COMP_clearInterrupt(void)
*   Description:        clear interrupt for timer0 CTC mode.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer0_COMP_clearInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer1_OVF_clearInterrupt(void)
*   Description:        clear interrupt for timer1 overflow mode.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer1_OVF_clearInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer1_COMPA_clearInterrupt(void)
*   Description:        clear interrupt for timer1 CTC mode channelA.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer1_COMPA_clearInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer1_COMPB_clearInterrupt(void)
*   Description:        clear interrupt for timer1 CTC mode channelB.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer1_COMPB_clearInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer2_OVF_clearInterrupt(void)
*   Description:        clear interrupt for timer2 overflow mode.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer2_OVF_clearInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer2_COMP_clearInterrupt(void)
*   Description:        clear interrupt for timer2 CTC mode.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
extern void Timer2_COMP_clearInterrupt(void);

/*****************************************************
*   Function Prototype: void Timer0_OVF_setCallBack(void(*a_ptr)(void))
*   Description:        call back function when timer0 overflow interrupt is initiated.
*   Input:              void(*a_ptr)(void) refers to function called by the call-back function in upper layer
*   Output:             None
*   return:             void
******************************************************/
extern void Timer0_OVF_setCallBack(void(*a_ptr)(void));

/*****************************************************
*   Function Prototype: void Timer0_COMP_setCallBack(void(*a_ptr)(void))
*   Description:        call back function when timer0 CTC interrupt is initiated.
*   Input:              void(*a_ptr)(void) refers to function called by the call-back function in upper layer
*   Output:             None
*   return:             void
******************************************************/
extern void Timer0_COMP_setCallBack(void(*a_ptr)(void));

/*****************************************************
*   Function Prototype: void Timer1_OVF_setCallBack(void(*a_ptr)(void))
*   Description:        call back function when timer1 overflow interrupt is initiated.
*   Input:              void(*a_ptr)(void) refers to function called by the call-back function in upper layer
*   Output:             None
*   return:             void
******************************************************/
extern void Timer1_OVF_setCallBack(void(*a_ptr)(void));

/*****************************************************
*   Function Prototype: void Timer1_COMPA_setCallBack(void(*a_ptr)(void))
*   Description:        call back function when timer1 channelA CTC interrupt is initiated.
*   Input:              void(*a_ptr)(void) refers to function called by the call-back function in upper layer
*   Output:             None
*   return:             void
******************************************************/
extern void Timer1_COMPA_setCallBack(void(*a_ptr)(void));

/*****************************************************
*   Function Prototype: void Timer1_COMPB_setCallBack(void(*a_ptr)(void))
*   Description:        call back function when timer1 channelB CTC interrupt is initiated.
*   Input:              void(*a_ptr)(void) refers to function called by the call-back function in upper layer
*   Output:             None
*   return:             void
******************************************************/
extern void Timer1_COMPB_setCallBack(void(*a_ptr)(void));

/*****************************************************
*   Function Prototype: void Timer2_OVF_setCallBack(void(*a_ptr)(void))
*   Description:        call back function when timer2 overflow interrupt is initiated.
*   Input:              void(*a_ptr)(void) refers to function called by the call-back function in upper layer
*   Output:             None
*   return:             void
******************************************************/
extern void Timer2_OVF_setCallBack(void(*a_ptr)(void));

/*****************************************************
*   Function Prototype: void Timer2_COMP_setCallBack(void(*a_ptr)(void))
*   Description:        call back function when timer2 CTC interrupt is initiated.
*   Input:              void(*a_ptr)(void) refers to function called by the call-back function in upper layer
*   Output:             None
*   return:             void
******************************************************/
extern void Timer2_COMP_setCallBack(void(*a_ptr)(void));

#endif /* TIMER_H_ */
