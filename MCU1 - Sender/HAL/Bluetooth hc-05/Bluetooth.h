/*
 * Bluetooth.h
 *
 * Created: 10/25/2020 2:07:29 AM
 *  Author: yehia
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_
#include "../../MCAL/UART/UART.h"
void Blutooth_vidInit();
void Blutooth_vidSendData(uint8 data);
uint8 Blutooth_u8ReceivedData(void);



#endif /* BLUETOOTH_H_ */