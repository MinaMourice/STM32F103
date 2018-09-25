/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 17 August 2018					*/
/* Version : 01								*/
/********************************************/

#ifndef _MDMA_PRIVATE_H_
#define _MDMA_PRIVATE_H_

typedef struct
{
	u32 ISR		;
	u32 IFCR	;
	u32 CCR1	;
	u32 CNDTR1	;
	u32 CPAR1	;
	u32 CMAR1	;
	u32 Reserved1;
	
	u32 CCR2	;
	u32 CNDTR2	;
	u32 CPAR2	;
	u32 CMAR2	;
	u32 Reserved2;
	
	u32 CCR3	;
	u32 CNDTR3	;
	u32 CPAR3	;
	u32 CMAR3	;
	u32 Reserved3;
	
	u32 CCR4	;
	u32 CNDTR4	;
	u32 CPAR4	;
	u32 CMAR4	;
	u32 Reserved4;
}MDMA_type;


#define MDMA ((volatile MUSART1_type*)0x40020000)