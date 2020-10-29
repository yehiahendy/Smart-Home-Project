/*
 * INT.h
 *
 * Created: 11/18/2019 9:34:35 PM
 *  Author: breks
 */ 

#ifndef INT_H_
#define INT_H_

#define EXINT0				   		__vector_1
#define EXINT1						__vector_2
#define EXINT2				   		__vector_3
#define TIMER2_COMP					__vector_4
#define TIMER2_OVF					__vector_5
#define TIMER0_COMP					__vector_10
#define TIMER0_OVF					__vector_11
#define TIMER1_CAPT					__vector_6
#define TIMER1_COMPA				__vector_7
#define TIMER1_COMPB				__vector_8
#define TIMER1_OVF					__vector_9

#define ISR(vector)				   	vector(void) __attribute__((signal,used));\
		vector(void)

#define GI_EN()			SET_BIT((*((uint8*)0x5F)),7)
#define GI_DI()			CLR_BIT((*((uint8*)0x5F)),7)

#endif /* INT_H_ */