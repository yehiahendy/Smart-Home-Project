/*
 * task_Func.h
 *
 * Created: 10/25/2020 9:08:15 AM
 *  Author: yehia
 */ 


#ifndef TASK_FUNC_H_
#define TASK_FUNC_H_
#include "Atmega32-drivers/MCAL/SPI/SPI.h"
#include "Atmega32-drivers/MCAL/DIO/DIO.h"
#include "Atmega32-drivers/MCAL/ADC/ADC.h"
#include "Atmega32-drivers/RTOS/FreeRTOS.h"
#include "Atmega32-drivers/RTOS/task.h"
#include "Atmega32-drivers/RTOS/queue.h"
void get_vidCommand(void *p);
void Light_vidToggle(void *p);
void Light_vidAdjust(void *p);



#endif /* TASK_FUNC_H_ */