/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 15 August 2018					*/
/* Version : 01								*/
/********************************************/

#ifndef _MUSART1_PRIVATE_H_
#define _MUSART1_PRIVATE_H_

#define USART1_SR_TXNE (1<<7) 
#define USART1_SR_RXNE (1<<5) 

typedef struct
{
	u32 SR	;
	u32 DR	;
	u32 BRR	;
	u32 CR1 ;
	u32 CR2 ;
	u32 CR3 ;
	u32 GTPR ;
}MUSART1_type;


#define MUSART1 ((volatile MUSART1_type*)0x40013800)

#endif
