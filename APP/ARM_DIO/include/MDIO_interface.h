/**************************************************/
/* 	Author : Mina Mourice                        */
/*  Date : 3/8/2018
/* Version : 1 									*/

#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

void MDIO_Initialization(void);
void MDIO_LedOn(void);
void MDIO_LedOff(void);
void MDIO_SetPinVal(u8 port , u8 pin , u8 val);
u8 MDIO_GetPinVal(u8 port , u8 pin);
void MDIO_SevenSegment_PortA(void);
void All_On(void);
void All_Off(void);


#endif
