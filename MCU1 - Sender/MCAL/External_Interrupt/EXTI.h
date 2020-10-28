/*
 * EXTI.h
 *
 * Created: 9/10/2020 6:45:34 AM
 *  Author: yehia
 */ 


#ifndef EXTI_H_
#define EXTI_H_
///////////////////////////////////////////////////////////
#include "EXTI_HW.h"
#include "EXTI_types.h"
#include "../../Util/BIT_MATH.h"
///////////////////////////////////////////////////////////
#define EXTI_INT0_EN     ENABLE
#define EXTI_INT1_EN     ENABLE
#define EXTI_INT2_EN     DISABLE
///////////////////////////////////////////////////////////
#define  ISC00       0
#define  ISC01       1
#define  ISC10       2
#define  ISC11       3
#define  ISC2        6
///////////////////////////////////////////////////////////
void EXTI_init(void);
void EXTI_setEdge(EXTI_IntType IntNum,EXTI_SenseControl SenseControl);
void EXTI_enInterrupt(EXTI_IntType IntNum);
void EXTI_diInterrupt(EXTI_IntType IntNum);
///////////////////////////////////////////////////////////

#endif /* EXTI_H_ */