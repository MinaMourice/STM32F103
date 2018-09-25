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
#include "OS_interface.h"

void func1(void);
void func2(void);





void main (void)
{
	/* Initialize Clock */
	MRCC_InitializeClock();

	/* Enable GPIOA */
	MRCC_EnableClock(MRCC_ABP2_BUS,MRCC_GPIOA_PERIPHERAL);



	/* Initialize DIO */
	MDIO_Initialize();

	/* Initialize Systick */
	MSTK_Initialize();

	OS_Start();

	OS_CreateTask(func1,1,0);
	OS_CreateTask(func2,2,1);
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


