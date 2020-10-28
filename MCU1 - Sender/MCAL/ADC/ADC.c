/*
 * ADC.c
 *
 * Created: 9/23/2020 7:43:43 PM
 *  Author: yehia
 */ 
#include "ADC.h"
void ADC_init(ADC_ch Channel)
{

	//choose the Voltage reference 
	ADMUX &= ADC_VoltageReference_clr_msk;
	ADMUX |= Voltage_Reference_Selector;
	//Right or Left adjust 
	ADMUX &= ADC_Adjust_clr_msk;
	ADMUX |= ADC_Adjust_Selector;
	//prescaler
	ADCSRA &= ADC_Prescaler_clr_msk;
	ADCSRA &= ADC_Prescaler_Selector;
	//conversion mode
	#if (ADC_Mode_Selector == ADC_AutoTrigging_msk)
	SET_Bit(ADCSRA,ADATE);
	SFIOR &= ADC_Trigger_clr_msk;
	SFIOR |= ADC_Trigger_Selector;
	SET_Bit(ADCSRA,ADSC);
	#endif
		//Enable ADC
		SET_Bit(ADCSRA,ADEN);
		//choose the channel
		ADMUX &= 0b11100000;
		ADMUX |= Channel;
}
uint16 ADC_ReadChannel(ADC_ch Channel)
{
	#if (ADC_Mode_Selector == ADC_SingleConversion_msk)
	ADMUX &= 0b11100000;
	ADMUX |= Channel;
	SET_Bit(ADCSRA,ADSC);
#endif
	while(GET_Bit(ADCSRA,ADIF) == 0)
	{
		;
	}
	return ADC;
}
void ADC_enInterrupt(void)
{
	SET_Bit(ADCSRA,ADIE);
}

void ADC_diInterrupt(void)
{
	CLEAR_Bit(ADCSRA,ADIE);
}

uint32 ADC_getVoltage_m(ADC_ch Channel)
{
	uint32 StepsNum;
	StepsNum=ADC_ReadChannel(Channel);

	return StepsNum*(ADC_VOLTAGE_REF_mv/ADC_TOTAL_STEPS);

}