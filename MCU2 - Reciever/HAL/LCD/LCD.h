/*
 * LCD.h
 *
 * Created: 9/3/2020 2:41:01 AM
 *  Author: yehia
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../../MCAL/DIO/DIO.h"
#define F_CPU 16000000ul
#include <util/delay.h>
#define LCD_Port         'A'
#define LCD_ControlPort  'B'
#define LCD_RS             0
#define LCD_Rw             1
#define LCD_E              2
/*
#define LCD_D0             0
#define LCD_D1             1
#define LCD_D2             2
#define LCD_D3             3
#define LCD_D4             4
#define LCD_D5             5
#define LCD_D6             6
#define LCD_D7             7
*/
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_RAW						(0x80)
#define LCD_BEGIN_AT_SECOND_RAW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)
#define Four_Bit

void LCD_init();
void LCD_kick ();
void LCD_SendCommand(uint8 command);
void LCD_SendData(uint8 data);
void LCD_WriteString(uint8 *string);
void LCD_clearScreen ();
void LCD_GotoXY(uint8 x, uint8 y);
void LCD_SendNumber (uint16 Number);
void LCD_SendRealNumber (float32  Number );
void LCD_CreatChar(uint8 charnum,uint8 a_NewShape[] );
void LCD_Move_Right(uint8 string[]);
void LCD_Move_Left(uint8 string[]);


#endif /* LCD_H_ */