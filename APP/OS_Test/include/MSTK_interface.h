/****************************************/
/* Author	: Mina Mourice				*/
/* Date		: 4 August 2018				*/
/* Version	: 01						*/
/****************************************/ 
#ifndef _MSTK_INTERFACE_H_
#define _MSTK_INTERFACE_H_

/* Initialize MSTK */
void MSTK_Initialize (void);

void MSTK_Start (u32 Count);

void MSTK_Stop(void);

void MSTK_SetCallback(void (*ptr)(void));

#endif
