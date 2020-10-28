/*
 * UART.h
 *
 * Created: 10/12/2020 7:06:47 AM
 *  Author: yehia
 */ 


#ifndef UART_H_
#define UART_H_
#include "../../Util/STD_types.h"
#include "UART_HW.h"
#include "../../Config/UART_Config.h"
#define F_CPU 16000000ul
/************************************************************************
 *  UART Functions                                                                    
 ************************************************************************/

void   UART_vidInit();
void   UART_vidSendData(uint8 u8data);
void   UART_vidSendString(uint8* u8data);
uint8  UART_u8ReadData(void);
uint8  *UART_u8ReadString(void);


/************************************************************************
 *  UART definitions                                                                      
 ************************************************************************/
//mode
#define Asynchrones            0
#define Synchrones             1
//speed
#define normal_Speed           0
#define double_Speed           1
// parity 
#define parity_Clr_MSK         0b11001111
#define parity_Dis             0b00000000
#define parity_Even            0b00100000
#define parity_Odd			   0b00110000
// Stop bit
#define Single				   0
#define Double				   1
//Character Size
#define Character_Size_Clr_MSK   0b11111001
#define Character_Size_5bit      0b00000000
#define Character_Size_6bit      0b00000010
#define Character_Size_7bit      0b00000100
#define Character_Size_8bit      0b00000110





#endif /* UART_H_ */
