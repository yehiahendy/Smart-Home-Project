/*
 * DIO_hw.h
 *
 * Created: 9/1/2020 11:47:11 PM
 *  Author: yehia
 */ 
#ifndef DIO_HW_H_
#define DIO_HW_H_
#include "../../Util/STD_types.h"

#define PORT_A  *((volatile uint8*)0x3B)
#define DDR_A   *((volatile uint8*)0x3A)
#define PIN_A   *((volatile uint8*)0x39)

#define PORT_B  *((volatile uint8*)0x38)
#define DDR_B   *((volatile uint8*)0x37)
#define PIN_B   *((volatile uint8*)0x36)

#define PORT_C  *((volatile uint8*)0x35)
#define DDR_C   *((volatile uint8*)0x34)
#define PIN_C   *((volatile uint8*)0x33)

#define PORT_D  *((volatile uint8*)0x32)
#define DDR_D   *((volatile uint8*)0x31)
#define PIN_D   *((volatile uint8*)0x30)


#endif /* DIO_HW_H_ */