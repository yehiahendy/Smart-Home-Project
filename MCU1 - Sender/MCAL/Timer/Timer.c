/*
 * Timer.c
 *
 * Created: 9/25/2020 6:39:36 AM
 *  Author: yehia
 */ 
#include "Timer.h"
#include "../../Config/Timer_Config.h"
#define  F_CPU 16000000ul
/*========================================
 * Timer0 functions
 *========================================
**/
void Timer0_vidInit(void)
{
 #if (Timer0_Mode_Selector == Timer_Mode_Normal_Msk)

	//Enable interrupt
	SET_Bit(TIMSK,TOIE0);
	//select Normal mode 
	TCCR0 = 0x00;
	TCCR0 &= Timer_Mode_Clr_Msk;
	TCCR0 |=  Timer0_Mode_Selector;
	CLEAR_Bit(TCCR0,COM00);
	CLEAR_Bit(TCCR0,COM01);
#endif
	/* check if the mode is CTC,Fast PWM or phase correct  
	thus chose the config of OC0*/
	#if (Timer0_Mode_Selector == Timer_Mode_CTC_Msk)
	 SET_Bit(TIMSK,OCIE0);
	TCCR0 &=  Timer0_OC0_Clear_Msk;
	TCCR0 |=  Timer0_Mode_CTC_Selector;
#endif
}
void Timer0_vidStart(void)
{		//Start the timer by selecting the prescaler value
		TCCR0 &=  Timer_Prescaler_clr_msk;
		TCCR0 |=  Timer0_Prescaler_Selector;
}
void Timer0_vidDisable(void)
{		//choose no prescaler 
		TCCR0 &=  Timer_Prescaler_clr_msk;
		TCCR0 |=  Timer_Prescaler_off_msk;
}
/* s32Delay  in ms */ 
void Timer0_vidSetDelay(uint32 u32Delay)
{

	#if (Timer0_Mode_Selector == Timer_Mode_Normal_Msk )
	//volatile to avoid the optimization 
		volatile uint8 u8PreLoad = 0;
		volatile uint16 	count = 0;
	if ((u32Delay*1000) == TOV_0) //if the time is equal to the overflow time 
	{
		TCNT0 = 0x00;
		Timer0_vidStart(); //start timer0
		while((GET_Bit(TIFR,TOV0)) == 0); //wait till time overflow occurs 
		SET_Bit(TIFR,TOV0);				//clear timer overflow flag by software
	}
	else if ((u32Delay*1000) < TOV_0) 
	{
		u8PreLoad = 255- ((u32Delay*1000)/(PRESCALER0*1000000/F_CPU)); //preload value 
		TCNT0 = u8PreLoad;
		Timer0_vidStart();
		while((GET_Bit(TIFR,TOV0)) == 0);//wait till time overflow occurs 
		SET_Bit(TIFR,TOV0);				//clear timer overflow flag by software
	}
	else
	{
		count = (u32Delay*1000)/TOV_0; //counter of  overflows 
		u8PreLoad = 255- ((((float)(u32Delay*1000)/TOV_0) - count) *256); //preload value
		TCNT0 = u8PreLoad;
		count = (u32Delay*1000)/TOV_0;
		Timer0_vidStart(); //start timer0
		/*wait to finish all overflows*/
	    while (count)
	    {
		    while((GET_Bit(TIFR,TOV0)) == 0)
		    {
			    ;
		    };
		    count--;
		    TCNT0=0;
		    SET_Bit(TIFR,TOV0);
	    }

    }
	#elif (Timer0_Mode_Selector == Timer_Mode_CTC_Msk ) // CTC Mode
	 if ((u32Delay*1000) < TOV_0)
	{
		OCR0 = (u32Delay*1000)/(PRESCALER0*1000000/F_CPU);
		
		Timer0_vidStart();
		while((GET_Bit(TIFR,OCF0)) == 0);

	}
	else {}
	#endif

}	

