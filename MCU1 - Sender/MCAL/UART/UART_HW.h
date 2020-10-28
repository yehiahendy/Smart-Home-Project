/*
 * UART_HW.h
 *
 * Created: 10/12/2020 7:07:01 AM
 *  Author: yehia
 */ 


#ifndef UART_HW_H_
#define UART_HW_H_
#include "../../Util/STD_types.h"

// crate union which represent the UCSRA register 
typedef union
{
// create struct Which represent the bits of register
	struct{
		uint8 MPCM : 1;
		uint8 U2X  : 1;
		uint8 PE   : 1;
		uint8 DOR  : 1;
		uint8 FE   : 1;
		uint8 UDRE : 1;
		uint8 TXC  : 1;
		uint8 RXC  : 1;
	}bit;
	uint8 Byte ;
}Reg_UCSRA;

// crate union which represent the UCSRB register 
typedef union
{
// create struct Which represent the bits of register
	struct{
		uint8 TXB8  : 1;
		uint8 RXB8  : 1;
		uint8 UCSZ2 : 1;
		uint8 TXEN  : 1;
		uint8 RXEN  : 1;
		uint8 UDRIE : 1;
		uint8 TXCIE : 1;
		uint8 RXCIE : 1;
	}bit;
	uint8 Byte ;
}Reg_UCSRB;

// crate union which represent the UCSRC register 
typedef union
{
// create struct Which represent the bits of register
	struct{
		uint8 UCPOL  : 1;
		uint8 UCSZ0  : 1;
		uint8 UCSZ1 : 1;
		uint8 USBS  : 1;
		uint8 UPM0 : 1;
		uint8 UPM1 : 1;
		uint8 UMSEL : 1;
		uint8 URSEL : 1;
	}bit;
	uint8 Byte ;
}Reg_UCSRC;
// create struct Which represent UART registers
typedef struct
{
	uint8     volatile *const  UBRRH;
	Reg_UCSRC volatile *const  UCSRC;
	uint8     volatile *const  UDR;
	Reg_UCSRA volatile *const  UCSRA;
	Reg_UCSRB volatile *const  UCSRB;
	uint8     volatile *const  UBRRL;
	
}Reg_USART;


#endif /* UART_HW_H_ */