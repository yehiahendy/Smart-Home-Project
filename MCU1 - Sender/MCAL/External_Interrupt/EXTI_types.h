/*
 * EXTI_types.h
 *
 * Created: 9/10/2020 6:45:52 AM
 *  Author: yehia
 */ 


#ifndef EXTI_TYPES_H_
#define EXTI_TYPES_H_
typedef enum
{
	EXTI_Low_Level,
	EXTI_OnChange_Edge,
	EXTI_Falling_Edge,
	EXTI_Rising_Edge
}EXTI_SenseControl;

typedef enum
{
	EXTI_INT0=6,
	EXTI_INT1=7,
	EXTI_INT2=5
}EXTI_IntType;




#endif /* EXTI_TYPES_H_ */