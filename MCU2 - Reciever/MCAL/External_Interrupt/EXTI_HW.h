/*
 * EXTI_HW.h
 *
 * Created: 9/10/2020 6:46:13 AM
 *  Author: yehia
 */ 

#ifndef EXTI_HW_H_
#define EXTI_HW_H_
#include "../../Util/STD_types.h"
#ifndef MCUCR
#define MCUCR					*((volatile uint8*)0x55)
#define MCUCSR					*((volatile uint8*)0x54)
#define GICR					*((volatile uint8*)0x5B)
#define GIFR					*((volatile uint8*)0x5A)
#endif





#endif /* EXTI_HW_H_ */