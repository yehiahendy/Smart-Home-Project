/*
 * Servo.c
 *
 * Created: 10/17/2020 6:16:54 AM
 *  Author: yehia
 */ 
#include "Servo.h"
void Servo_vidInit(void)
{		PWM1_vidInit();
		PWM1_vidStart();
}
void Servo_vidSetAngle(uint8 u8angle)
{
	volatile uint8 OcVal = 0 ;
	volatile uint8 PreLoad = 0 ;
	/* when angle = 0 the OCR1A should equal 125 
	 * when angle = 0 the OCR1A should equal 250 
	 * according to Servo specification 
	 * Frequency = 50 HZ 
	 * Ton at angle 0 = 1 ms
	 * Ton at angle 180 = 2ms
	 */
	OcVal = (((u8angle * 125)/180)+125);
	PreLoad = 250 - ((float)(((u8angle * 125.0)/180.0)+125) - OcVal) *250 ;
	 TCNT1 = PreLoad;
	 OCR1A = OcVal+1;
}