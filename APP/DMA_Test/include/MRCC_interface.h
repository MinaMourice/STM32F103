/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 3 August 2018					*/
/* Version : 01								*/
/********************************************/

#ifndef _MRCC_INTERFACE_H_
#define _MRCC_INTERFACE_H_

#define MRCC_AHB_BUS	21
#define MRCC_ABP1_BUS	6
#define MRCC_ABP2_BUS	96

#define MRCC_DMA1_PERIPHERAL	1
#define MRCC_GPIOA_PERIPHERAL	4
#define MRCC_GPIOB_PERIPHERAL	8
#define MRCC_GPIOC_PERIPHERAL	16
#define MRCC_GPIOD_PERIPHERAL	32
#define MRCC_GPIOE_PERIPHERAL	64
#define MRCC_GPIOF_PERIPHERAL	128
#define MRCC_GPIOG_PERIPHERAL	256

/* Initialize the RCC */
void MRCC_InitializeClock(void);


/* Enable Clock */
void MRCC_EnableClock(u8 Bus, u8 Peripheral);

#endif
