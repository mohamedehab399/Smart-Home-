/*
 * LED.c
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */

#include "LED.h"

/*
 * Description :
 * Initialize the LEDS:
 * 1. Setup the LEDS pins directions by use the GPIO driver.
 * 2. Setup the LEDS to be logic low at the first
 */
void LEDS_init(void)
{
	GPIO_setupPinDirection(LED_PORT,RED_LED,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT,GREEN_LED,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT,BLUE_LED,PIN_OUTPUT);
	GPIO_writePin(LED_PORT,RED_LED,LOGIC_LOW);
	GPIO_writePin(LED_PORT,GREEN_LED,LOGIC_LOW);
	GPIO_writePin(LED_PORT,BLUE_LED,LOGIC_LOW);
}

/*
 * Description :
 * Turns on the required LED with it's ID using GPIO driver and configuration of connection
 * and configured for positive and negative logic
 */
void LED_on(uint8 a_LED_ID , LED_LogicType a_ledLogic)
{
	if (a_ledLogic == LED_POSITIVE_LOGIC)
	{
		GPIO_writePin(LED_PORT, a_LED_ID, LOGIC_HIGH);
	}
	else
	{
		GPIO_writePin(LED_PORT, a_LED_ID, LOGIC_LOW);
	}
}
/*
 * Description :
 * Turns off the required LED with it's ID using GPIO driver and configuration of connection
 * and configured for positive and negative logic
 */
void LED_off(uint8 a_LED_ID , LED_LogicType a_ledLogic)
{
	if (a_ledLogic == LED_POSITIVE_LOGIC)
	{
		GPIO_writePin(LED_PORT, a_LED_ID, LOGIC_LOW);
	}
	else
	{
		GPIO_writePin(LED_PORT, a_LED_ID, LOGIC_HIGH);
	}
}
