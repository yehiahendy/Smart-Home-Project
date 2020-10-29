/*
 * LM35.h
 *
 * Created: 10/25/2020 7:15:46 AM
 *  Author: yehia
 */ 


#ifndef LM35_H_
#define LM35_H_
#include "../../MCAL/ADC/ADC.h"
#include "../../Config/LM35_Config.h"
void LM35_vidInit();
uint8 LM35_u8Temperature (); 



#endif /* LM35_H_ */