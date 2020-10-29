/*
 * DIO.h
 *
 * Created: 9/1/2020 11:47:38 PM
 *  Author: yehia
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "DIO_hw.h"
#include "../../Util/BIT_MATH.h"

void DIO_WritePinDir(uint8 Port,uint8 PinNo,STD_Direction Dir);
void DIO_WritePin(uint8 Port,uint8 PinNo,STD_levelType level);
void DIO_TogglePin(uint8 Port,uint8 PinNo);
STD_levelType DIO_ReadPin(uint8 Port,uint8 PinNo);
void Dio_WritePortDir(uint8 PORT,STD_Direction dir);
uint8 Dio_ReadPort(uint8 PORT );
void Dio_WritePortVal(uint8 PORT, uint8 data);
void Dio_WritePortLevel(uint8 PORT, STD_levelType Level);
//advanced

void Dio_WriteHighNibbleVal(uint8 port, uint8 val);
void Dio_WriteLowNibbleVal(uint8 port, uint8 val);

void Dio_WriteHighNibbleDir(uint8 port, STD_Direction dir) ;
void Dio_WriteLowNibbleDir(uint8 port, STD_Direction dir);

#endif /* DIO_H_ */