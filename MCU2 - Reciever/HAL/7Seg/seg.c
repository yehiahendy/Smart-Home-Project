/*
 * seg.c
 *
 * Created: 9/4/2020 4:57:49 AM
 *  Author: yehia
 */ 
#include "seg.h"
	void Seg_init()
	{
		DIO_WritePinDir(Seg,Seg_A,STD_OUT);
		DIO_WritePinDir(Seg,Seg_B,STD_OUT);
		DIO_WritePinDir(Seg,Seg_C,STD_OUT);
		DIO_WritePinDir(Seg,Seg_D,STD_OUT);
	}
	
	void Seg_Write(uint8 num)
	{
		Dio_WriteHighNibbleVal(Seg,num<<4);
	}
	void Seg_1_EN(void)
	{
		DIO_WritePin(En,En1,STD_high);
		
	}
	void Seg_1_DI(void)
	{
		DIO_WritePin(En,En1,STD_low);
	}
	void Seg_2_EN(void)
	{
		DIO_WritePin(En,En2,STD_high);
	}
	void Seg_2_DI(void)
	{
		DIO_WritePin(En,En2,STD_low);
	}