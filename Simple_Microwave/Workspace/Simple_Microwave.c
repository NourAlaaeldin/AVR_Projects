/*
 * Simple_Microwave.c
 *
 *  Created on: Mar 19, 2020
 *      Author: Nour
 */

/*******************************************************************************
 *                      Includes                                 			   *
 *******************************************************************************/

#include "LCD.h"
#include "keypad.h"
#include "Buttons.h"
#include "Leds.h"
#include "DC_Motor.h"
#include "DIO.h"
#include "Timer.h"
#include <util/delay.h>

/*******************************************************************************
 *                      Preprocessor Defines                                   *
 *******************************************************************************/

/* default display on LCD */
#define DEFAULT_DISPLAY		"00:00"

/*******************************************************************************
 *                      ENUMS                                 			       *
 *******************************************************************************/

typedef enum
{
	operate,stop
}
State;

/*******************************************************************************
 *                      Global Variables                                 	   *
 *******************************************************************************/

/* default state is stop state */
State state = stop;

/* time variables */
uint8 time_in_seconds;
uint8 time_in_minutes;

uint8 flag_1 = HIGH;
uint8 flag_2 = HIGH;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void Timer_App(void)
*   Description:        Call back function called by timer interrupt.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void Timer_App(void);

/*****************************************************
*   Function Prototype: void init_all(void)
*   Description:        Initialize all.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void init_all(void);

/*****************************************************
*   Function Prototype: void operate_all(void)
*   Description:        Operation state.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void operate_all(void);

/*****************************************************
*   Function Prototype: void stop_all(void)
*   Description:        Stop state.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void stop_all(void);

/*****************************************************
*   Function Prototype: void set_time(void)
*   Description:        Set the time of the microwave.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void set_time(void);

/*******************************************************************************
 *                      Function Definitions                                   *
 *******************************************************************************/

/*****************************************************
*   Function Prototype: void Timer_App(void)
*   Description:        Call back function called by timer interrupt.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void Timer_App(void)
{
	/* decrement the value of time in seconds */
	time_in_seconds--;

	if(time_in_seconds >= 10)
	{
		/* display the value of time in certain position */
		LCD_goToRowColumn(0,3);
		LCD_intgerToString(time_in_seconds);
	}
	else
	{
		/* display the value of time in certain position */
		LCD_goToRowColumn(0,3);
		LCD_intgerToString(0);

		/* display the value of time in certain position */
		LCD_goToRowColumn(0,4);
		LCD_intgerToString(time_in_seconds);
	}
	if(time_in_seconds == 0)
	{
		/* check if the user entered time in minutes */
		if(time_in_minutes != 0)
		{
			/* decrement the value of time in minutes */
			time_in_minutes--;

			/* convert minutes to seconds */
			time_in_seconds = 60;

			if(time_in_minutes >= 10)
			{
				/* display the value of time in certain position */
				LCD_goToRowColumn(0,0);
				LCD_intgerToString(time_in_minutes);
			}
			else
			{
				/* display the value of time in certain position */
				LCD_goToRowColumn(0,0);
				LCD_intgerToString(0);

				/* display the value of time in certain position */
				LCD_goToRowColumn(0,1);
				LCD_intgerToString(time_in_minutes);
			}
		}
		/* reach here when time in seconds and minutes equal 0 */
		else
		{
			/*
			 * clear weight sensor when operation finish
			 * clear door sensor flags when operation finish
			 * set flag to high when operation finish
			 */
			weight_sensor_flag 	= 	LOW;
			door_sensor_flag   	= 	LOW;
			flag_1 				= 	HIGH;

			/* go to stop state */
			state 				= 	stop;
		}
	}
}

/*****************************************************
*   Function Prototype: void init_all(void)
*   Description:        Initialize all.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void init_all(void)
{
	/* set global interrupt */
	SET_BIT(SREG_R,I_B);

	/* set initializations */
	LCD_init();
	leds_init();
	buttons_init();
	DC_Motor_init();
}

/*****************************************************
*   Function Prototype: void operate_all(void)
*   Description:        Operation state.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void operate_all(void)
{
	/*
	 * 	turn on heater
	 * 	turn on lamp
	 * 	operate motor
	 * 	operate timer
	 */
	write_pin(LEDS_OUT,HEATER,HIGH);
	write_pin(LEDS_OUT,LAMP,HIGH);
	DC_Motor_rotate_clockwise();
	Timer1_COMPA_setInterrupt();
}

