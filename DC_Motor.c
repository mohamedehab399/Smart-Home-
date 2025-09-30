/*
 * DC_Motor.c
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */

#include "DC_Motor.h"

void DcMotor_Init(void)
{
    /* Setup IN1 and IN2 as outputs */
    GPIO_setupPinDirection(H_bridge_PORT_ID, IN1_PIN_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(H_bridge_PORT_ID, IN2_PIN_ID, PIN_OUTPUT);

    /* Setup EN pin (PWM pin) as output */
    GPIO_setupPinDirection(H_bridge_PORT_ID, EN_PIN_ID, PIN_OUTPUT);

    /* Motor off initially */
    GPIO_writePin(H_bridge_PORT_ID, IN1_PIN_ID, LOGIC_LOW);
    GPIO_writePin(H_bridge_PORT_ID, IN2_PIN_ID, LOGIC_LOW);
    /* EN pin will be controlled by PWM_Timer0_Start */
}

void DcMotor_Rotate(DcMotor_state a_state, uint16 a_speed)
{
    switch (a_state)
    {
    case MOTOR_OFF:
        GPIO_writePin(H_bridge_PORT_ID, IN1_PIN_ID, LOGIC_LOW);
        GPIO_writePin(H_bridge_PORT_ID, IN2_PIN_ID, LOGIC_LOW);
        PWM_Timer0_Start(0);  // 0% duty cycle
        break;

    case MOTOR_CW:
        GPIO_writePin(H_bridge_PORT_ID, IN1_PIN_ID, LOGIC_LOW);
        GPIO_writePin(H_bridge_PORT_ID, IN2_PIN_ID, LOGIC_HIGH);
        PWM_Timer0_Start(a_speed); // Duty cycle = speed%
        break;

    case MOTOR_A_CW:
        GPIO_writePin(H_bridge_PORT_ID, IN1_PIN_ID, LOGIC_HIGH);
        GPIO_writePin(H_bridge_PORT_ID, IN2_PIN_ID, LOGIC_LOW);
        PWM_Timer0_Start(a_speed); // Duty cycle = speed%
        break;
    }
}
