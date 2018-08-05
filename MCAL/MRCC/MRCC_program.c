/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 3 August 2018					*/
/* Version : 01								*/
/********************************************/


#include "LSTD_TYPES.h"
#include "MRCC_private.h"
#include "MRCC_interface.h"

void MRCC_InitializeClock(void)
{
	/*HSE On*/
	MRCC->CR	=0x00010000;
	
	/*Select HSE as system clock*/
	MRCC->CFGR	=0x00000001;
}


void MRCC_EnableClock(u8 Bus, u8 Peripheral)
{
	switch(Bus)
	{
		case MRCC_AHB_BUS	: MRCC -> AHBENR  |= Peripheral;break;
		case MRCC_ABP1_BUS	: MRCC -> APB1ENR |= Peripheral;break;
		case MRCC_ABP2_BUS	: MRCC -> APB2ENR |= Peripheral;break;
	}
}
