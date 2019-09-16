/*
 * main.c
 *
 *  Created on: Sep 16, 2019
 *      Author: Nour
 * Description: The main file
 */

#include "seven_segment.h"
#include "keypad.h"

int
main(void)
{
	uint8 key;
	seven_segment_init();

	while(TRUE)
	{
		/* get the pressed button from keypad */
        key = Keypad_getPressedKey();

	    if((key >= 0) && (key <= 9))
		{
			#ifdef	FIRST_4_PINS
			SEVEN_SEGMENT_OUT = (SEVEN_SEGMENT_OUT & ~FIRST_FOUR_PINS) | (key & FIRST_FOUR_PINS);
			#endif

			#ifdef	SECOND_4_PINS
			SEVEN_SEGMENT_OUT = (SEVEN_SEGMENT_OUT & ~SECOND_FOUR_PINS) | (key & SECOND_FOUR_PINS);
			#endif
		}
	}
}
