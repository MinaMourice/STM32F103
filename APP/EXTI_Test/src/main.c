/*
 * main.c
 *
 *  Created on: Aug 11, 2018
 *      Author: Mina Mourice
 */
#include "LSTD_Types.h"
#include "MRCC_interface.h"
#include "MDIO_interface.h"
#include "MNVK_interface.h"
#include "MEXTI_interface.h"

void func(void)
{
	static u8 Flag=0;
	if(Flag == 0)
	{
		MDIO_SetPinValue(MDIO_PORTA,1,MDIO_LOW);
		Flag=1;
	}
	else
	{
		MDIO_SetPinValue(MDIO_PORTA,1,MDIO_HIGH);
		Flag=0;
	}
}
void main(void)
{
	/* Initialize RCC */
	MRCC_InitializeClock();

	/* Enable GPIOA */
	MRCC_EnableClock(MRCC_ABP2_BUS,MRCC_GPIOA_PERIPHERAL);

	/* Enable Alternative Function */
	MRCC_EnableClock(MRCC_ABP2_BUS,MRCC_AFIO_PERIPHERAL);

	/* Initialize GPIO */
	MDIO_Initialize();

	/* Set A0 to Pull UP */
	MDIO_SetPinValue(MDIO_PORTA,0,MDIO_HIGH);

	#define AIRCR *((volatile u32*) 0xE000ED0C)
	AIRCR = 0x05FA0500;
	/* Set MEXTI Callback*/
	MEXTI_SetCallBack(0,func);

	/* Set Mode to falling Edge */
	MEXTI_SetMode(0,MEXTI_RISING);

	/* Enable Interrupt */
	MEXTI_Enable(0);

	/* Initialize USART */
	//USART1_Initialize();

	/* Enable MEXTI on NVIC */
	MNVK_Enable(MNVK_EXTI0);


	/* Disable Global Interrupt
	asm("MOV R0,#0x01");
	asm("MSR PRIMASK,R0");


	  Critical Section


	asm("MOV R0,#0");
	asm("MSR PRIMASK,R0");*/
}




