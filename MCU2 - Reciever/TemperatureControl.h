/*
 * TemperatureControl.h
 *
 * Created: 10/26/2020 3:55:05 PM
 *  Author: yehia
 */ 


#ifndef TEMPERATURECONTROL_H_
#define TEMPERATURECONTROL_H_
#include "MCAL/DIO/DIO.h"
#include "HAL/LM35/LM35.h"
#include "HAL/H-Bridge/Motor_Dirver.h"
#include "HAL/LCD/LCD.h"
#include "RTOS/FreeRTOS.h"
#include "RTOS/task.h"
#include "RTOS/queue.h"
void get_Temperature(void *p);








#endif /* TEMPERATURECONTROL_H_ */
