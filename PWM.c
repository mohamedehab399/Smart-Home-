/*
 * PWM.c
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */


#include"PWM.h"

void PWM_Timer0_Start(uint8 a_duty_cycle)
{
	TCNT0 = 0; /* to set timer initial value */

	OCR0 =(a_duty_cycle * 256) / 100 - 1;

	/*set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC. */
	GPIO_setupPinDirection(PWM_PORT_ID,PWM_PIN_ID,PIN_OUTPUT);

	/* Configure timer control register
	 * 1. FOC0=0 --> for PWM mode
	 * 2. WGM01=1 & WGM00=1 --> for fast PWM Mode
	 * 3. COM00=0 & COM01=1 -->  non inverted mode (clear oc0)
	 * 4. CS00=1 & CS01=0 & CS02=1 --> set clock = F_CPU/1024
	 * so the value of the TCCR0 register is 0b01101101 --> 0x6D
	 */
	TCCR0 = 0x6D;
}

