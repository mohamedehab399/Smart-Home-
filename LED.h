/*
 * LED.h
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */

#ifndef LED_H_
#define LED_H_

#include "gpio.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LED_PORT   PORTB_ID

#define RED_LED   PIN5_ID
#define GREEN_LED   PIN6_ID
#define BLUE_LED   PIN7_ID


/* LED logic type define for the connection type positive or negative logic*/
typedef enum {
    LED_POSITIVE_LOGIC,
    LED_NEGATIVE_LOGIC
} LED_LogicType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Initialize the LEDS:
 * 1. Setup the LEDS pins directions by use the GPIO driver.
 * 2. Setup the LEDS to be logic low at the first
 */
void LEDS_init(void);
/*
 * Description :
 * Turns on that its ID mentioned using GPIO driver
 */
void LED_on(uint8 a_LED_ID, LED_LogicType a_ledLogic);
/*
 * Description :
 * Turns off that its ID mentioned using GPIO driver
 */
void LED_off(uint8 a_LED_ID, LED_LogicType a_ledLogic);

#endif /* LED_H_ */
