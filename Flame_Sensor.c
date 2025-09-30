/*
 * Flame_Sensor.c
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */



#include "Flame_Sensor.h"

void FlameSensor_init(void)
{
	GPIO_setupPinDirection(FLAME_PORT_ID,FLAME_PIN_ID,PIN_INPUT);
}

uint8 FlameSensor_getValue(void)
{
    return GPIO_readPin(FLAME_PORT_ID,FLAME_PIN_ID);
}

