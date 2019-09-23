/*
 *  adc.h
 *  Created on: Sep 23, 2019
 *  Author: Nour Alaa
 */

#ifndef ADC_H_
#define ADC_H_

#include "micro_config.h"
#include "standard_library.h"
#include "common_macros.h"
#include "AVR_registers.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */

extern volatile uint16 g_ADC_value;

typedef enum
{
	AREF,AVCC,INTERNAL = 3
}ADC_Voltage;

typedef enum
{
	NO_PRESCALING,_2,_4,_8,_16,_32,_64,_128
}ADC_Prescalar;

typedef enum
{
	Polling,Interrupt
}ADC_Mode;

typedef struct
{
	ADC_Voltage   voltage;
	ADC_Prescalar prescalar;
	ADC_Mode      mode;
}ADC_ConfigType;

void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
void ADC_readChannel(uint8 channel_num,const ADC_ConfigType * Config_Ptr);

#endif /* ADC_H_ */
