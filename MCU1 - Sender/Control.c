/*
 * Control.c
 *
 * Created: 10/24/2020 8:26:03 AM
 *  Author: yehia
 */ 
#include "Control.h"
#include "HAL/LCD/LCD.h"
 boolean enter_Password(void)
{
	uint8 pass[5],temp;
	uint8 i = 0;
	pass[4] = '\0';
	while ( i < 4)
	{   
		pass[i] = KP_u8GetKey();   //get the password from the user
		LCD_SendData('*');
		i++;
	}
	i = 0;
	temp = 0 ;
	while ( i < 4)
	{
		temp = Internal_u8EEPROM_Read(i);  //compare it with the saved password in EEPROM
		
		if (temp != pass[i])
		{
			return false;
		}
		i++;
	}
	return true ; 
			
}

boolean change_Password(uint8* code)
{
	uint8 temp , i = 0;
	while ( i < 5)
	{
		temp = KP_u8GetKey();
		if (temp != code[i])
		{
			return false;
		}
		
		LCD_SendData('*');
		i++;
	}
	LCD_clearScreen();
	LCD_WriteString("New password");
	LCD_GotoXY(1,0);
	for (i = 0; i < 4;i++)
	{
		  temp = KP_u8GetKey();
		  LCD_SendData('*');
	     Internal_vidEEPROM_Write(i,temp);
	}
	return true;
	
}