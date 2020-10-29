/*
 * KeyPad.c
 *
 * Created: 9/8/2020 3:51:07 AM
 *  Author: yehia
 */ 
#include "KeyPad.h"
#ifdef KP_4
unsigned char Keys[4][4]={
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'c','0','=','+'}
};
#endif
#ifdef KP_3
unsigned char Keys[4][3]={
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'},
	{'*','0','#'}
};
#endif
void KP_VidInit(void)
{
	//init the first 4 is output
	Dio_WriteLowNibbleDir(KP_Port,STD_OUT);
	//init the last 4 is input
	Dio_WriteHighNibbleDir(KP_Port,STD_IN);
	//make the input pins pull up
	Dio_WritePortLevel(KP_Port,STD_high);
}
uint8 KP_u8GetKey()
{
	uint8 u8RetKey = '\0';
	#ifdef KP_4
	
		for (uint8 row = 0; row < 4; row ++)
		{
			Dio_WritePortLevel(KP_Port,STD_high);
			DIO_WritePin(KP_Port,row,STD_low);
			for (uint8 col = 0; col < 4; col ++)
			{
				if ((DIO_ReadPin(KP_Port,col+4)) == 0)
				{
					if ((DIO_ReadPin(KP_Port,col+4)) == 0)
					{
						u8RetKey = Keys[row][col];
					}
				}

			}
		}
		return u8RetKey;
	#endif
		#ifdef KP_3
		while (1)
		{
			for (uint8 row = 0; row < 4; row ++)
			{
				Dio_WritePortLevel(KP_Port,STD_high);
				DIO_WritePin(KP_Port,row,STD_low);
				for (uint8 col = 0; col < 3; col ++)
				{
					if ((DIO_ReadPin(KP_Port,col+4)) == 0)
					{
						_delay_ms(1100);
						if ((DIO_ReadPin(KP_Port,col+4)) == 0)
						{
							u8RetKey = Keys[row][col];
							
						}
					}

				}
			}
			if (u8RetKey != '\0') break;

		}
			return u8RetKey ;
		#endif
}
