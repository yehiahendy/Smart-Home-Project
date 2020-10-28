/*
 * UART.c
 *
 * Created: 10/12/2020 7:06:38 AM
 *  Author: yehia
 */ 
#include "UART.h"
Reg_USART UART = {
	
	(uint8 volatile *const)      0x40,
	(Reg_UCSRC volatile *const)  0x40,
	(uint8 volatile *const)      0x2C,
	(Reg_UCSRA volatile *const)  0x2B,
	(Reg_UCSRB volatile *const)  0x2A,
	(uint8 volatile *const)      0x29,
};
void   UART_vidInit()
{
	
	//chose baud rate
	*(UART.UBRRL) = UBRR_Val;
	UART.UCSRC->bit.URSEL = 0 ;
	*(UART.UBRRH) = UBRR_Val >> 8;
	/* frame format */ 
	//number of bits received or transmitted  
	UART.UCSRC->bit.URSEL = 1 ;
	UART.UCSRC->Byte &= Character_Size_Clr_MSK;
	UART.UCSRC->Byte |= UART_Character_Size;
	//number of stop bit 
	UART.UCSRC->bit.USBS = UART_Stop_Bit;
	//parity options  
	UART.UCSRC->Byte &= parity_Clr_MSK;
	UART.UCSRC->Byte |= UART_parity;
	//chose mode Synchronous or Asynchronous 
	UART.UCSRC->bit.UMSEL = UART_Mode ;
	//choose speed 
	UART.UCSRA->bit.U2X = normal_Speed;
	//enable receive or transmit  
	UART.UCSRB->Byte = 0x00;
	UART.UCSRB->bit.TXCIE = 1 ;
	UART.UCSRB->bit.TXEN = 1 ;
	UART.UCSRB->bit.RXCIE = 1 ;
	UART.UCSRB->bit.RXEN = 1 ;
	UART.UCSRB->bit.UDRIE = 1 ;
	
	
}
uint8  UART_u8ReadData(void)
{
	
	while (UART.UCSRA->bit.RXC == 0);
	UART.UCSRA->bit.RXC  = 1;
	return *(UART.UDR);
}
void   UART_vidSendData(uint8 u8data)
{
	
	*(UART.UDR) = u8data ;
	while (UART.UCSRA->bit.TXC == 0);
	UART.UCSRA->bit.TXC  = 1;
	
}

uint8 *UART_u8ReadString(void)
{
	
	uint8 static u8Str[String_Size] , i = 0;
	while (i < String_Size-1) 
	{
	   u8Str[i]=UART_u8ReadData();
	   if (u8Str[i] != '\0')
	   {
		  
		   if  ((u8Str[i] == '\x20'))
		   {
			   u8Str[i] = '\0';
			    break;
		   }
		    i++;
	   }
	}
	i = 0;
	return u8Str;
}
void   UART_vidSendString(uint8* u8data)
{
	uint8 i = 0;
	while(u8data[i] != '\0')
	{
		UART_vidSendData(u8data[i]);
		i++;
	}
}