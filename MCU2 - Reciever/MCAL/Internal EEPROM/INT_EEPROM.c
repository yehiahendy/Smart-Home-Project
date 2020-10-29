/*
 * INT_EEPROM.c
 *
 * Created: 10/24/2020 6:54:23 AM
 *  Author: yehia
 */ 
#include "INT_EEPROM.h"
void  Internal_vidEEPROM_Write(uint16 u16Address,uint8 u8Data)
{
	//wait for complete  the previous   write
	while((GET_Bit(EECR,EEWE)) != 0);
	//select address
	EEARL = u16Address;
	EEARH = u16Address >> 9 ;
	//put the data
	EEDR = u8Data;
	//enable
	SET_Bit(EECR,EEMWE);
	SET_Bit(EECR,EEWE); 
}
uint8 Internal_u8EEPROM_Read(uint16 u16Address)
{
	//wait for complete  the previous   write
	while((GET_Bit(EECR,EEWE)) != 0);
	//select address
	EEARL = u16Address;
	EEARH = u16Address >> 9 ;
	//enable
	SET_Bit(EECR,EERE);
	return EEDR;
}