/*
 * KeyPad.h
 *
 * Created: 9/8/2020 3:50:52 AM
 *  Author: yehia
 */ 
#ifndef KEYPAD_H_
#define KEYPAD_H_
#define KP_Port    'c'
/************************************************************************
 * Rows 
 * A --- 0
 * B --- 1
 * c --- 2
 * D --- 3 
 * columns 
 * 1 --- 4
 * 2 --- 5
 * 3 --- 6
 * 4 --- 7                                                                     
/************************************************************************/
#define KP_3          
#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>
void KP_VidInit(void);
uint8 KP_u8GetKey();





#endif /* KEYPAD_H_ */