/*
 * main.c
 *
 *  Created on: Aug 15, 2018
 *      Author: Mina Mourice
 */

#include "LSTD_Types.h"
#include "MRCC_interface.h"
#include "MDIO_interface.h"
#include "MNVK_interface.h"
#include "MEXTI_interface.h"
#include "MUSART1_interface.h"
void main(void)
{

	/* Initialize RCC */
	MRCC_InitializeClock();

	/* Enable GPIOA */
	MRCC_EnableClock(MRCC_ABP2_BUS,MRCC_GPIOA_PERIPHERAL);

	/* Enable Alternative Function */
	MRCC_EnableClock(MRCC_ABP2_BUS,MRCC_AFIO_PERIPHERAL);



	/* Initialize GPIO */
	/* PA9 = alternate function push/pull output */
	/* PA10 = floating input */
	MDIO_Initialize();

	/* Initialize USART1 */
	MUSART1_Initialize();
	u16 i=0;
	/* Send Char */
while(1)
	MUSART1_SendChar('1');

}
