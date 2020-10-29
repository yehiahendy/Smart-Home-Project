	/*
 * STD_types.h
 *
 *  Created on: Sep 20, 2019
 *      Author: breks
 */

#ifndef UTIL_STD_TYPES_H_
#define UTIL_STD_TYPES_H_

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;

typedef signed char sint8;
typedef signed short int sint16;
typedef signed long int sint32;

typedef float float32;

typedef enum
{
	STD_low=0,
	STD_high=1
}STD_levelType;

typedef enum
{
	false=0,
	true=1
}boolean;

typedef enum
{
	STD_IN=0,
	STD_OUT=1
}STD_Direction;

#define DISABLE			0
#define ENABLE			1

#endif /* UTIL_STD_TYPES_H_ */
