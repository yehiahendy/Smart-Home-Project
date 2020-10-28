/*
 * LCD.c
 *
 * Created: 9/3/2020 2:41:35 AM
 *  Author: yehia
 */ 
#include "LCD.h"
void LCD_kick ()
{
	DIO_WritePin(LCD_ControlPort,LCD_E,STD_high);
	_delay_us(1);
	DIO_WritePin(LCD_ControlPort,LCD_E,STD_low);
}
void LCD_init()
{
	//port initialization 
	DIO_WritePinDir(LCD_ControlPort,LCD_RS,STD_OUT);
	DIO_WritePinDir(LCD_ControlPort,LCD_Rw,STD_OUT);
	DIO_WritePinDir(LCD_ControlPort,LCD_E,STD_OUT);
	Dio_WriteHighNibbleDir(LCD_Port,STD_OUT);
	
	#ifdef Eigh_Bit
	Dio_WriteLowNibbleDir(LCD_Port,STD_OUT);
	#endif
	_delay_ms(15);
	//LCD initialization
	
	#ifdef Four_Bit
			LCD_SendCommand(0x33);
			LCD_SendCommand(0x32);
			LCD_SendCommand(LCD_FUNCTION_4BIT_2LINES);
			LCD_SendCommand(LCD_DISP_ON_CURSOR);
			LCD_SendCommand(LCD_CLEAR_SCREEN);
			LCD_SendCommand(LCD_ENTRY_INC_);
	#endif
		#ifdef Eight_Bit
		LCD_SendCommand(0x33);
		LCD_SendCommand(0x32);
		LCD_SendCommand(LCD_FUNCTION_8BIT_2LINES);
		LCD_SendCommand(LCD_DISP_ON_CURSOR_BLINK);
		LCD_SendCommand(LCD_CLEAR_SCREEN);
		LCD_SendCommand(LCD_ENTRY_INC_);
		#endif
	
	
	
}
void LCD_SendCommand(uint8 cmd)
{
	//set RS and RW 
	DIO_WritePin(LCD_ControlPort,LCD_RS,STD_low);
	DIO_WritePin(LCD_ControlPort,LCD_Rw,STD_low);

	
	#ifdef Four_Bit
			// put half of command on LCD
			Dio_WriteHighNibbleVal(LCD_Port,cmd);
			//Enable
			LCD_kick();
			//put the other half
			Dio_WriteHighNibbleVal(LCD_Port,(cmd<<4));
			//Enable
			LCD_kick();
			
    #endif
	
	#ifdef Eight_Bit
			// put the command on the port 
			Dio_WritePortVal(LCD_Port,cmd);
			//Enable
			LCD_kick();
	#endif
	_delay_ms(10);
		
}
void LCD_SendData(uint8 data)
{
	//set RS and RW
	DIO_WritePin(LCD_ControlPort,LCD_RS,STD_high);
	DIO_WritePin(LCD_ControlPort,LCD_Rw,STD_low);
	#ifdef Four_Bit
	// put half of command on LCD
	Dio_WriteHighNibbleVal(LCD_Port,data);
	//Enable
	LCD_kick();
	//put the other half
	Dio_WriteHighNibbleVal(LCD_Port,(data<<4));
	//Enable
	LCD_kick();
	#endif
	
	#ifdef Eight_Bit
	// put the command on the port
	Dio_WritePortVal(LCD_Port,data);
	//Enable
	LCD_kick();
	#endif	
	_delay_ms(10);
}
void LCD_WriteString(uint8 *string)
{
	uint8  i =0;
	while(string[i] != '\0')
	{
		LCD_SendData(string[i]);
		i++;
	}
}
void LCD_clearScreen ()
{
	LCD_SendCommand(LCD_CLEAR_SCREEN);
}
void LCD_GotoXY(uint8 x, uint8 y)
{
	if (x == 0)
	{
		LCD_SendCommand(LCD_BEGIN_AT_FIRST_RAW + y);
	}
	else
	{
		LCD_SendCommand(LCD_BEGIN_AT_SECOND_RAW + y);
	}
}
void LCD_SendNumber (uint16 Number)
{
	uint8 string[16];
	//covert number from int to string
	LCD_WriteString(itoa(Number,string,10));
}

void LCD_SendRealNumber (float32  Number )
{
	
	//create the array of char
	uint8 string[16],sign;
	//check if the number is positive or negative 
	//put the sign in the array
	sign = Number < 0 ? '-' : ' ';
	// if the number is negative make it positive
	Number = Number < 0 ? -Number : Number;
	//put the number in integer to neglect the sign 
	uint16 i = Number;
	//make the decimel   integer 
	uint16 decimel = (Number-i)*1000 ;
	
	sprintf(string ,"%c%d.%03d",sign,i,decimel);
	LCD_WriteString(string);
}
void LCD_CreatChar(uint8 charnum,uint8 a_NewShape[] )
{
	/*CGRAM address 0x40,48,50...
    you can make 8 custom characters */
int i;
LCD_SendCommand((0x40) +(charnum*8));
for(i=0;i<8;i++)
{
	LCD_SendData(a_NewShape[i]);
}
	
}

void LCD_Move_Right(uint8 string[])
{
	for (uint8 i = 0 ; i < 16 - strlen(string) ;i++)
	{
		LCD_GotoXY(0,i);
		LCD_WriteString(string);
		_delay_ms(500);
		LCD_clearScreen();
	}
}
void LCD_Move_Left(uint8 string[])
{
	uint8 i = 16 - strlen(string);
	for (i ; i >0  ;i--)
	{
		LCD_GotoXY(0,i);
		LCD_WriteString(string);
		_delay_ms(500);
		LCD_clearScreen();
	}
}