void PWM0_vidInit(void)
{

		//chose PWM mode
		TCCR0 &= Timer_Mode_Clr_Msk;
		TCCR0 |= Timer0_Mode_Selector;
		//chose PWM mode ( non-inverting or inverting )
		TCCR0 &= Timer0_OC0_Clear_Msk;
		TCCR0 |= Timer0_Mode_PWM_Selector; 
		
}
void PWM0_vidGenerate(uint8 u8DutyCycle)
{
	//volatile to avoid the optimization
	volatile uint8 u8data;
	#if (Timer0_Mode_Selector == Timer_Mode_PWM_Fast_Msk)
	#if (Timer0_Mode_PWM_Selector == Timer0_OC0_ClearPin_Msk) ///non inverting mode
	u8data = ((256*u8DutyCycle)/100)-1 ;    //calculate the val of OCR            
	OCR0 = u8data;
   #endif
	#if (Timer0_Mode_PWM_Selector == Timer0_OC0_Set_Msk) /// inverting mode
	u8data = 255-((u8DutyCycle*256)/100);  //calculate the val of OCR  
	OCR0 = u8data;
	#endif
    #elif (Timer0_Mode_Selector == Timer_Mode_PWM_Pashe_correct_Msk)
    #if (Timer0_Mode_PWM_Selector == Timer0_OC0_ClearPin_Msk) ///non inverting mode
    u8data = (255*u8DutyCycle)/100 ;  //calculate the val of OCR  
    OCR0 = u8data;
    
    #endif
    #if (Timer0_Mode_PWM_Selector == Timer0_OC0_Set_Msk) /// inverting mode
    u8data = 255-((u8DutyCycle*255)/100);
    OCR0 = u8data;
    #endif
    #endif
	
}
void PWM0_vidStart(void)
{
		TCCR0 &=  Timer_Prescaler_clr_msk;
    	TCCR0 |=  Timer0_Prescaler_Selector;
}

/*========================================
 * Timer2 functions
 *========================================
**/

void Timer2_vidInit(void)
{
 #if (Timer2_Mode_Selector == Timer_Mode_Normal_Msk)

	//Enable interrupt
	SET_Bit(TIMSK,TOIE2);
	//select the mode
	TCCR2 = 0x00;
	TCCR2 &= Timer_Mode_Clr_Msk;
	TCCR2 |=  Timer2_Mode_Selector;
	CLEAR_Bit(TCCR2,COM20);
	CLEAR_Bit(TCCR2,COM21);
#endif
	/* check if the mode is CTC,Fast PWM or phase correct  
	thus chose the config of OC0*/
	
	#if (Timer2_Mode_Selector == Timer_Mode_CTC_Msk)
	 SET_Bit(TIMSK,OCIE2);
	TCCR2 &=  Timer0_OC0_Clear_Msk;
	TCCR2 |=  Timer2_Mode_CTC_Selector;
#endif
}
void Timer2_vidStart(void)
{
		TCCR2 &=  Timer_Prescaler_clr_msk;
		TCCR2 |=  Timer2_Prescaler_Selector;
}
void Timer2_vidDisable(void)
{
		TCCR2 &=  Timer_Prescaler_clr_msk;
		TCCR2 |=  Timer_Prescaler_off_msk;
}
/* s32Delay  in ms */ 

void Timer2_vidSetDelay(uint32 u32Delay)
{

	#if (Timer2_Mode_Selector == Timer_Mode_Normal_Msk )
		volatile uint8 u8PreLoad = 0;
		volatile uint16 	count = 0;
	if ((u32Delay*1000) == TOV_2)
	{
		TCNT2 = 0x00;
		Timer2_vidStart();
		while((GET_Bit(TIFR,TOV2)) == 0);
		SET_Bit(TIFR,TOV2);
	}
	else if ((u32Delay*1000) < TOV_2)
	{
		u8PreLoad = 255- ((u32Delay*1000)/(PRESCALER2*1000000/F_CPU));
		TCNT2 = u8PreLoad;
		Timer2_vidStart();
		while((GET_Bit(TIFR,TOV2)) == 0);
		SET_Bit(TIFR,TOV2);
	}
	else
	{
		
		count = (u32Delay*1000)/TOV_2;
		u8PreLoad = 255- ((((float)(u32Delay*1000)/TOV_2) - count) *256);
		TCNT2 = u8PreLoad;
		count = (u32Delay*1000)/TOV_2;
		Timer2_vidStart();
	    while (count)
	    {
		    while((GET_Bit(TIFR,TOV2)) == 0)
		    {
			    ;
		    };
		    count--;
		    TCNT2=0;
		    SET_Bit(TIFR,TOV2);
		    
	    }

    }
	#elif (Timer2_Mode_Selector == Timer_Mode_CTC_Msk )
	 if ((u32Delay*1000) < TOV_2)
	{
		OCR2 = (u32Delay*1000)/(PRESCALER2*1000000/F_CPU);
		
		Timer2_vidStart();
		while((GET_Bit(TIFR,OCF2)) == 0);

	}
	else {}
	#endif

}	

