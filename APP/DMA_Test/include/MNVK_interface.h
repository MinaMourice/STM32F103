/****************************************/
/* Author	: Mina Mourice				*/
/* Date		: 11 August 2018				*/
/* Version	: V01						*/
/****************************************/ 
#ifndef _MNVK_INTERFACE_H_
#define _MNVK_INTERFACE_H_

#define MNVK_EXTI0 6 
#define MNVK_EXTI1 7
#define MNVK_DMA	11

/* Enable MNVK */
void MNVK_Enable (u8 ID);

/* Disable MNVK */
void MNVK_Disable (u8 ID);

/* Clear Pending Flag */
void MNVK_ClearPending (u8 ID);

/* Set Pending Flag */
void MNVK_SetPending (u8 ID);

#endif