/*****************************************************
*   Function Prototype: void stop_all(void)
*   Description:        Stop state.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void stop_all(void)
{
	/*
	 * turn off heater
	 * turn off lamp
	 * stop motor
	 * stop timer
	 */
	write_pin(LEDS_OUT,HEATER,LOW);
	write_pin(LEDS_OUT,LAMP,LOW);
	DC_Motor_stop();
	Timer1_COMPA_clearInterrupt();

	/* check if weight sensor and door sensor are high again to go to operate state */
	if(weight_sensor_flag == HIGH && door_sensor_flag == HIGH)
	{
		/*
		 * clear cancel button when operation state detected
		 * set flag to high when operation state detected
		 */
		cancel_button_flag 	= 	LOW;
		flag_2 				= 	HIGH;
	}
}

/*****************************************************
*   Function Prototype: void set_time(void)
*   Description:        Set the time of the microwave.
*   Input:              None
*   Output:             None
*   return:             void
******************************************************/
void set_time(void)
{
	/* keypad variables */
	uint8 keypad;
	uint8 keypad_input[4] = {0};

	/* variable i refers to counter */
	uint8 i = 0;

	/* 13 refers to on key, must be pressed to terminate set time function */
	while(keypad != 13)
	{
		/* get input key from keypad */
		keypad = Keypad_getPressedKey();

		/* wait for half a second */
		_delay_ms(500);

		if(keypad != 13)
		{
			/* save the keypad input in keypad_input array */
			keypad_input[i] = keypad;

			if(i < 2)
			{
				/* display entered value in certain position */
				LCD_goToRowColumn(0,i+3);
				LCD_intgerToString(keypad_input[i]);
			}
			else if(i == 2)
			{
				/* display ':' in certain position */
				LCD_goToRowColumn(0,i);
				LCD_displayCharacter(':');

				/* display entered value in certain position */
				LCD_goToRowColumn(0,i-2);
				LCD_intgerToString(keypad_input[i]);
			}
			else if(i > 2)
			{
				/* display entered value in certain position */
				LCD_goToRowColumn(0,i-2);
				LCD_intgerToString(keypad_input[i]);
			}
			i++;
		}
	}
	/* calculate time in seconds and time in minutes */
	time_in_seconds = keypad_input[0] * 10 + keypad_input[1];
	time_in_minutes = keypad_input[2] * 10 + keypad_input[3];
}

int main(void)
{
	/* call init_all function */
	init_all();

	/* display 00:00 as default */
	LCD_displayString(DEFAULT_DISPLAY);

	/* configure the timer to interrupt every 1 sec */
	Timer_ConfigType Config_struct = {Timer1,CTC,0,CLK_1024,0,0,0,1000,0,Channel_A,0};

	/* initialize the timer */
	Timer_init(&Config_struct);

	/* set the callback function */
	Timer1_COMPA_setCallBack(Timer_App);

	while(TRUE)
	{
		/*
		 * check if food is in microwave
		 * check if door is closed
		 * set time
		 * check if start button is pressed
		 * go to operate state
		 */
		if(	weight_sensor_flag == HIGH && door_sensor_flag == HIGH)
		{
			/* we want to set time only once */
			if(flag_1 == HIGH)
			{
				set_time();
				flag_1 = LOW;
			}
			if(read_pin(START_BUTTON_IN,START_BUTTON))
			{
				state = operate;
			}
		}

		/*
		 * check if cancel button is pressed
		 * go to stop state
		 */
		if(cancel_button_flag == HIGH)
		{
			/* we want to go to stop state only once */
			if(flag_2 == HIGH)
			{
				flag_2 = LOW;

				/* clear LCD screen */
				LCD_clearScreen();

				/* display 00:00 as default */
				LCD_displayString(DEFAULT_DISPLAY);

				/*
				 * clear weight sensor when operation finish
				 * clear door sensor flags when operation finish
				 * set flag to high when operation finish
				 */
				weight_sensor_flag 	= 	LOW;
				door_sensor_flag   	= 	LOW;
				flag_1 				= 	HIGH;

				/* go to stop state */
				state 				= 	stop;
			}
		}

		switch(state)
		{
		case operate:
			operate_all();
			break;
		case stop:
			stop_all();
			break;
		}
	}
}
