/*
 * Bluetooth.c
 *
 * Created: 10/25/2020 2:07:21 AM
 *  Author: yehia
 */ 
#include "Bluetooth.h"
void Blutooth_vidInit()
{
	UART_vidInit();
}
void Blutooth_vidSendData(uint8 data)
{
	UART_vidSendData(data);
}
uint8 Blutooth_u8ReceivedData(void)
{
	uint8 u8Data;
	u8Data = UART_u8ReadData();
	return u8Data;
}