void PWM2_vidInit(void)
{

		//chose PWM mode
		TCCR2 &= Timer_Mode_Clr_Msk;
		TCCR2 |= Timer2_Mode_Selector;
		//chose PWM mode ( non-inverting or inverting )
		TCCR2 &= Timer0_OC0_Clear_Msk;
		TCCR2 |= Timer2_Mode_CTC_Selector;
		
		
}
void PWM2_vidGenerate(uint8 u8DutyCycle)
{
	volatile uint8 u8data=0;
	#if (Timer2_Mode_Selector == Timer_Mode_PWM_Fast_Msk)
	#if (Timer2_Mode_PWM_Selector == Timer0_OC0_ClearPin_Msk) ///non inverting mode
	u8data = ((256*u8DutyCycle)/100)-1 ;
	OCR2 = u8data;
	
	
   #endif
	#if (Timer2_Mode_PWM_Selector == Timer0_OC0_Set_Msk) /// inverting mode
	u8data = 255-((u8DutyCycle*256)/100);
	OCR2 = u8data;
	
	#endif
	
    #elif (Timer2_Mode_Selector == Timer_Mode_PWM_Pashe_correct_Msk)
		#if (Timer2_Mode_PWM_Selector == Timer0_OC0_ClearPin_Msk) ///non inverting mode
		u8data = (255*u8DutyCycle)/100 ;
		OCR2 = u8data;	
		#endif
		#if (Timer2_Mode_PWM_Selector == Timer0_OC0_Set_Msk) /// inverting mode
		u8data = 255-((u8DutyCycle*255)/100);
		OCR2 = u8data;
		#endif
		#endif
	
}
void PWM2_vidStart(void)
{
		TCCR2 &=  Timer_Prescaler_clr_msk;
    	TCCR2 |=  Timer2_Prescaler_Selector;
}
/*========================================
 * Timer1 functions
 *========================================
**/

