/*
 * main.c
 *
 *  Created on: Aug 8, 2018
 *      Author: Mina Mourice
 */

#include "LSTD_Types.h"
#include "MDIO_interface.h"
#include "MRCC_interface.h"
#include "MSTK_interface.h"
#include "OS_interface.h"

/* To make small OS :
 * 1- Task Struct (Pointer to function , Periodicity )
 * 2- Define Tasks in an array of Task type
 * 3- Scheduler Function
 */

/* TickCount Volatile as it is used in an interrupt*/
volatile u32 TickCount =0;

/* 1- Task Struct*/
typedef struct
{
	void (*Taskhandler)(void);
	u16 Periodicity ;
}Task;

/* 2- Task array */
Task SysTasks[7]={
		/*Task 1*/{ Task1_7segmentCountUp , 10 },
		/*Task 2{ Task2_7segmentCountDown , 8 }
		Task 3{ Task3_ShiftLed , 8 }
		Task 4{ Task4_BuzzerBeep , 20},
		Task 5{ Task5_StepperMotor , 1},
		Task 6{ Task6_NameLCD , 14},
		Task 7{ Task7_UART_A , 3},*/
};

/* Scheduler Funtion */
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

	/*Enable Clock for Port A & B */
	MRCC_EnableClock(MRCC_ABP2_BUS,MRCC_GPIOA_PERIPHERAL);
	MRCC_EnableClock(MRCC_ABP2_BUS,MRCC_GPIOB_PERIPHERAL);
	MRCC_EnableClock(MRCC_ABP2_BUS,MRCC_GPIOC_PERIPHERAL);

	/* Initialize GPIO A */
	MDIO_Initialize();

	/* MSTK Initialize */
	MSTK_Initialize();

	/* Set Systick Callback*/
	MSTK_SetCallback(Scheduler);

	/* MSTK_Start : 50 ms */
	MSTK_Start(50000);
}

