/*
 * Control.h
 *
 * Created: 10/24/2020 8:26:14 AM
 *  Author: yehia
 */ 


#ifndef CONTROL_H_
#define CONTROL_H_

#include "HAL/KeyPad/KeyPad.h"
#include "MCAL/Internal EEPROM/INT_EEPROM.h"

boolean    enter_Password(void);
boolean change_Password(uint8* code);






#endif /* CONTROL_H_ */