/*
 * main.c
 *
 *  Created on	: Aug 3, 2018
 *      Author	: Mina Mourice
 *      Version	: 01
 */


#include "LSTD_Types.h"
#include "MDIO_interface.h"
#include "MRCC_interface.h"


void main(void)
{
	/* Initialize Clock System */
	MRCC_InitializeClock();

	/* Enable GPIOA Clock */
	MRCC_EnablClock(MRCC_APB2_BUS,MRCC_GPIOA_PERIPHERAL);

	/* Initialize GPIO */
	MDIO_Initialize();

	/* Set A0 Low */
	MDIO_SetPinValue(MDIO_PORTA,0,MDIO_LOW);

	/* Set A1 Low */
	MDIO_SetPinValue(MDIO_PORTA,1,MDIO_LOW);
}

