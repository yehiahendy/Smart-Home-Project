/*
 * SPI_HW.h
 *
 * Created: 10/20/2020 5:09:32 AM
 *  Author: yehia
 */ 


#ifndef SPI_HW_H_
#define SPI_HW_H_


/*************************** SPCR bits***********************************/
#define SPR0	0 
#define SPR1	1 
#define CPHA	2 
#define CPOL	3
#define MSTR	4
#define DORD	5
#define SPE		6
#define SPIE	7
/*************************** SPSR bits***********************************/
#define SPI2X   0
#define WCOL    6
#define SPIF    7

/************************************************************************/

#define  SPDR             *((volatile unsigned char *)0x2F)
#define  SPSR             *((volatile unsigned char *)0x2E)
#define  SPCR             *((volatile unsigned char *)0x2D)




#endif /* SPI_HW_H_ */