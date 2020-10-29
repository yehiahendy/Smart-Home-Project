/*
 * UART_Config.h
 *
 * Created: 10/12/2020 6:19:03 PM
 *  Author: yehia
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
/************************************************************************
 ************************  UART Mode *************************************
 * Synchrones
 * Asynchrones       
 * Transmitt 
 * Receive                                    
 ************************************************************************/

#define  UART_Mode		   Asynchrones
/************************************************************************
 **************************** UART Speed ****************************
 * normal speed
 * Double speed
 ************************************************************************/

/************************************************************************
 ************************** UART Baud rate values **********************
 * frequency 16000000
 * Baud rate
 * 2400
 * 9600
 * 14.4k
 * 19.2
 * 28.8k
 * 38.4k
 * 57.6k
 * 76.8k
 * 115.2k
 * 230.4k
 * 250k
 * 0.5M
 * 1M
 ************************************************************************/

#define  UART_Speed   normal_Speed
//#define  F_CPU 16000000ul
//#define  BAUD  9600
#define  UBRR_Val    103   // normal mode
/************************************************************************
 = parity =
 * parity_Dis             
 * parity_Even            
 * parity_Odd	
 = Stop Bit =		   
 * Single				   
 * Double	
 = Character_Size =		   
 * Character_Size_5bit    
 * Character_Size_6bit    
 * Character_Size_7bit    
 * Character_Size_8bit    
 ************************************************************************/

#define  UART_parity			parity_Even
#define  UART_Stop_Bit			Single
#define  UART_Character_Size    Character_Size_8bit
#define  String_Size		    5


#endif /* UART_CONFIG_H_ */