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
void MDMA_Start(u32* Source, u32* Destination);

void MDMA_SetCallBack(void(*ptr)(void));
#endif
