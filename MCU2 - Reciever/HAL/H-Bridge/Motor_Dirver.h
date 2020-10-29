/*
 * Motor_Dirver.h
 *
 * Created: 10/28/2020 5:47:04 AM
 *  Author: yehia
 */ 


#ifndef MOTOR_DIRVER_H_
#define MOTOR_DIRVER_H_
#include "../../MCAL/Timer/Timer.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../Config/Motor_Dirver_Config.h"
void motorA_vidInit();
void motorB_vidInit();
void Motor1_ClockWise(uint8 u8Speed);
void Motor1_AntiClockWise(uint8 u8Speed);
void Motor1_Stop();
void Motor2_ClockWise(uint8 u8Speed);
void Motor2_AntiClockWise(uint8 u8Speed);
void Motor2_Stop();




#endif /* MOTOR_DIRVER_H_ */