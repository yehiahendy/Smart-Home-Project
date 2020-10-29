/*
 * INT_EEPROM_Config.h
 *
 * Created: 10/24/2020 6:55:12 AM
 *  Author: yehia
 */ 


#ifndef INT_EEPROM_CONFIG_H_
#define INT_EEPROM_CONFIG_H_

/**********************EEPROM Registers******************************/
#define EEDR        *((volatile unsigned char*)0x3D)
#define EECR        *((volatile unsigned char*)0x3C)
#define EEARH       *((volatile unsigned char*)0x3F)
#define EEARL       *((volatile unsigned char*)0x3E)
	
/**********************EECR Bits******************************/
#define EERE        0
#define EEWE        1
#define EEMWE       2
#define EERIE       3






#endif /* INT_EEPROM_CONFIG_H_ */