/*
 * PIR.c
 *
 * Created: 10/23/2020 4:14:10 AM
 *  Author: yehia
 */ 
#include "PIR.h"
void    PIR_vidInit()
{
	DIO_WritePinDir(PIR_PORT,PIR_PIN,STD_IN);
}
boolean PIR_CheckHuman()
{
	STD_levelType readLevel;
	readLevel = DIO_ReadPin(PIR_PORT,PIR_PIN);
	return readLevel == STD_high ? true : false;
}