void Timer1_vidInit(void)
{
	//Clear TCCR1B register 
	TCCR1B &= 0x00;
	//Clear TCCR1A register
	TCCR1A &= 0x00;
	//Check  the selected Mode
	#if (Timer1_Mode_Selector == Timer1_Mode_Normal_Msk)
	//Enable Timer OverFlow 
	SET_Bit(TIMSK,TOIE1);
	// Select Normal Mode 
	TCCR1A &= Timer1_Mode_Clr_TCCR1A_Msk;
	TCCR1A |= Timer1_Mode_Normal_Msk;
	TCCR1B &= Timer1_Mode_Clr_TCCR1B_Msk;
	TCCR1B |= Timer1_Mode_Normal_Msk;
	
	#elif (Timer1_Mode_Selector == Timer_Mode_CTC_OCR1A_Msk)
	//Enable Timer OCF1A Flag
	SET_Bit(TIMSK,OCF1A);
	// Select  Mode
	TCCR1A &= Timer1_Mode_Clr_TCCR1A_Msk;
	TCCR1A |= Timer1_Mode_Selector;
	TCCR1B &= Timer1_Mode_Clr_TCCR1B_Msk;
	TCCR1B |= ((Timer1_Mode_Selector>>3)<<3);
	//Select the OC1x Mode
	#if (Timer1_CTC_channel_Selector == 'A' )
	TCCR1A &= Timer1_OC1_Clear_Msk;
	//to Select only OC1A
	TCCR1A |= (Timer1_OC1A_Mode_Selector & 0xC0);
	#elif  (Timer1_CTC_channel_Selector == 'B' )
	TCCR1A &= Timer1_OC1_Clear_Msk;
	//to Select only OC1B
	TCCR1A |= (Timer1_OC1B_Mode_Selector & 0x30);
	#elif  (Timer1_CTC_channel_Selector == 'M' )
	TCCR1A &= Timer1_OC1_Clear_Msk;
	//to Select  OC1A,OC1B
	TCCR1A |= (Timer1_OC1A_Mode_Selector & 0xC0);
	TCCR1A |= (Timer1_OC1B_Mode_Selector & 0x30);
	#endif
	//to choose ICR instade of  OCR1x
	#elif (Timer1_Mode_Selector == Timer_Mode_CTC_ICR1_Msk)
	//Enable Timer ICF1 Flag
	SET_Bit(TIMSK,ICF1);
	// Select  Mode
	TCCR1A &= Timer1_Mode_Clr_TCCR1A_Msk;
	TCCR1A |= Timer1_Mode_Selector;
	TCCR1B &= Timer1_Mode_Clr_TCCR1B_Msk;
	TCCR1B |= ((Timer1_Mode_Selector>>3)<<3);
	//Select the OC1x Mode
	#if (Timer1_CTC_channel_Selector == 'A' )
	TCCR1A &= Timer1_OC1_Clear_Msk;
	//to Select only OC1A
	TCCR1A |= (Timer1_OC1A_Mode_Selector & 0xC0);
	#elif  (Timer1_CTC_channel_Selector == 'B' )
	TCCR1A &= Timer1_OC1_Clear_Msk;
	//to Select only OC1B
	TCCR1A |= (Timer1_OC1B_Mode_Selector & 0x30);
	#elif  (Timer1_CTC_channel_Selector == 'M' )
	TCCR1A &= Timer1_OC1_Clear_Msk;
	//to Select  OC1A,OC1B
	TCCR1A |= (Timer1_OC1A_Mode_Selector & 0xC0);
	TCCR1A |= (Timer1_OC1B_Mode_Selector & 0x30);
	#endif
	#endif
	
}
void Timer1_vidStart(void)
{
	//Start the timer by selecting the prescaler value 
	TCCR1B &= Timer_Prescaler_clr_msk;
	TCCR1B |= Timer1_Prescaler_Selector;
}
void Timer1_vidDisable(void)
{
		//Turn of  the timer 
		TCCR1B &= Timer_Prescaler_clr_msk;
		TCCR1B |= Timer_Prescaler_off_msk;
}

void Timer1_vidSetDely(uint32 u32Delay)
{

	#if (Timer1_Mode_Selector == Timer1_Mode_Normal_Msk )
	//volatile to avoid the optimization
	volatile uint16 u16PreLoad = 0;
	
	if ((u32Delay*1000) == TOV_1) //if the time is equal to the overflow time
	{
		TCNT1 = 0;
		Timer1_vidStart();//start timer 1
		while((GET_Bit(TIFR,TOV1)) == 0); //wait till  timer1 overflow 
		SET_Bit(TIFR,TOV1);				//clear timer overflow flag by software
	}
	else if ((u32Delay*1000) < TOV_1)
	{
		u16PreLoad = TOP- ((u32Delay*1000)/(PRESCALER1*1000000/F_CPU)); //preload value 
		TCNT1 = u16PreLoad;  
		Timer1_vidStart(); //start timer 1
		while((GET_Bit(TIFR,TOV1)) == 0);//wait till  timer1 overflow
		SET_Bit(TIFR,TOV1); //clear timer overflow flag by software
	}
	else
	{
		
		volatile uint16 u16Count = 0; //volatile to avoid the optimization
		u16Count = (u32Delay*1000)/TOV_1;//counter of  overflows 
		u16PreLoad = TOP- (((float)(u32Delay*1000)/TOV_1) - u16Count) *(TOP+1);//preload value
		TCNT1 = u16PreLoad;
		u16Count = (u32Delay*1000)/TOV_1;
		Timer1_vidStart(); //start timer 1
		/*wait to finish all overflows*/

		while (u16Count)
		{
			while((GET_Bit(TIFR,TOV1)) == 0)
			{
				;
			};
			u16Count--;
			TCNT1=0;
			SET_Bit(TIFR,TOV1);
			
		}

	}
	#elif (Timer1_Mode_Selector == Timer_Mode_CTC_OCR1A_Msk ) //CTC Mode using OCR1x
		 if ((u32Delay*1000) < TOV_1)
		 {
			 OCR1A = (u32Delay*1000)/(PRESCALER1*1000000/F_CPU);
			 Timer1_vidStart();
			 while((GET_Bit(TIFR,OCF1A)) == 0);
			SET_Bit(TIFR,OCF1A);
		 }
		 else {}
	#elif (Timer1_Mode_Selector == Timer_Mode_CTC_ICR1_Msk ) //CTC Mode using ICRx
	if ((u32Delay*1000) < TOV_1)
	{
		ICR = (u32Delay*1000)/(PRESCALER1*1000000/F_CPU);
		Timer1_vidStart();
		while((GET_Bit(TIFR,ICF1)) == 0);
		SET_Bit(TIFR,ICF1);
	}
	else {}
		
 #endif
}



