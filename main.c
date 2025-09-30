/*
 * main.c
 *
 *  Created on: Sep 28, 2025
 *      Author: Mohamed Ehab
 */

#include "lcd.h"
#include "LED.h"
#include "LDR.h"
#include "BUZZER.h"
#include "DC_Motor.h"
#include "flame_Sensor.h"
#include "LM35_Temperature_Sensor.h"
#include "ADC.h"

/*
 * Description :
 * Main function for the app
 */
int main(void)
{
	uint8 temp,light_intensity;  /* two variables to store the temperature and the light in */

	/* enable all components using init functions */
	LEDS_init();
	Buzzer_init();
	DcMotor_Init();
	FlameSensor_init();
	LCD_init();
	ADC_init();
	while(1)
	{
		/* check the flame */
		if(FlameSensor_getValue()==LOGIC_HIGH)
		{
			Buzzer_on();
			LCD_sendCommand(LCD_CLEAR_COMMAND);
			LCD_displayStringRowColumn(0,0,"Critical alert!");
			while(FlameSensor_getValue()==LOGIC_HIGH);  /*using the polling technique for the flame sensor*/
			LCD_sendCommand(LCD_CLEAR_COMMAND);
			Buzzer_off();
		}

		/*display the temperature and light intensity*/
		light_intensity=LDR_getLightIntensity();
		temp=LM35_getTemperature();
		LCD_displayStringRowColumn(1,0,"Temp=");



		/*display the temperature and let space for the digits if it 3 num or 2 nums */
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else if (temp>=10)
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}
		else
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}

		LCD_displayStringRowColumn(1,8,"LDR=");

		if(light_intensity >= 100)
		{
			LCD_intgerToString(light_intensity);
			LCD_displayCharacter('%');
		}
		else
		{
			LCD_intgerToString(light_intensity);

			LCD_displayCharacter('%');
			LCD_displayCharacter(' ');
		}

		/*display fan state depend on temperature*/
		temp <25 ?LCD_displayStringRowColumn(0,3,"FAN is OFF"):LCD_displayStringRowColumn(0,3,"FAN is ON ");

		/* fan speed control using PWM duty cycle */
		if(temp<25){
			DcMotor_Rotate(MOTOR_OFF,0);
		}
		else if(temp>=25 && temp<30)
		{
			DcMotor_Rotate(MOTOR_CW,25);
		}
		else if(temp>=30 && temp<35)
		{
			DcMotor_Rotate(MOTOR_CW,50);
		}
		else if(temp>=35&& temp<40)
		{
			DcMotor_Rotate(MOTOR_CW,75);
		}
		else if(temp>=40)
		{
			DcMotor_Rotate(MOTOR_CW,100);
		}


		/* light intensity control depend on LDR reading*/
		if(light_intensity>70)
		{
			LED_off(RED_LED , LED_POSITIVE_LOGIC);
			LED_off(GREEN_LED , LED_POSITIVE_LOGIC);
			LED_off(BLUE_LED , LED_POSITIVE_LOGIC);
		}
		else if(light_intensity<=70 && light_intensity>50)
		{
			LED_on(RED_LED , LED_POSITIVE_LOGIC);
			LED_off(GREEN_LED , LED_POSITIVE_LOGIC);
			LED_off(BLUE_LED , LED_POSITIVE_LOGIC);
		}
		else if(light_intensity<=50 && light_intensity>15)
		{
			LED_on(RED_LED , LED_POSITIVE_LOGIC);
			LED_on(GREEN_LED , LED_POSITIVE_LOGIC);
			LED_off(BLUE_LED , LED_POSITIVE_LOGIC);
		}
		else if(light_intensity<=15)
		{
			LED_on(RED_LED , LED_POSITIVE_LOGIC);
			LED_on(GREEN_LED , LED_POSITIVE_LOGIC);
			LED_on(BLUE_LED , LED_POSITIVE_LOGIC);
		}
	}
}

