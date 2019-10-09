/*
 * MC2.c
 *
 *  Created on: Oct 8, 2019
 *      Author: Nour
 */

#include "UART.h"
#include "EEPROM_external.h"
#include "DC_Motor.h"
#include "Timer.h"
#include "delay.h"

/* compare value for timer1 */
#define _1_M_SEC					(uint16)7999

/* UART ready status */
#define READY						(uint8)0x01

#define ARRAY_SIZE					(uint8)16

#define ACTIVATE_BUZZER				(uint8)0xFF

#define DELAY_TIME					100

#define BUZZER_TIME					60

#define MOTOR_TIME					15

/* A function that gathers all initializations */
void init_all(void);

int
main(void)
{
	uint8 password[ARRAY_SIZE] = {LOW};
	uint8 count = LOW;

	/* variable to store received value */
	uint8 dummy;

	/* address of EEPROM */
	uint16 Adress = 0x0001;

	init_all();

	do
	{
		dummy = UART_recieveByte();
		if(dummy != LOW)
		{
			password[count] = dummy;
			EEPROM_external_write_byte(Adress,password[count]);
			count++;
		}
	}
	while(dummy != LOW);

	while(TRUE)
	{

		dummy = UART_recieveByte();
		delay_ms(DELAY_TIME);

		/* rotate the motor */
		if(dummy == 43)
		{
			DC_Motor_rotate_clockwise();
			delay_s(MOTOR_TIME);
			DC_Motor_rotate_anti_clockwise();
			delay_s(MOTOR_TIME);
			DC_Motor_stop();
		}
		/* save the changed password */
		else if(dummy == 45)
		{
			do
			{
				dummy = UART_recieveByte();
				if(dummy != LOW)
				{
					password[count] = dummy;
					EEPROM_external_write_byte(Adress,password[count]);
					count++;
				}
			}
			while(dummy != LOW);
		}
		/* activate the buzzer */
		else if(dummy == ACTIVATE_BUZZER)
		{
			SET_BIT(PORTC_R,PC4_B);
			delay_s(BUZZER_TIME);
			CLEAR_BIT(PORTC_R,PC4_B);
		}
	}
}

void
init_all(void)
{

	/* UART configuration */
	UART_ConfigType UART_Config = {Disabled,_1_bit,_8_bit};

	/* Timer 1 is configured to operate for 1 secs */
	Timer_ConfigType Timer_Config = {Timer1,CTC,0,no_prescaling,0,0,0,_1_M_SEC,0,Channel_A};

	/* DC_Motor initialization */
	DC_Motor_init();

	/* EEPROM_external initialization */
	EEPROM_external_init();

	/* UART initialization */
	UART_init(&UART_Config);

	/* Timer initialization */
	Timer_init(&Timer_Config);

	/* Buzzer initialization */
	SET_BIT(DDRC_R,PC4_B);
	CLEAR_BIT(PORTC_R,PC4_B);
}
