/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 15 August 2018					*/
/* Version : 01								*/
/********************************************/

#include "LSTD_TYPES.h"
#include "MUSART1_private.h"
#include "MUSART1_interface.h"

/* Initialize the USART1 */
void USART1_Initialize(void)
{
	/* Set Baudrate */
	MUSART1->BRR=64000000L/115200L;
	
	/* TX RX Enable*/
	MUSART1->CR1|=(1<<2)|(1<<3);
	
	/* Enable USART */
	MUSART1->CR1|=(1<<13);
	
}


/* Send Char */
void USART1_SendChar(u8 ch)
{
	/* Busy Waiting if Data is not transferred to the shift register */
	while (!(USART1->SR & USART1_SR_TXNE );
	 
	/* Write to Data Register to transmit */ 
	USART1->DR = (ch & 0xFF);
	 
}

/* Recieve Char */
u8 USART1_ReceiveChar(void)
{
	
	/* Busy Waiting until Data is received */
	while (!(USART1->SR & USART1_SR_RXNE));
	  
	return ((u8)(USART1->DR & 0xFF));
}


void(*Callback)(void)

void SetRecieveCallback(void(*ptr)(void))
{
	Callback=ptr;
}

void USART1_IRQHandler(void)
{
	Callback();
}