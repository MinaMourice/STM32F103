/************************************************/
/* Name		: Mina Mourice						*/
/* Date		: 3 August 2018						*/
/* Version 	: 01								*/

#include "LSTD_TYPES.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"


void MDIO_Initialization(void)
{
	/*C13 output*/
	//MDIOC_CRH = 0x00000000;
	MDIOC_CRH |=(1<<25)|(1<<21);
	MDIOC_BRR|=(1<<13)|(1<<14);
	//MDIOC_ODR&=~(1<<14);


	/*PortA Output - Push Pull 2 MHZ
	  A0 , A1 , A2 , A3 , A4 , A5 , A6 */
	MDIOA_CRL |=(1<<1)|(1<<5)|(1<<9)
			|(1<<13)|(1<<17)|(1<<21)
			|(1<<25);
}

void MDIO_SetPinVal(u8 port , u8 pin , u8 val)
{
	if(val==0)
		ODR_DIOx(port) &=~(1<<pin);
	else
		ODR_DIOx(port) |=(1<<pin);
}

u8 MDIO_GetPinVal(u8 port , u8 pin)
{
	return (ODR_DIOx(port) & (1<<pin));
}

