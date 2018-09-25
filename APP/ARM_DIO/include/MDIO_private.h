/************************************************/
/* Name		: Mina Mourice						*/
/* Date		: 3 August 2018						*/
/* Version 	: 01								*/

#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_
/*PORTC Registers*/
#define MDIOC_CRL		*((u32*)0x40011000)
#define MDIOC_CRH		*((u32*)0x40011004)
#define MDIOC_IDR		*((u32*)0x40011008)
#define MDIOC_ODR 		*((u32*)0x4001100C)
#define MDIOC_BSR		*((u32*)0x40011010)
#define MDIOC_BRR		*((u32*)0x40011014)
#define MDIOC_LCK		*((u32*)0x40011018)

/*PORTA Registers*/
#define MDIOA_CRL		*((u32*)0x40010800)
#define MDIOA_CRH		*((u32*)0x40010804)
#define MDIOA_IDR		*((u32*)0x40010808)
#define MDIOA_ODR 		*((u32*)0x4001080C)
#define MDIOA_BSR		*((u32*)0x40010810)
#define MDIOA_BRR		*((u32*)0x40010814)
#define MDIOA_LCK		*((u32*)0x40010818)

/*Access the ODR of any Port */
#define ODR_DIOx(_N)     *((u32*)(0x40010800 + (1024)*(_N) + 0x0000000C))

#endif
