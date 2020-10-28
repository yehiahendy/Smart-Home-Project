/*
 * Servo.h
 *
 * Created: 10/17/2020 6:17:07 AM
 *  Author: yehia
 */ 


#ifndef SERVO_H_
#define SERVO_H_
#include "../../Util/STD_types.h"
#include "../../MCAL/Timer/Timer.h"
#include "../../Util/STD_types.h"
#include "../../MCAL//Timer/Timer.h"

void Servo_vidInit(void);
void Servo_vidSetAngle(uint8 u8angle);

#endif /* SERVO_H_ */