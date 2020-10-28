/*
 * seg.h
 *
 * Created: 9/4/2020 4:58:04 AM
 *  Author: yehia
 */ 


#ifndef SEG_H_
#define SEG_H_
#include "../../MCAL/DIO/DIO.h"
#define En    'B'
#define En1    2
#define En2    1
#define Seg   'A'
#define Seg_A  4
#define Seg_B  5
#define Seg_C  6
#define Seg_D  7
void Seg_init();
void Seg_Write(uint8 num);
void Seg_1_EN(void);
void Seg_1_DI(void);
void Seg_2_EN(void);
void Seg_2_DI(void);





#endif /* SEG_H_ */