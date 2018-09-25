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
	/* Set HSION bit */
	MRCC->CR = 0x00000001;

	/* Set PLLON bits */
	MRCC->CR |= (1<<24);

	/* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE bits */
	MRCC->CFGR |=(1<<19)|(1<<20)|(1<<21)|(1<<1);
	
	/* Enable USART1 */
	MRCC -> APB2ENR |=(1<<14);
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
