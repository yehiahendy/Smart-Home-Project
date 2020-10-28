/*
 * BIT_MATH.h
 *
 * Created: 8/29/2020 4:13:10 PM
 *  Author: yehia
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_Bit(Var,BitNo)    Var |= (1<<BitNo)
#define CLEAR_Bit(Var,BitNo)  Var &= ~(1<<BitNo)
#define TOGGLE_BIT(Var,BitNo) Var ^= (1<<BitNo)
#define GET_Bit(var,BitNo)    ((var) >> (BitNo)) & 0x01

#endif /* BIT_MATH_H_ */