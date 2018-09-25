/*
 * main.c
 *
 *  Created on: Aug 11, 2018
 *      Author: Mina Mourice
 */
#include "LSTD_Types.h"
#include "MDIO_interface.h"
#include "MNVK_interface.h"
#include "MRCC_interface.h"

void main (void)
{
	MRCC_InitializeClock();
	MRCC_EnableClock(MRCC_ABP2_BUS,MRCC_GPIOA_PERIPHERAL);

	MDIO_Initialize();

	MNVK_Enable(MNVK_EXTI0);
	MNVK_SetPending(MNVK_EXTI0);
}

void EXTI0_IRQHandler(void){

	/* Set A0 to high */
	MDIO_SetPinValue(MDIO_PORTA,0,MDIO_HIGH);

}



