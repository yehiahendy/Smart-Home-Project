/*
 * task_Func.c
 *
 * Created: 10/25/2020 9:07:45 AM
 *  Author: yehia
 */ 
#include "lightControl.h"
extern QueueHandle_t CommandHandle ;

void get_vidCommand(void *p)
{
	//initiate SPI 
	SPI_vidInit();
	uint8 SPI_Receiver = '\0';	
	while(1)
	{	
		SPI_Receiver = SPI_Receive(); //Receive the commadn from first MCU using SPI
 		xQueueSendToBack(CommandHandle,&SPI_Receiver,portMAX_DELAY); // Send command to queue to receive it in a another task
 		taskYIELD();
		 
	}
}
//first task Highest periorty 
void Light_vidToggle(void *p)
{
	//initiation 
	DIO_WritePinDir('C',3,STD_OUT);
	DIO_WritePinDir('C',4,STD_OUT);
	DIO_WritePinDir('C',5,STD_OUT);
	uint8 u8Receive;
	while (1)
	{
		//receive the command from the queue 
		xQueueReceive(CommandHandle,&u8Receive,portMAX_DELAY);
		/* according to the command toggle on LED */
		if (u8Receive == 'A')
		{
			DIO_TogglePin('C',3);
		}
		else if (u8Receive == 'B')
		{
			DIO_TogglePin('C',4);
		}
		else if (u8Receive == 'C')
		{
			DIO_TogglePin('C',5);
	    }
		
		//stay 200ms in block state 
		vTaskDelay(200/portTICK_PERIOD_MS);
	
	}
}
void Light_vidAdjust(void *p)
{
	//initiation 
	DIO_WritePinDir('A',1,STD_IN);
	DIO_WritePinDir('A',2,STD_IN);
	DIO_WritePinDir('A',3,STD_IN);
	DIO_WritePinDir('C',0,STD_OUT);
	DIO_WritePinDir('C',1,STD_OUT);
	DIO_WritePinDir('C',2,STD_OUT);
	ADC_init(A1);
	ADC_init(A2);
	ADC_init(A3);
	while (1)
	{
		
			//Read ADC value 
			if ( ADC_ReadChannel(A1) >= 500)
			{
				DIO_WritePin('c',0,STD_high);
			}
			else
			{
				DIO_WritePin('c',0,STD_low);
			}
			if (ADC_ReadChannel(A2)> 500)
			{
				DIO_WritePin('c',1,STD_high);
			}
			else
			{
				DIO_WritePin('c',1,STD_low);
			}
			if ( ADC_ReadChannel(A3) >= 350)
			{
				DIO_WritePin('c',2,STD_high);
			}
			else
			{
				DIO_WritePin('c',2,STD_low);
			}
			
			vTaskDelay(10/portTICK_PERIOD_MS);
		}
			
}


