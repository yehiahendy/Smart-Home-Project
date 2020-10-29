/*
 * Timer_Config.h
 *
 * Created: 9/30/2020 7:36:13 AM
 *  Author: yehia
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*========================================
 * Timer 0,2 Modes Selector 
 * Timer_Mode_Clr_Msk                     0b10110111
 * Timer_Mode_Normal_Msk                  0b00000000
 * Timer_Mode_PWM_Pashe_correct_Msk       0b01000000
 * Timer_Mode_CTC_Msk                     0b00001000
 * Timer_Mode_PWM_Fast_Msk                0b01001000
 
 *========================================
**/
 #define  Timer0_Mode_Selector			Timer_Mode_PWM_Pashe_correct_Msk
 #define  Timer2_Mode_Selector			Timer_Mode_PWM_Pashe_correct_Msk
 


/*========================================
 *  Timer 0,2 CTC Mode Output 
 *  Timer0_OC0_Clear_Msk               0b11001111
 *  Timer0_OC0_Dis_Msk                 0b00000000
 *  Timer0_OC0_Toggle_Msk              0b00010000
 *  Timer0_OC0_ClearPin_Msk            0b00100000
 *  Timer0_OC0_Set_Msk                 0b00110000
 
 *========================================
**/  
 #define Timer0_Mode_CTC_Selector  Timer0_OC0_Toggle_Msk 
 #define Timer0_Mode_PWM_Selector  Timer0_OC0_ClearPin_Msk

 #define Timer2_Mode_CTC_Selector  Timer0_OC0_Toggle_Msk
 #define Timer2_Mode_PWM_Selector  Timer0_OC0_ClearPin_Msk
 /*========================================
 * Timer 0,1,2 PreScaler Selector  
 * Timer_Prescaler_clr_msk				    0b11111000
 * Timer_Prescaler_off_msk				    0b00000000
 * Timer_Prescaler_No_msk			     	0b00000001
 * Timer_Prescaler_8_msk					0b00000010
 * Timer_Prescaler_64_msk					0b00000011
 * Timer_Prescaler_256_msk				    0b00000100
 * Timer_Prescaler_1024_msk				    0b00000101
 * Timer_Prescaler_Ex_Falling_msk		    0b00000110
 * Timer_Prescaler_Ex_Rising_msk		    0b00000111
 
 *========================================
**/
 
 /************************************************************************/
 /*							    Timer 1 modes      
                  
  * Timer1_Mode_Clr_Msk                               0b11100100
  * Timer1_Mode_Normal_Msk							  0b00000000
  * Timer_Mode_PWM_Pashe_correct_8bit_Msk             0b00000001
  * Timer_Mode_PWM_Pashe_correct_9bit_Msk             0b00000010
  * Timer_Mode_PWM_Pashe_correct_10bit_Msk            0b00000011
  * Timer_Mode_CTC_OCR1A_Msk						  0b00001000
  * Timer_Mode_PWM_Fast_8bit_Msk					  0b00001001
  * Timer_Mode_PWM_Fast_9bit_Msk				      0b00001010
  * Timer_Mode_PWM_Fast_10bit_Msk                     0b00001011
  * Timer_Mode_PWM_PasheAndFreq_ICR1_Msk              0b00010000
  * Timer_Mode_PWM_PasheAndFreq_OCR1A_Msk             0b00010001
  * Timer_Mode_PWM_Pashe_correct_ICR1_Msk             0b00010010
  * Timer_Mode_PWM_Pashe_correct_OCR1A_Msk            0b00010011
  * Timer_Mode_CTC_ICR1_Msk						      0b00011000
  * Timer_Mode_PWM_Fast_ICR1_Msk					  0b00011010
  * Timer_Mode_PWM_Fast_OCR1A_Msk				      0b00011011     
  
 /************************************************************************/
#define FAST										1
#define PhaseCorrect								2
#define  Timer1_Mode_Selector				Timer_Mode_PWM_Fast_8bit_Msk
#define  Timer1_PWM_Mode_Selector			FAST

/************************************************************************/
/*				          CTC non-PWM	
 * Timer1_OC1_Clear_Msk									0b00001111
 * Timer1_OC1_Dis_Msk						          0b00000000
 * Timer1_OC1_Toggle_Msk						      0b01010000
 * Timer1_OC1_ClearPin_Msk					          0b10100000
 * Timer1_OC1_Set_Msk                                0b11110000
 
	
/************************************************************************/

 #define Timer1_OC1A_Mode_Selector             Timer1_OC1_ClearPin_Msk
 #define Timer1_OC1B_Mode_Selector             Timer1_OC1_Set_Msk
 // A for channel A , B for Channel B , M For Both A and B
 #define Timer1_CTC_channel_Selector		   'M'       

 
/*========================================
 * Prescaler Selector
 * Timer_Prescaler_clr_msk				    0b11111000
 * Timer_Prescaler_off_msk				    0b00000000
 * Timer_Prescaler_No_msk			     	0b00000001
 * Timer_Prescaler_8_msk					0b00000010
 * Timer_Prescaler_64_msk					0b00000011
 * Timer_Prescaler_256_msk				    0b00000100
 * Timer_Prescaler_1024_msk					0b00000101
 * Timer_Prescaler_Ex_Falling_msk		    0b00000110
 * Timer_Prescaler_Ex_Rising_msk		    0b00000111
 
*========================================
**/
 
 #define  Timer0_Prescaler_Selector     Timer_Prescaler_1024_msk
 #define  Timer1_Prescaler_Selector     Timer_Prescaler_1024_msk
 #define  Timer2_Prescaler_Selector     Timer_Prescaler_1024_msk
 
 // prescaler 8,64,256,1024 
 #define PRESCALER0      1024
 #define PRESCALER1      1024
 #define PRESCALER2      1024
 
 /*========================================
  * PWM TOP
  * Timer1_Mode_Normal_Msk				0xFFFF
  * Timer_Mode_PWM_Fast_8bit_Msk		0x00FF
  * Timer_Mode_PWM_Fast_9bit_Msk		0x01FF
  * Timer_Mode_PWM_Fast_10bit_Msk		0x03FF
  * Timer_Mode_PWM_Fast_ICR1_Msk		ICR1			
  * Timer_Mode_PWM_Fast_OCR1A_Msk		OCR1A                
 
*========================================*/
  #define  TOP			255

 /*========================================
  * Specification of timer equation 
 
 *========================================
**/

 #define  F_CPU        16000000ul
 #define  TOV_0        ((PRESCALER0*1000000/F_CPU) * 256)
 #define  TOV_1        ((PRESCALER1*1000000/F_CPU) * TOP)
 #define  TOV_2        ((PRESCALER2*1000000/F_CPU) * 256)

 

#endif /* TIMER_CONFIG_H_ */