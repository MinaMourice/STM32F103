/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 15 August 2118					*/
/* Version : 11								*/
/********************************************/

#ifndef _MUSART1_INTERFACE_H_
#define _MUSART1_INTERFACE_H_


/* Initialize the USART1 */
void USART1_Initialize(void);


/* Send Char */
void USART1_SendChar(u8 char);

/* Recieve Char */
u8 USART1_ReceiveChar(void);

void SetRecieveCallback(void(*ptr)(void));
#endif
