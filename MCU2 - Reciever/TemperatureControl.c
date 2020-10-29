/*
 * TemperatureControl.c
 *
 * Created: 10/26/2020 3:55:20 PM
 *  Author: yehia
 */ 
#include "TemperatureControl.h"
void get_Temperature(void *p)
{
	LCD_init(); //initiate LCD 
	LM35_vidInit(LM35_Channel); //initiate temperature sensor
	motorA_vidInit();           // initiate Motor 1
	motorB_vidInit();     
	uint16 u8Temperature;
	while (1)
	{
		u8Temperature = ADC_ReadChannel(A0); //get the read of temperature sensor
 		LCD_clearScreen();  // clear LCD
		 /* Display the temperature value on LCD */
 		LCD_WriteString("Temperature:");
		u8Temperature =LM35_u8Temperature(); //get read again to make sure 
    	LCD_SendNumber(u8Temperature);
		/* Temperature controller */ 
		if (u8Temperature >= 27)
		{
			//turn on Air conditioning 
			Motor1_ClockWise(100);
		}
		else if (u8Temperature <= 18)
		{
			//turn on heater 
			Motor2_ClockWise(100);
		}
		else
		{
			Motor2_Stop();
			Motor1_Stop();
		}
		taskYIELD(); 
		vTaskDelay(50/portTICK_PERIOD_MS); //task will stay in block state 50 ms
	}
}

