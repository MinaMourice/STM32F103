/****************************************/
	/* Author	: Mina Mourice				*/
/* Date		: 4 August 2018				*/
/* Version	: 01						*/
/****************************************/

#include "LSTD_Types.h"
#include "MSTK_private.h"
#include "MSTK_Interface.h"

/* Initialize MSTK */
void MSTK_Initialize (void)
{
	/* Set Clock to be AHB/8 and Enable Interrupt */
	MSTK->CTRL=0x00000002;
}

void MSTK_Start (u32 Count)
{
	/* Load Count into Load Register */
	MSTK -> LOAD = Count ;
	
	/* Enable Systick */
	MSTK -> CTRL |=1;
}

void MSTK_Stop(void)
{
	/* Disable Systick */
	MSTK -> CTRL &= 0xFFFFFFFE;
}

/* 1- Pointer to function */
void (*MSTK_Callback) (void);

/* 2- Systick Interrupt Handler */
void SysTick_Handler(void)
{
	MSTK_Callback();
}

/* 3- Interface SetCallback implementation */
void MSTK_SetCallback(void (*ptr)(void))
{
	MSTK_Callback=ptr;
}
