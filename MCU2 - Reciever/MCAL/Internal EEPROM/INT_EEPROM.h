/*
 * INT_EEPROM.h
 *
 * Created: 10/24/2020 6:54:37 AM
 *  Author: yehia
 */ 


#ifndef INT_EEPROM_H_
#define INT_EEPROM_H_
#include "../../Util/BIT_MATH.h"
#include "../../Util/STD_types.h"
#include "INT_EEPROM_HW.h"
void  Internal_vidEEPROM_Write(uint16 u16Address,uint8 u8Data);
uint8 Internal_u8EEPROM_Read(uint16 u16Address);

 


#endif /* INT_EEPROM_H_ */