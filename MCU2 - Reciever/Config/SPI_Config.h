/*
 * SPI_Config.h
 *
 * Created: 10/20/2020 5:10:04 AM
 *  Author: yehia
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/********************** Type ***********************************
 *  SPI_Master				          0b00001000
 *  SPI_Slave						  0b00000000
***************************************************************/
#define  SPI_Type_Selector      SPI_Slave	
 
 /********************** Modes **********************************
  *  SPI_Mode0			Read on rising edge changed on falling edge
  *  SPI_Mode1			Read on falling edge changed on rising edge
  *  SPI_Mode2			Read on falling edge changed on rising edge
  *  SPI_Mode3			Read on rising edge changed on falling edge
 *****************************************************************/
#define  SPI_Mode_Selector      SPI_Mode0

/********************** Frequency **********************************
#define  SPI_SCK_Frequency_Clr_MSK        0b11111100
#define  SPI_SCK_Frequency_4			  0b00000000
#define  SPI_SCK_Frequency_16             0b00000000
#define  SPI_SCK_Frequency_64             0b00000000
#define  SPI_SCK_Frequency_128            0b00000000
********************************************************************/
#define  SPI_SCK_Frequency_Selector      SPI_SCK_Frequency_128
#define  Single 
#endif /* SPI_CONFIG_H_ */