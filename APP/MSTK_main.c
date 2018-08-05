/*
 * main.c
 *
 *  Created on: Aug 4, 2018
 *      Author: Mina Mourice
 */

#include "LSTD_Types.h"
#include "MRCC_interface.h"
#include "MDIO_interface.h"
#include "MSTK_interface.h"


void func1(void);
void func2(void);

typedef struct
{
	void (*Taskhandler)(void);
	u16 Periodicity ;
}Task;

Task SysTasks[2]={
		/* Task 1 */ {	func1	,	2	},
		/* Task 2 */ {	func2	,	1	}
};


volatile u32 TickCount = 0 ;
void Scheduler (void)
{
	u8 i ;
	TickCount++;
	for (i=0 ; i<2;i++)
	{
		if(	(TickCount % SysTasks[i].Periodicity) ==0)
		{
			SysTasks[i].Taskhandler();
		}
	}
}

void main (void)
{
	/* Initialize Clock */
	MRCC_InitializeClock();

	/* Enable GPIOA */
	MRCC_EnableClock(MRCC_ABP2_BUS,MRCC_GPIOA_PERIPHERAL);

	/* Set Systic Handler*/
	MSTK_SetCallback(Scheduler);

	/* Initialize DIO */
	MDIO_Initialize();

	/* Initialize Systick */
	MSTK_Initialize();

	/* Start Systick */
	MSTK_Start(1000000);

	while(1)
	{

	}
}

void func1(void)
{
	static u8 Flag = 0 ;
	if(0==Flag)
	{
		MDIO_SetPinValue(MDIO_PORTA,0,MDIO_HIGH);
		Flag=1;
	}
	else
	{
		MDIO_SetPinValue(MDIO_PORTA,0,MDIO_LOW);
		Flag=0;
	}
}



void func2(void)
{
	static u8 Flag = 0 ;
	if(0==Flag)
	{
		MDIO_SetPinValue(MDIO_PORTA,1,MDIO_HIGH);
		Flag=1;
	}
	else
	{
		MDIO_SetPinValue(MDIO_PORTA,1,MDIO_LOW);
		Flag=0;
	}
}


