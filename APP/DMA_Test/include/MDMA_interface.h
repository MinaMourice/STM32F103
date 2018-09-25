/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 17 August 2118					*/
/* Version : 01								*/
/********************************************/

#ifndef _MDMA_INTERFACE_H_
#define _MDMA_INTERFACE_H_


/* Initialize the USART1 */
void MDMA_Initialize(void);


/* Send Char */
void MDMA_Start(u32* Sourcead, u32* Destinationad);

void MDMA_SetCallback(void (*ptr)(void));
#endif
