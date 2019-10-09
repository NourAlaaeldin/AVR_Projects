/*
 * MC1.c
 *
 *  Created on: Oct 7, 2019
 *      Author: Nour
 */

#include "LCD.h"
#include "UART.h"
#include "Timer.h"
#include "keypad.h"
#include "delay.h"

/* compare value for timer1 */
#define _1_M_SEC					(uint16)7999

/* UART ready status */
#define READY						(uint8)0x01

#define ARRAY_SIZE					(uint8)16

#define ACTIVATE_BUZZER				(uint8)0xFF

#define DELAY_TIME					100

#define DOOR_TIME					30

#define BUZZER_TIME					60

/* variable indicates how many times the password is repeated */
uint8 counter = LOW;

/*
 * in: password array
 * out: password size
 * A function that handles the entering of the password
 */
uint8 password_handling(uint8 * pass);

/*
 * in: password array, password check array,size of password array
 * out: none
 * A function that compares two passwords
 */
uint8 comp_password(uint8 * pass1,uint8 * pass2,uint8 size);

/* A function that gathers all initializations */
void init_all(void);

int
main(void)
{
	/* initial definition of size variable */
	uint8 size = LOW;
	uint8 keypad;
	uint8 password[ARRAY_SIZE] = {LOW};
	uint8 password_check[ARRAY_SIZE] = 	{LOW};
	uint8 temp_password[ARRAY_SIZE] = 	{LOW};
	uint8 comp_result;

    init_all();

	/* Enter the password for the first time */
	size = password_handling(password);

	/* enter the password again */
	password_handling(password_check);

	/* compare the 2 passwords */
	comp_result = comp_password(password,password_check,size);
	while(comp_result != 1)
	{
		comp_result = comp_password(password,password_check,size);
	}

	/* Reach here if password is matched */
	LCD_displayString("password matched");
	delay_ms(DELAY_TIME);
	LCD_clearScreen();

	/* send the password */
	for(uint8 count = LOW;count < size;count++)
	{
		UART_sendByte(password[count]);
	}
	UART_sendByte(LOW);

	while(TRUE)
	{
		LCD_displayStringRowColumn(0,0,"+:Open Door");
		LCD_displayStringRowColumn(1,0,"-:ChangePassword");

		keypad = Keypad_getPressedKey();
		delay_ms(DELAY_TIME);

		/* ASCII of - */
		if(keypad == 45)
		{
			/* reset counter before compare function */
			counter = LOW;
 			LCD_clearScreen();
 			delay_ms(DELAY_TIME);
			/* enter the password again */
			password_handling(temp_password);
			/* compare the 2 passwords */
			comp_result = comp_password(password,temp_password,size);
			while(comp_result != 1)
			{
				comp_result = comp_password(password,temp_password,size);
				if(comp_result == 3)
				{
					LCD_displayStringRowColumn(0,0,"Password wrong");
					LCD_displayStringRowColumn(1,0,"three times");
					delay_ms(DELAY_TIME);
					UART_sendByte(ACTIVATE_BUZZER);
					delay_s(BUZZER_TIME); /* wait for a minute */
					LCD_clearScreen();
					break;
				}
			}

			/* compare the 2 passwords */
			comp_result = comp_password(password,temp_password,size);
			while(comp_result != 1)
			{
				comp_result = comp_password(password,temp_password,size);
			}
			/* Reach here if password is matched */
 			LCD_displayString("password matched");
 			delay_ms(DELAY_TIME);
 			LCD_clearScreen();

			/* enter the new password */
 			size = password_handling(password);

 			/* send the password */
 			for(uint8 count = LOW;count < size;count++)
 			{
 				UART_sendByte(password[count]);
 			}
 			UART_sendByte(LOW);
		}
		/* ASCII of + */
		else if(keypad == 43)
		{
			/* reset counter before compare function */
			counter = LOW;
 			LCD_clearScreen();
 			delay_ms(DELAY_TIME);
			/* enter the password again */
			password_handling(temp_password);

			/* compare the 2 passwords */
			comp_result = comp_password(password,temp_password,size);
			while(comp_result != 1)
			{
				comp_result = comp_password(password,temp_password,size);
				if(comp_result == 3)
				{
					LCD_displayStringRowColumn(0,0,"Password wrong");
					LCD_displayStringRowColumn(1,0,"three times");
					delay_ms(DELAY_TIME);
					UART_sendByte(ACTIVATE_BUZZER);
					delay_s(BUZZER_TIME); /* wait for a minute */
					LCD_clearScreen();
					break;
				}
			}

			/* compare the 2 passwords */
			comp_result = comp_password(password,temp_password,size);
			while(comp_result != 1)
			{
				comp_result = comp_password(password,password_check,size);
			}
 			/* Reach here if password is matched */
 			LCD_displayString("password matched");
 			delay_ms(DELAY_TIME);
 			LCD_clearScreen();

 			UART_sendByte(keypad);

 			delay_ms(DELAY_TIME);
 			LCD_displayString("Door opening");
 			delay_s(DOOR_TIME);
 			LCD_clearScreen();
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

	/* LCD initialization */
	LCD_init();

	/* UART initialization */
	UART_init(&UART_Config);

	/* Timer initialization */
	Timer_init(&Timer_Config);
}

uint8
password_handling(uint8 * pass)
{
	uint8 keypad;
	uint8 size = LOW;

	LCD_displayStringRowColumn(0,0,"Please enter");
	LCD_displayStringRowColumn(1,0,"the password");
	delay_ms(DELAY_TIME);
	LCD_clearScreen();

	do
	{
		keypad = Keypad_getPressedKey();
		delay_ms(DELAY_TIME);
		if(keypad != 13)
		{
			pass[size] = keypad;
			(size)++;
			LCD_displayCharacter('*');
		}
	}
	while(keypad != 13); /*ASCII of ON button*/

	LCD_clearScreen();

	return size;
}

uint8
comp_password(uint8 * pass1,uint8 * pass2,uint8 size)
{
	for(uint8 count = LOW;count < size;count++)
	{
		if(pass1[count] != pass2[count])
		{
			counter++;
			/* if user enters the wrong password 3 times */
			if(counter == 3)
			{
				return counter;
			}
			/* enter the password again */
			password_handling(pass2);
			/* reach here when compare failed */
			return 0;
		}
	}
	/* reach here when compare succeed */
	return 1;
}
