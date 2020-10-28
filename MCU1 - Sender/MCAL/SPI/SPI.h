/*
 * SPI.h
 *
 * Created: 10/20/2020 5:09:12 AM
 *  Author: yehia
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "../../Config/SPI_Config.h"
#include "SPI_HW.h"
#include "../../Util/STD_types.h"
#include "../DIO/DIO.h"
/************************************************************************
 * SPI Functions                                                       
 ************************************************************************/

void  SPI_vidInit(void);
uint8 SPI_Receive(void);
void SPI_Send_Date(uint8 u8SendData);


/************************************************************************
 * SPI configs                                                        
 ************************************************************************/
                          
/********************** Type **********************************/

 #define  SPI_Master				      0b00010000
 #define  SPI_Slave						  0b00000000

/********************** Modes **********************************/
#define  SPI_Mode_Clr_MSK			      0b11110011
#define  SPI_Mode0						  0b00000000
#define  SPI_Mode1				          0b00000100
#define  SPI_Mode2						  0b00001000
#define  SPI_Mode3						  0b00001100

/********************** Frequency **********************************/
#define  SPI_SCK_Frequency_Clr_MSK        0b11111100
#define  SPI_SCK_Frequency_4			  0b00000000
#define  SPI_SCK_Frequency_16             0b00000001
#define  SPI_SCK_Frequency_64             0b00000010
#define  SPI_SCK_Frequency_128            0b00000011

#endif /* SPI_H_ */