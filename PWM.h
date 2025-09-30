/*
 * PWM.h
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */

#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#include "std_types.h"
#include "gpio.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define PWM_PORT_ID     	PORTB_ID
#define PWM_PIN_ID         	PIN3_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * This function responsible for initialize the PWM timer0 driver with
 * Prescaler : F_CPU/1024
 * Non-inverting mode
 * configures OC0 as the output pin.
 */
void PWM_Timer0_Start(uint8 a_duty_cycle);

#endif /* PWM_H_ */
