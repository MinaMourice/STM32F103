/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 15 August 2018					*/
/* Version : 01								*/
/********************************************/

#include "LSTD_TYPES.h"
#include "MUSART1_private.h"
#include "MUSART1_interface.h"



/* Initialize the USART1 */
void MUSART1_Initialize(void)
{


	/* Set Baudrate */
	MUSART1->BRR=64000000L/9600L;
	
	/* TX RX Enable*/
	MUSART1->CR1|=(1<<2)|(1<<3);
	/* Enable USART */
	MUSART1->CR1|=(1<<13);

	
}


/* Send Char */
void MUSART1_SendChar(u8 ch)
{
	/* Busy Waiting if Data is not transferred to the shift register */
	while ( !(MUSART1->SR & USART1_SR_TXNE) );
	 
	/* Write to Data Register to transmit */ 
	MUSART1->DR = (ch & 0xFF);
	 
}

/* Recieve Char */
u8 MUSART1_ReceiveChar(void)
{
	
	/* Busy Waiting until Data is received */
	while (!(MUSART1->SR & USART1_SR_RXNE));
	  
	return ((u8)(MUSART1->DR & 0xFF));
}


void(*Callback)(void);

void SetRecieveCallback (void(*ptr)(void))
{
	Callback=ptr;
}

void USART1_IRQHandler(void)
{
	Callback();
}
