/*
 * LDR.c
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */

#include "LDR.h"
#include "ADC.h"

uint16 LDR_getLightIntensity(void)
{
	uint8 LDR_value = 0;
	uint16 adc_value = 0;

	/* Read ADC channel mentioned where LDR is connected */
	adc_value = ADC_readChannel(LDR_CHANNEL_ID);

	/* Calculate the intensity of light from the ADC value and use casting to get correct value*/
	LDR_value = (uint8)(((uint32)adc_value*LDR_MAX_LIGHT*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_MAX_VOLT_VALUE));
 return LDR_value;
}
