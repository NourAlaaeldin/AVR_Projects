/*
 * seven_segment.c
 *
 *  Created on: Sep 16, 2019
 *      Author: Nour
 * Description: Header file for the seven_segment driver
 */

#include "seven_segment.h"

void
seven_segment_init(void)
{
	#ifdef	FIRST_4_PINS
	SEVEN_SEGMENT_DIR |= FIRST_FOUR_PINS;
	SEVEN_SEGMENT_OUT &= ~FIRST_FOUR_PINS;
	#endif

    #ifdef	SECOND_4_PINS
	SEVEN_SEGMENT_DIR |= SECOND_FOUR_PINS;
	SEVEN_SEGMENT_OUT &= ~SECOND_FOUR_PINS;
	#endif
}
