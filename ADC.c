/*
 * ADC.c
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */


#include <avr/io.h>
#include "ADC.h"
#include "common_macros.h"


void ADC_init(void) {
	/* ADMUX Register Bits Description:
	 * REFS1 & REFS0 = 11 for choose the internal voltage 2.56v
	 * ADLAR   = 0 right adjusted
	 * MUX0:4  = 00000 to initialize the channel number that it will read
	 * so the value of the ADMUX register is 0b11000000 --> 0xC0
	 */
    ADMUX = 0xC0;

	/* ADCSRA Register Bits Description:
	 * ADEN = 1 Enable ADC
	 * ADIE = 0 Disable ADC Interrupt
	 * ADATE = 0 Disable Auto Trigger
	 * ADPS2:0 = 111 to choose ADC_Clock = F_CPU/128 = 16Mhz/128 = 125Khz --> ADC range of operation (50-200Khz)
	 * so the value of the ADCSRA register is 0b10000111 --> 0x87
	 */
    ADCSRA = 0x87;
}


uint16 ADC_readChannel(uint8 a_channel_num) {
    ADMUX =( ADMUX & 0xE0)|(a_channel_num & 0x07); /* Set the desired channel */
    SET_BIT(ADCSRA, ADSC);  /* Set bit to start ADC conversion */
    while (BIT_IS_CLEAR(ADCSRA, ADIF));   /* Polling and wait for conversion to complete and flag be 1*/
    SET_BIT(ADCSRA, ADIF);              /* Clear flag ADIF by set it */
    return ADC; /* Return the ADC result */
}




