/*
 * LM35_Temperature_Sensor.c
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */


#include "LM35_Temperature_Sensor.h"
#include "ADC.h"


uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC value from the channel id mentioned*/
	adc_value = ADC_readChannel(TEMP_CHANNEL_ID);

	/* Calculate the temperature from the ADC value and use casting to get correct value */
	temp_value = (uint8)((((uint32)(adc_value*TEMP_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE))/(ADC_MAXIMUM_VALUE*TEMP_MAX_VOLT_VALUE)));
	return temp_value;
}

