/*
 * main.c
 *
 *  Created on: Aug 17, 2018
 *      Author: Mina Mourice
 */
#include "LSTD_Types.h"
#include "MDMA_interface.h"
#include "MNVK_interface.h"
#include "MRCC_interface.h"

u32 i ;
u32 Source[1000];
u32 Destination[1000];
void func1(void)
{
	static volatile u8 x=0;
	x++;
}
void main (void)
{
	/* Initialize Clock */
	MRCC_InitializeClock();

	/* Enable Clock for DMA */
	MRCC_EnableClock(MRCC_AHB_BUS,MRCC_DMA1_PERIPHERAL);

	/* Initialize DMA1 */
	MDMA_Initialize();

	/* Enable DMA Interrupt */
	MNVK_Enable(MNVK_DMA);

	/* Set MDMA Callback */
	MDMA_SetCallback(func1);

	/* MDMA Start */
	MDMA_Start(Source,Destination);
	for(i =0 ;i<1000;i++)
	{
		Destination[i]=Source[i];
	}

	MDMA_SetCallback(func1);
}

/*
void DMA1_Channel1_IRQHandler(void)
{
	static volatile u8 x=0;
	x++;
}
*/

