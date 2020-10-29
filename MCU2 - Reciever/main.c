/*
 * Final_project_component2.c
 *
 * Created: 10/25/2020 8:44:24 AM
 * Author : yehia
 */ 
#include "lightControl.h"
#include "TemperatureControl.h"
xQueueHandle CommandHandle ; //create queue handler 
int main(void)
{
	/*************************************
	 MCU2 will be disabled until first MCU 
	 receive the correct password 
	 **************************************/
	DIO_WritePinDir('C',6,STD_IN);
	while (DIO_ReadPin('c',6) == 0);
    /* Replace with your application code */
	
 	CommandHandle = xQueueCreate(1,sizeof(uint8));//create queue the length = 1, size = 1 byte 
	 //create tasks 
 	xTaskCreate(get_vidCommand,"Get",85,NULL,1,NULL);	
 	xTaskCreate(Light_vidAdjust,"AutoLight",200,NULL,2,NULL);
 	xTaskCreate(Light_vidToggle,"LED2",200,NULL,3,NULL);
 	xTaskCreate(get_Temperature,"Get temperature",250,NULL,1,NULL);
	 //start Scheduler
 	vTaskStartScheduler();

    while (1) 
    {
    }
}