void PWM1_vidInit(void)
{
	// Select Normal Mode
	TCCR1A &= Timer1_Mode_Clr_TCCR1A_Msk;
	TCCR1A |= Timer1_Mode_Selector;
	TCCR1B &= Timer1_Mode_Clr_TCCR1B_Msk;
	TCCR1B |= ((Timer1_Mode_Selector>>3)<<3);
	//Select CTC A Or B or A&B
	#if (Timer1_CTC_channel_Selector == 'A' )
	TCCR1A &= Timer1_OC1_Clear_Msk;
	TCCR1A |= (Timer1_OC1A_Mode_Selector & 0xC0);
	#endif
	#if  (Timer1_CTC_channel_Selector == 'B' )
	TCCR1A &= Timer1_OC1_Clear_Msk;
	TCCR1A |= (Timer1_OC1B_Mode_Selector & 0x30);
	#endif
	#if  (Timer1_CTC_channel_Selector == 'M' )
	TCCR1A &= Timer1_OC1_Clear_Msk;
	TCCR1A |= (Timer1_OC1A_Mode_Selector & 0xC0);
	TCCR1A |= (Timer1_OC1B_Mode_Selector & 0x30);
	#endif
}
void PWM1_vidGenerate(uint8 u8DutyCycle)

{
	volatile uint16 u16Data=0;
	#if (Timer1_PWM_Mode_Selector == FAST)
	#if ((Timer1_OC1A_Mode_Selector == Timer1_OC1_ClearPin_Msk) ||(Timer1_OC1B_Mode_Selector == Timer1_OC1_ClearPin_Msk))
	u16Data = (((TOP+1)*u8DutyCycle)/100)-1 ;///non inverting mode
	#endif
	#if ((Timer1_OC1A_Mode_Selector == Timer1_OC1_Set_Msk) ||(Timer1_OC1B_Mode_Selector == Timer1_OC1_Set_Msk))/// inverting mode
	#if  (Timer1_CTC_channel_Selector == 'M' )
	OCR1A = u16Data;
	#endif
	u16Data = TOP-(((TOP+1)*u8DutyCycle)/100);
	OCR1B = u16Data;
	#endif
	#elif (Timer1_PWM_Mode_Selector == PhaseCorrect)
	#if ((Timer1_OC1A_Mode_Selector == Timer1_OC1_ClearPin_Msk) ||(Timer1_OC1B_Mode_Selector == Timer1_OC1_ClearPin_Msk))
	u16Data = ((TOP*u8DutyCycle)/100) ;///non inverting mode
	#endif
	#if ((Timer1_OC1A_Mode_Selector == Timer1_OC1_Set_Msk) ||(Timer1_OC1B_Mode_Selector == Timer1_OC1_Set_Msk))/// inverting mode
	#if  (Timer1_CTC_channel_Selector == 'M' )
	OCR1A = u16Data;
	#endif
	u16Data = TOP-((TOP*u8DutyCycle)/100);
	OCR1B = u16Data;
	#endif
	#endif

	#if (Timer1_CTC_channel_Selector == 'A')
	 OCR1A = u16Data;
	#elif (Timer1_CTC_channel_Selector == 'B')
	OCR1B = u16Data;

	#endif
	
}
void PWM1_vidStart(void)
{
	//Start the timer by selecting the prescaler value
	TCCR1B &= Timer_Prescaler_clr_msk;
	TCCR1B |= Timer1_Prescaler_Selector;
}