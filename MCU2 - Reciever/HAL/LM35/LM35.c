/*
 * LM35.c
 *
 * Created: 10/25/2020 7:15:35 AM
 *  Author: yehia
 */ 
#include "LM35.h"
void LM35_vidInit()
{
	ADC_init(LM35_Channel);
}
uint8 LM35_u8Temperature ()
{ 
	uint16 u16Data = 0 ;
	u16Data =ADC_ReadChannel(A0);
	if (LM35_Vref == 5)
	{
		return (uint8)(u16Data/2);
	}
	else if (LM35_Vref == 2.5)
	{
		return (uint8)(u16Data/4);
	}
	
}