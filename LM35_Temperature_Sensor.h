/*
 * LM35_Temperature_Sensor.h
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */

#ifndef LM35_TEMPERATURE_SENSOR_H_
#define LM35_TEMPERATURE_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define TEMP_CHANNEL_ID         1
#define TEMP_MAX_VOLT_VALUE     1.5
#define TEMP_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * This function responsible for calculate the temperature from the ADC digital value
 * read from the channel mentioned.
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_TEMPERATURE_SENSOR_H_ */
