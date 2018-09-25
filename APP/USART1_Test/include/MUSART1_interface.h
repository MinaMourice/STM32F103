/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 15 August 2118					*/
/* Version : 11								*/
/********************************************/

#ifndef _MUSART1_INTERFACE_H_
#define _MUSART1_INTERFACE_H_


/* Initialize the USART1 */
void MUSART1_Initialize(void);


/* Send Char */
void MUSART1_SendChar(u8 ch);

/* Recieve Char */
u8 MUSART1_ReceiveChar(void);

/* Callback function */
void SetRecieveCallback(void(*ptr)(void));

#endif
