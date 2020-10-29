/*
 * ADC_hw.h
 *
 * Created: 9/23/2020 7:43:04 PM
 *  Author: yehia
 */ 


#ifndef ADC_HW_H_
#define ADC_HW_H_
#include "../../Util/STD_types.h"
/*
///////////////////////////////////////////
define the registers of ADC 
//////////////////////////////////////////
*/
#define  ADMUX                  *((volatile uint8* )0x27)
#define  ADCSRA                 *((volatile uint8* )0x26)
#define  ADC                    *((volatile uint16*)0x24)
#define  ADCL                   *((volatile uint8*)0x24)
#define  ADCH                   *((volatile uint8*)0x25)
#define  SFIOR                  *((volatile uint8*)0x50)

#endif /* ADC_HW_H_ */