/*
 * ADC.h
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function Description :
 * This function responsible for initializing the ADC register (ADMUX,ADCSRA) to activate the ADC
 */
void ADC_init(void);

/*
 * Description :
 * This function responsible for reading analog data from a certain ADC channel
 * and convert it to digital using the ADC driver and return the digital value
 * use uint16 cause the ADC return 10bit of data stored in ADC Data Register.
 */
uint16 ADC_readChannel(uint8 a_channel_num);

#endif /* ADC_H_ */
