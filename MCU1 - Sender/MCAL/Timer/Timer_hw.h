/*
 * Timer_hw.h
 *
 * Created: 9/25/2020 6:38:20 AM
 *  Author: yehia
 */ 


#ifndef TIMER_HW_H_
#define TIMER_HW_H_
#include "../../Util/STD_types.h"
/*========================================
 * common registers
 *========================================
**/
#define  TIMSK					 *((volatile uint8*)0x59)
/////////////////////////////////////////////////////////////////
// Bits of TIMSK
#define  OCIE2                     7
#define  TOIE2                     6
#define  TICIE1                    5
#define  OCIE1A                    4
#define  OCIE1B                    3
#define  TOIE1                     2
#define  OCIE0                     1
#define  TOIE0                     0
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
#define  TIFR					 *((volatile uint8*)0x58)
// Bits of TIFR
#define  OCF2                     7
#define  TOV2                     6
#define  ICF1                     5
#define  OCF1A                    4
#define  OCF1B                    3
#define  TOV1                     2
#define  OCF0                     1
#define  TOV0                     0
/////////////////////////////////////////////////////////////////

/*========================================
 * Timer 0
 *========================================
**/
#define  TCCR0                   *((volatile uint8*)0x53)
#define  TCNT0                   *((volatile uint8*)0x52)
#define  OCR0					 *((volatile uint8*)0x5c)

/////////////////////////////////////////////////////////////////
// Bits of TCCR0
#define  FOC0                     7
#define  WGM00                    6
#define  COM01                    5
#define  COM00                    4
#define  WGM01                    3
#define  CS02                     2
#define  CS01                     1
#define  CS00                     0
/////////////////////////////////////////////////////////////////
/*========================================
 * Timer 1
 *========================================
**/         
#define TCCR1A		*((volatile uint8*)0x4F)
#define TCCR1B		*((volatile uint8*)0x4E)

#define TCNT1		*((volatile uint16*)0x4C)
#define OCR1A		*((volatile uint16*)0x4A)
#define OCR1B		*((volatile uint16*)0x48)
#define ICR			*((volatile uint16*)0x46)

/*========================================
 * Timer 2
 *========================================
**/
#define TCCR2      *((volatile uint16*)0x45)
#define TCNT2	   *((volatile uint16*)0x44)   
#define OCR2	   *((volatile uint16*)0x43)

/////////////////////////////////////////////////////////////////
// Bits of TCCR2
#define  FOC2                     7
#define  WGM20                    6
#define  COM20                    5
#define  COM21                    4
#define  WGM21                    3
#define  CS22                     2
#define  CS21                     1
#define  CS20                     0
/////////////////////////////////////////////////////////////////




#endif /* TIMER_HW_H_ */