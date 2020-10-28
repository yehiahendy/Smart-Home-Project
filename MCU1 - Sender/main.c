/*
 * Final_Project_Componant1.c
 *
 * Created: 10/23/2020 3:43:53 AM
 * Author : yehia
 */ 
#define F_CPU 1600000
#include "Display.h"
#include "Control.h"
#include "HAL/PIR Sensor/PIR.h"
#include "MCAL/SPI/SPI.h"
#include "HAL/Bluetooth hc-05/Bluetooth.h"

int main(void)
{
	DIO_WritePinDir('d',2,STD_OUT); 
	DIO_WritePin('d',2,STD_low); // disable the second MCU
   const uint8 reset[] = "*#0*#"; //reset pass code
   uint8 selector, passCount = 0; 
   uint8 BluetoothData;
   Bluetooth_vidInit(); // initiate Bluetooth module 
   SPI_vidInit();      //initiate SPI Communication protocol
   LCD_init();        // initiate LCD
   KP_VidInit();     // initiate Keypad
   PIR_vidInit();   // initiate PIR Sensor
   while(PIR_CheckHuman() != 1) // check if there's no people at home
    vidDisplay_Home();        // animation 
    while (1)
    {
	    vidDisplay_Selections(); // show the selections
	    selector = KP_u8GetKey(); // get the user selection 
	    LCD_clearScreen();        // clear LCD
	    switch(selector)
	    {
		    case '1' :
		    
		    LCD_WriteString("Enter Pass");   //ask the user to enter the password
		    LCD_GotoXY(1,0);
		    while (passCount < 3)
		    {
				/*
				   if the password was correct show  welcome message on LCD 
				   and get commands from the user using Bluetooth
				   then send coomands to the other MCU using SPI 
				  */
			    if (enter_Password() == true)
			    {
					LCD_clearScreen();
				    LCD_WriteString("Welcome Yehia");
					_delay_ms(1000);
					LCD_clearScreen();
					UART_vidSendString("A for first LED\r\n");
					UART_vidSendString("B for second LED \r\n");
					UART_vidSendString("C for third LED \r\n");
					DIO_WritePin('d',2,STD_high);
					while(1)
					{
						//receive data via bluetooth
						
						BluetoothData = Bluetooth_u8ReceivedData();
						Bluetooth_vidSendData('\r');
						Bluetooth_vidSendData('\n');
						if (BluetoothData != '\0')
						{
							//send data via SPI 
							SPI_Send_Date(BluetoothData);
							_delay_ms(5);
							SPI_Send_Date(BluetoothData);
							_delay_ms(5);
							
						}
					}
			    }
			    else
			    {
					/*
					the user can't enters the password more than 3 times
					*/
					LCD_clearScreen();
				    passCount++;
				    LCD_WriteString("Try again");
				    _delay_ms(500);
				    LCD_clearScreen();
			    }
		    }
		    break;
		    case '2' :
			/*
			the second choice is to reset the password or 
			set it for the first time */ 
		    LCD_clearScreen();
		    LCD_WriteString("reset code");
			LCD_GotoXY(1,0);
		    if (change_Password(reset) == true)
		    {
				LCD_clearScreen();
			    LCD_WriteString("Reset done");
				_delay_ms(500);
		    }
	    }//switch
		if (passCount == 3)
		{
			LCD_WriteString("Sorry");
			break;
		}
    }//while 1

 }//main
