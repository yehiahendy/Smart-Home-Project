/*
 * SPI.c
 *
 * Created: 10/20/2020 5:08:41 AM
 *  Author: yehia
 */ 
#include "../../Util/BIT_MATH.h"
#include "SPI.h"

void  SPI_vidInit(void)
{
	SPCR = 0x00;
	// choose Slave or Master
	SPCR |= SPI_Type_Selector;
	#if (SPI_Type_Selector == SPI_Master)
	DIO_WritePinDir('b',4,STD_OUT);
	DIO_WritePinDir('b',5,STD_OUT);
	DIO_WritePinDir('b',6,STD_IN);
	DIO_WritePinDir('b',7,STD_OUT);

	#elif (SPI_Type_Selector == SPI_Slave)
	DIO_WritePinDir('b',4,STD_IN);
	DIO_WritePinDir('b',5,STD_IN);
	DIO_WritePinDir('b',6,STD_OUT);
	DIO_WritePinDir('b',7,STD_IN);
	#endif
	//Enable SPI interrupt flag
	SET_Bit(SPCR,SPIE);
	//LSB transmitted first 
	SET_Bit(SPCR,DORD);
	//select the mode 
	SPCR &= SPI_Mode_Clr_MSK;
	SPCR |= SPI_Mode_Selector;
	// select the frequency
	#ifdef Single
	CLEAR_Bit(SPSR,SPI2X);
	#endif
	#ifdef Double_Speed
	SET_Bit(SPSR,SPI2X);
	#endif
	SPCR &= SPI_SCK_Frequency_Clr_MSK;
	SPCR |= SPI_SCK_Frequency_Selector;
	//Enable SPI
	SET_Bit(SPCR,SPE); 
	
}
void SPI_Send_Date(uint8 u8SendData)
{
	/*uint8 u8ReceiveData;*/
	SPDR = u8SendData; //send data
	while((GET_Bit(SPSR,SPIF)) == 0); //wait to transmitt the data

}
uint8 SPI_Receive(void)
{

	while((GET_Bit(SPSR,SPIF)) == 0); //wait to transmitt the data
	return SPDR; //Receive data
}