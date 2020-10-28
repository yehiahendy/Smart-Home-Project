/*
 * ADC.h
 *
 * Created: 9/23/2020 7:43:29 PM
 *  Author: yehia
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "ADC_types.h"
#include "../../Config/ADC_config.h"
#include "ADC_hw.h"
#include "../../Util/BIT_MATH.h"
#include "../../Util/STD_types.h"
#define ADEN      7
#define ADSC      6
#define ADATE     5
#define ADIF      4
#define ADIE      3
/*=============================================================
 * Reference Analog Channel Bits
 * ============================================================
 **/
#define  ADC_VoltageReference_clr_msk	     0b00111111
#define ADC_VoltageReference_AREF_msk		 0b00000000	
#define ADC_VoltageReference_AVCC_msk		 0b01000000
#define ADC_VoltageReference_2_56V_msk	     0b11000000
/*=============================================================
 * ADC Adjust Result
 * ============================================================
**/
#define ADC_Adjust_clr_msk	     0b11011111
#define ADC_Adjust_Left_msk	     0b00100000	
#define ADC_Adjust_Right_msk	 0b00000000
/*=============================================================
 * ADC Prescaler Select Bits
 * ============================================================
**/
#define ADC_Prescaler_clr_msk				0b11111000
//#define ADC_Prescaler_2_msk					0b00000000
#define ADC_Prescaler_2_msk					0b00000001
#define ADC_Prescaler_4_msk					0b00000010
#define ADC_Prescaler_8_msk					0b00000011
#define ADC_Prescaler_16_msk				0b00000100
#define ADC_Prescaler_32_msk				0b00000101
#define ADC_Prescaler_64_msk				0b00000110
#define ADC_Prescaler_128_msk				0b00000111
/*=============================================================
 * ADC Auto Trigger Enable
 * ============================================================
**/
#define ADC_Mode_clr_msk					0b11011111
#define ADC_SingleConversion_msk			0b00000000
#define ADC_AutoTrigging_msk				0b00100000
/*=============================================================
 * ADC Auto Trigger Source
 * ============================================================
**/
#define ADC_Trigger_clr_msk							0b00011111
#define ADC_Trigger_Free_Running_mode_msk			0b00000000
#define ADC_Trigger_Analog_Comparator_msk			0b00100000
#define ADC_Trigger_Exti0_msk						0b01000000
#define ADC_Trigger_Timer0Comp_msk					0b01100000
#define ADC_Trigger_Timer0_OVF_msk					0b10000000
#define ADC_Trigger_Timer1CompB_msk					0b10100000
#define ADC_Trigger_Timer1_OVF_msk					0b11000000
#define ADC_Trigger_Timer1_CAPT_msk					0b11100000
/*=============================================================
 * functions prototypes 
 *=============================================================
**/
void ADC_init(ADC_ch Channel);
uint16 ADC_ReadChannel(ADC_ch Channel);
void ADC_enInterrupt(void);
void ADC_diInterrupt(void);
uint32 ADC_getVoltage_m(ADC_ch Channel);


#endif /* ADC_H_ */