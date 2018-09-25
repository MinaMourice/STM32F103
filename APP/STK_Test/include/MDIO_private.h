/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 3 August 2018					*/
/* Version : 01								*/
/********************************************/

#ifndef _MDIO_PRIVATE_H_
#define _MDIO_PRIVATE_H_


typedef struct
{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSR;
	u32 BRR;
	u32 LCK;
}GPIO_type;




#define GPIOA ((volatile GPIO_type*)0x40010800)
#define GPIOB ((volatile GPIO_type*)0x40010C00)
#define GPIOC ((volatile GPIO_type*)0x40011000)
#define GPIOD ((volatile GPIO_type*)0x40011400)
#define GPIOE ((volatile GPIO_type*)0x40011800)
#define GPIOF ((volatile GPIO_type*)0x40011C00)
#define GPIOG ((volatile GPIO_type*)0x40012000)

#endif
