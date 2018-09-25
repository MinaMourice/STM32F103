/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 17 August 2018					*/
/* Version : 01								*/
/********************************************/

#include "LSTD_TYPES.h"
#include "MDMA_interface.h"
#include "MDMA_private.h"
/* Initialize MDMA */
void MDMA_Initialize(void)
{
	/* 
	M2M On
	Increment Source
	Increment Distnation
	Enable Complete Interrupt
	Circular Mode off
	Transfer size 32 Bit
	*/
	MDMA->CCR1=0x00007AC2;
	
	/* Set block Size 1000 */
	MDMA->CNDTR1=1000;
}


/* Start MDMA */
void MDMA_Start(u32* Sourcead, u32* Destinationad)
{
	MDMA -> CPAR1 = Sourcead;
	MDMA -> CMAR1 = Destinationad;
	MDMA -> CCR1 |=1;
}
void (*MDMA_Callback) (void);

void DMA1_Channel1_IRQHandler(void)
{
	MDMA_Callback();
}

void MDMA_SetCallback(void (*ptr)(void))
{
	MDMA_Callback=ptr;
}
