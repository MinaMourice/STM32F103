/****************************************/
/* Author	: Mina Mourice				*/
/* Date		: 11 August 2018				*/
/* Version	: V01						*/
/****************************************/
#ifndef _MEXTI_PRIVATE_H_
#define _MEXTI_PRIVATE_H_

typedef struct
{
	u32 IMR ;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}MEXTI_type;	

/* EXTI base Address */
#define MEXTI ((volatile MEXTI_type*)0x40010400)

#endif