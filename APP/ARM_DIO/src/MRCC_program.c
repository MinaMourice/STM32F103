/************************************************/
/* Name		: Mina Mourice						*/
/* Date		: 3 August 2018						*/
/* Version 	: 01								*/

#include "LSTD_TYPES.h"
#include "MRCC_private.h"
#include "MRCC_interface.h"

void MRCC_InitializeClock(void)
{
	/*HSE On*/
	MRCC_CR	|=(1<<4);
	
	/*Select HSE as system clock*/
	MRCC_CFGR |=0x01;
	/*Enable clock for I/O PC   PORTC & PORTA*/
	MRCC_APB2ENR |= (1<<4)|(1<<2);
}
