/*
 * EXTI.c
 *
 * Created: 9/10/2020 6:45:19 AM
 *  Author: yehia
 */ 
#include "EXTI.h"
void EXTI_init(void)
{
	#if (EXTI_INT0_EN == ENABLE)
	EXTI_setEdge(EXTI_INT0,EXTI_Rising_Edge);
	EXTI_enInterrupt(EXTI_INT0);

	#endif
	
	#if (EXTI_INT1_EN == ENABLE)
	EXTI_setEdge(EXTI_INT1,EXTI_Rising_Edge);
	EXTI_enInterrupt(EXTI_INT1);

	#endif
	
	#if (EXTI_INT2_EN == ENABLE)
	
	EXTI_setEdge(EXTI_INT2,EXTI_Rising_Edge);
	EXTI_enInterrupt(EXTI_INT2);

	#endif
	
}
void EXTI_setEdge(EXTI_IntType IntNum,EXTI_SenseControl SenseControl)
{
	switch(IntNum)
	{
		case EXTI_INT0 :
		if (SenseControl == EXTI_Low_Level)
		{
			CLEAR_Bit(MCUCR,ISC00);
			CLEAR_Bit(MCUCR,ISC01);
		}
		else if (SenseControl == EXTI_OnChange_Edge )
		{
			SET_Bit(MCUCR,ISC00);
			CLEAR_Bit(MCUCR,ISC01);
		}
			
		else if (SenseControl == EXTI_Falling_Edge ) 
		{
			CLEAR_Bit(MCUCR,ISC00);
			SET_Bit(MCUCR,ISC01);
		}
		else
		{
			SET_Bit(MCUCR,ISC00);
			SET_Bit(MCUCR,ISC01);
		}
		break;
		
		case EXTI_INT1 :
		if (SenseControl == EXTI_Low_Level)
		{
			CLEAR_Bit(MCUCR,ISC10);
			CLEAR_Bit(MCUCR,ISC11);
		}
		else if (SenseControl == EXTI_OnChange_Edge )
		{
			SET_Bit(MCUCR,ISC10);
			CLEAR_Bit(MCUCR,ISC11);
		}
		
		else if (SenseControl == EXTI_Falling_Edge )
		{
			CLEAR_Bit(MCUCR,ISC10);
			SET_Bit(MCUCR,ISC11);
		}
		else
		{
			SET_Bit(MCUCR,ISC10);
			SET_Bit(MCUCR,ISC11);
		}
		break;
		
		case EXTI_INT2 :
		if (SenseControl == EXTI_Falling_Edge )
		{
			CLEAR_Bit(MCUCSR,ISC2);
		} 
		else
		{
			SET_Bit(MCUCSR,ISC2);
		}
		break;
	}
	
}
void EXTI_enInterrupt(EXTI_IntType IntNum)
{
	switch(IntNum)
	{
		case EXTI_INT0 :
		SET_Bit(GICR,EXTI_INT0);
		break;
		case EXTI_INT1 :
		SET_Bit(GICR,EXTI_INT1);
		break;
		case EXTI_INT2 :
		SET_Bit(GICR,EXTI_INT2);
	}
}
void EXTI_diInterrupt(EXTI_IntType IntNum)
{
	switch(IntNum)
	{
		case EXTI_INT0 :
		CLEAR_Bit(GICR,EXTI_INT0);
		break;
		case EXTI_INT1 :
		CLEAR_Bit(GICR,EXTI_INT1);
		break;
		case EXTI_INT2 :
		CLEAR_Bit(GICR,EXTI_INT2);
	}
}