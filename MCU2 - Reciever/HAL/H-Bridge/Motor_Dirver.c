/*
 * Motor_Dirver.c
 *
 * Created: 10/28/2020 5:46:53 AM
 *  Author: yehia
 */ 
#include "Motor_Dirver.h"
void motorA_vidInit()
{
	//IN1,IN2,IN3,IN4   output
	DIO_WritePinDir(IN1_PORT,IN1,STD_OUT);
	DIO_WritePinDir(IN2_PORT,IN2,STD_OUT);
	DIO_WritePinDir(ENA_PORT,ENA,STD_OUT);
	PWM2_vidInit();
	PWM2_vidStart();

}
void motorB_vidInit()
{
	DIO_WritePinDir(ENB_PORT,ENB,STD_OUT);
	DIO_WritePinDir(IN3_PORT,IN3,STD_OUT);
	DIO_WritePinDir(IN4_PORT,IN4,STD_OUT);
	PWM0_vidInit();
	PWM0_vidStart();
		
}
//u8speed from 0 - 100 percentage 
void Motor1_ClockWise(uint8 u8Speed)
{
	DIO_WritePin(IN1_PORT,IN1,STD_high);
	DIO_WritePin(IN2_PORT,IN2,STD_low);
	PWM0_vidGenerate(u8Speed);
}
void Motor1_AntiClockWise(uint8 u8Speed)
{
	DIO_WritePin(IN1_PORT,IN1,STD_low);
	DIO_WritePin(IN2_PORT,IN2,STD_high);
	PWM0_vidGenerate(u8Speed);
	
}
void Motor1_Stop()
{
		DIO_WritePin(IN1_PORT,IN1,STD_high);
		DIO_WritePin(IN2_PORT,IN2,STD_high);
}
void Motor2_ClockWise(uint8 u8Speed)
{
	DIO_WritePin(IN3_PORT,IN3,STD_high);
	DIO_WritePin(IN4_PORT,IN4,STD_low);
	PWM2_vidGenerate(u8Speed);
	
}
void Motor2_AntiClockWise(uint8 u8Speed)
{
	DIO_WritePin(IN3_PORT,IN3,STD_low);
	DIO_WritePin(IN4_PORT,IN4,STD_high);
	PWM2_vidGenerate(u8Speed);
	
}
void Motor2_Stop()
{
	DIO_WritePin(IN3_PORT,IN3,STD_high);
	DIO_WritePin(IN4_PORT,IN4,STD_high);
	
}
