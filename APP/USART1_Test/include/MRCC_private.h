/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 3 August 2018					*/
/* Version : 01								*/
/********************************************/

typedef struct
{
u32 CR		;
u32 CFGR	;
u32 CIR		;
u32 APB2RSTR;
u32 APB1RSTR;
u32 AHBENR 	;
u32 APB2ENR ;
u32 APB1ENR ;
u32 BDCR   	;
u32 CSR  	;
}MRCC_type;


#define MRCC ((volatile MRCC_type*)0x40021000)