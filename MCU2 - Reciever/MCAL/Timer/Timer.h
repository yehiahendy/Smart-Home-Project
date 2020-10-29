/*
 * Timer.h
 *
 * Created: 9/25/2020 6:38:44 AM
 *  Author: yehia
 */ 

#ifndef TIMER_H_
#define TIMER_H_

#include "Timer_hw.h"
#include "../../Util/STD_types.h"

/*========================================
 * Timer0 functions
 *========================================
**/
void Timer0_vidInit(void);
void Timer0_vidStart(void);
void Timer0_vidDisable(void);
void Timer0_vidSetDelay(uint32 u32Delay);

void PWM0_vidInit(void);
void PWM0_vidGenerate(uint8 u8DutyCycle);
void PWM0_vidStart(void);
/*========================================
 * Timer1 functions
 *========================================
**/
void Timer1_vidInit(void);
void Timer1_vidStart(void);
void Timer1_vidDisable(void);
void Timer1_vidSetDely(uint32 u32Delay);

void PWM1_vidInit(void);
void PWM1_vidGenerate(uint8 u8DutyCycle);
void PWM1_vidStart(void);

/*========================================
 * Timer2 functions
 *========================================
**/
void Timer2_vidInit(void);
void Timer2_vidStart(void);
void Timer2_vidDisable(void);
void Timer2_vidSetDely(uint32 u32Delay);

void PWM2_vidInit(void);
void PWM2_vidGenerate(uint8 u8DutyCycle);
void PWM2_vidStart(void);

/*========================================
 * Timer0,2 MSK
 *========================================
**/


/************************************************************************/
/*							    TImer 0,2 modes                         */
/************************************************************************/
#define  Timer_Mode_Clr_Msk                     0b10110111
#define  Timer_Mode_Normal_Msk                  0b00000000
#define  Timer_Mode_PWM_Pashe_correct_Msk       0b01000000
#define  Timer_Mode_CTC_Msk                     0b00001000
#define  Timer_Mode_PWM_Fast_Msk                0b01001000

/************************************************************************/
/*				CTC non-PWM, Fast PWM ,Phase correct                    */
/************************************************************************/
 
#define  Timer0_OC0_Clear_Msk					0b11001111
#define  Timer0_OC0_Dis_Msk					    0b00000000
#define  Timer0_OC0_Toggle_Msk                  0b00010000
#define  Timer0_OC0_ClearPin_Msk                0b00100000
#define  Timer0_OC0_Set_Msk                     0b00110000


/************************************************************************/
/*						     Prescaler                                  */
/************************************************************************/


#define Timer_Prescaler_clr_msk				    0b11111000
#define Timer_Prescaler_off_msk				    0b00000000
#define Timer_Prescaler_No_msk			     	0b00000001
#define Timer_Prescaler_8_msk					0b00000010
#define Timer_Prescaler_64_msk					0b00000011
#define Timer_Prescaler_256_msk				    0b00000100
#define Timer_Prescaler_1024_msk				0b00000101
#define Timer_Prescaler_Ex_Falling_msk		    0b00000110
#define Timer_Prescaler_Ex_Rising_msk		    0b00000111


/*========================================
 * Timer1 MSK
 *========================================
**/


/************************************************************************/
/*							    TImer 1 modes                           */
/************************************************************************/
#define Timer1_Mode_Clr_TCCR1A_Msk                        0b11111100
#define Timer1_Mode_Clr_TCCR1B_Msk                        0b11100111
#define Timer1_Mode_Normal_Msk							  0b00000000
#define Timer_Mode_PWM_Pashe_correct_8bit_Msk             0b00000001
#define Timer_Mode_PWM_Pashe_correct_9bit_Msk             0b00000010
#define Timer_Mode_PWM_Pashe_correct_10bit_Msk            0b00000011
#define Timer_Mode_CTC_OCR1A_Msk						  0b00001000
#define Timer_Mode_PWM_Fast_8bit_Msk					  0b00001001
#define Timer_Mode_PWM_Fast_9bit_Msk				      0b00001010
#define Timer_Mode_PWM_Fast_10bit_Msk                     0b00001011
#define Timer_Mode_PWM_PasheAndFreq_ICR1_Msk              0b00010000
#define Timer_Mode_PWM_PasheAndFreq_OCR1A_Msk             0b00010001
#define Timer_Mode_PWM_Pashe_correct_ICR1_Msk             0b00010010
#define Timer_Mode_PWM_Pashe_correct_OCR1A_Msk            0b00010011
#define Timer_Mode_CTC_ICR1_Msk						      0b00011000				
#define Timer_Mode_PWM_Fast_ICR1_Msk					  0b00011010
#define Timer_Mode_PWM_Fast_OCR1A_Msk				      0b00011011


/************************************************************************/
/*				          CTC non-PWM								    */
/************************************************************************/

 #define  Timer1_OC1_Clear_Msk									0b00001111
 #define Timer1_OC1_Dis_Msk								        0b00000000
 #define Timer1_OC1_Toggle_Msk								    0b01010000
 #define Timer1_OC1_ClearPin_Msk					            0b10100000
 #define Timer1_OC1_Set_Msk                                     0b11110000

#endif /* TIMER_H_ */