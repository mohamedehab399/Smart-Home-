/*
 * LDR.h
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */

#ifndef LDR_H_
#define LDR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define LDR_CHANNEL_ID            0
#define LDR_MAX_VOLT_VALUE        2.56
#define LDR_MAX_LIGHT             100

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the ldr from the ADC digital value.
 */
uint16 LDR_getLightIntensity(void);

#endif /* LDR_H_ */
