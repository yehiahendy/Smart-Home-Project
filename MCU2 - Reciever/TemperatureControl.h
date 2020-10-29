/*
 * TemperatureControl.h
 *
 * Created: 10/26/2020 3:55:05 PM
 *  Author: yehia
 */ 


#ifndef TEMPERATURECONTROL_H_
#define TEMPERATURECONTROL_H_
#include "Atmega32-drivers/MCAL/DIO/DIO.h"
#include "Atmega32-drivers/HAL/LM35/LM35.h"
#include "Atmega32-drivers/HAL/H-Bridge/Motor_Dirver.h"
#include "Atmega32-drivers/HAL/LCD/LCD.h"
#include "Atmega32-drivers/RTOS/FreeRTOS.h"
#include "Atmega32-drivers/RTOS/task.h"
#include "Atmega32-drivers/RTOS/queue.h"
void get_Temperature(void *p);








#endif /* TEMPERATURECONTROL_H_ */