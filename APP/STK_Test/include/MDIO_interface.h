/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 3 August 2018					*/
/* Version : 01								*/
/********************************************/

#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

#define MDIO_PORTA		0
#define MDIO_PORTB		1
#define MDIO_PORTC		2
#define MDIO_PORTD		3
#define MDIO_PORTE		4
#define MDIO_PORTF		5
#define MDIO_PORTG		6


#define MDIO_LOW		0
#define MDIO_HIGH		1

/* Initialize MDIO*/
void MDIO_Initialize(void);

/* Set any pin of any port */
void MDIO_SetPinValue(u8 Port, u8 Pin, u8 Value);

/* Get value of any pin of any port */
u8 MDIO_GetPinValue(u8 Port , u8 Pin);



#endif
