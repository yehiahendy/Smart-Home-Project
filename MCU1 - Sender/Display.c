/*
 * Display.c
 *
 * Created: 10/23/2020 5:20:53 AM
 *  Author: yehia
 */ 
#include "Display.h"
void vidDisplay_Home()
{
	uint8 HomeUpper[8] =
	{
  0x04,
  0x0A,
  0x11,
  0x1F,
  0x11,
  0x11,
  0x1F,
  0x00
  };
		LCD_CreatChar(0,HomeUpper);
	for (unsigned int i = 0 ; i < 2 ;i++ )
	{
		for (unsigned int j = 0 ; j < 16;j++)
		{
			LCD_GotoXY(i,j);
			LCD_SendData(0);
		}
	}
}
void vidDisplay_Selections()
{
	LCD_clearScreen();
	LCD_GotoXY(0,5);
	LCD_WriteString("Welcome");
	_delay_ms(500);
	LCD_clearScreen();
	LCD_WriteString("1-Enter Password");
	LCD_GotoXY(1,0);
	LCD_WriteString("2-Set password");
}
