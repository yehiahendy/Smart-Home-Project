/*
 * task_Func.h
 *
 * Created: 10/25/2020 9:08:15 AM
 *  Author: yehia
 */ 


#ifndef TASK_FUNC_H_
#define TASK_FUNC_H_
#include "MCAL/SPI/SPI.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/ADC/ADC.h"
#include "RTOS/FreeRTOS.h"
#include "RTOS/task.h"
#include "RTOS/queue.h"
void get_vidCommand(void *p);
void Light_vidToggle(void *p);
void Light_vidAdjust(void *p);

#endif /* TASK_FUNC_H_ */
