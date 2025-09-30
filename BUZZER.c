/*
 * BUZZER.c
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */

#include "BUZZER.h"

void Buzzer_init(void)
{
	GPIO_setupPinDirection(Buzzer_PORT_ID,Buzzer_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(Buzzer_PORT_ID,Buzzer_PIN_ID,LOGIC_LOW);
}

void Buzzer_on(void)
{
	GPIO_writePin(Buzzer_PORT_ID,Buzzer_PIN_ID,LOGIC_HIGH);
}

void Buzzer_off(void)
{
	GPIO_writePin(Buzzer_PORT_ID,Buzzer_PIN_ID,LOGIC_LOW);
}
