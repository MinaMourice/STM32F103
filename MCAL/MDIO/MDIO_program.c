/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 3 August 2018					*/
/* Version : 01								*/
/********************************************/
#include "LSTD_Types.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"

void MDIO_Initialize (void)
{
	GPIOA->CRL=0x00000022;
	GPIOB->CRL=0x22222222;
	GPIOC->CRL=0x22222222;
	GPIOD->CRL=0x22222222;
	GPIOE->CRL=0x22222222;
	GPIOF->CRL=0x22222222;
	GPIOG->CRL=0x22222222;
}

void MDIO_SetPinValue(u8 Port, u8 Pin, u8 Value)
{
	if (Pin<=15)
	{
		switch(Port)	
		{
			case MDIO_PORTA: 
				if(MDIO_HIGH==Value)
					GPIOA->ODR |= (1<<Pin);
				else 
					GPIOA->ODR &= ~(1<<Pin);
				break;
			case MDIO_PORTB:
				if(MDIO_HIGH==Value)
					GPIOB-> ODR |= (1<<Pin);
				else 
					GPIOB-> ODR &= ~(1<<Pin);
				break;
			case MDIO_PORTC:
				if(MDIO_HIGH==Value)
					GPIOC-> ODR |= (1<<Pin);
				else 
					GPIOC-> ODR &= ~(1<<Pin);
				break;		
			case MDIO_PORTD:
				if(MDIO_HIGH==Value)
					GPIOD-> ODR |= (1<<Pin);
				else 
					GPIOD-> ODR &= ~(1<<Pin);
				break;		
			case MDIO_PORTE:
				if(MDIO_HIGH==Value)
					GPIOE-> ODR |= (1<<Pin);
				else 
					GPIOE-> ODR &= ~(1<<Pin);
				break;		
			case MDIO_PORTF:
				if(MDIO_HIGH==Value)
					GPIOF-> ODR |= (1<<Pin);
				else 
					GPIOF-> ODR &= ~(1<<Pin);
				break;		
			case MDIO_PORTG:
				if(MDIO_HIGH==Value)
					GPIOG-> ODR |= (1<<Pin);
				else 
					GPIOG-> ODR &= ~(1<<Pin);
				break;	
		}
	}
}


u8 MDIO_GetPinValue(u8 Port , u8 Pin)
{
	u8 Result;
	if (Pin<=15)
	{
		switch(Port)	
		{
			case MDIO_PORTA: 
				if(((GPIOA->IDR >> Pin)&1) == 1)
					Result=MDIO_HIGH;
				else
					Result=MDIO_HIGH;
				break;
			case MDIO_PORTB:
				if(((GPIOA->IDR >> Pin)&1 )==1)
					Result=MDIO_HIGH;
				else 
					Result=MDIO_HIGH;
				break;
			case MDIO_PORTC:
				if(((GPIOA->IDR >> Pin)&1)==1)
					Result=MDIO_HIGH;
				else 
					Result=MDIO_HIGH;
				break;
			case MDIO_PORTD:
				if(((GPIOA->IDR >> Pin)&1)==1)
					Result=MDIO_HIGH;
				else 
					Result=MDIO_HIGH;
				break;
			case MDIO_PORTE:
				if(((GPIOA->IDR >> Pin)&1)==1)
					Result=MDIO_HIGH;
				else
					Result=MDIO_HIGH;
				break;	
			case MDIO_PORTF:
				if(((GPIOA->IDR >> Pin)&1)==1)
					Result=MDIO_HIGH;
				else 
					Result=MDIO_HIGH;
				break;	
			case MDIO_PORTG:
				if(((GPIOA->IDR >> Pin)&1)==1)
					Result=MDIO_HIGH;
				else 
					Result=MDIO_HIGH;
				break;
		}
	}
	return Result;
}







