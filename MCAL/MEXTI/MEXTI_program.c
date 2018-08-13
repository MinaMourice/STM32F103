/*********)
*******************************/
/* Author	: Mina Mourice				*/
/* Date		: 11 August 2018				*/
/* Version	: V01						*/
/****************************************/

#include "LSTD_Types.h"
#include "MEXTI_private.h"
#include "MEXTI_Interface.h"




void MEXTI_Enable (u8 ID)
{
	if(ID<19)
	{
		MEXTI -> IMR |=(1<<ID);
	}
}



void MEXTI_Disable (u8 ID)
{
	if(ID<19)
	{
		MEXTI -> IMR &=~(1<<ID);
	}
}


void MEXTI_SetMode(u8 ID,u8 Mode)
{
	if(ID<19)
	{
		switch(Mode)
		{
			case MEXTI_RISING	:
				MEXTI -> RTSR |=(1<<ID);
				MEXTI -> FTSR &=~(1<<ID);
				break;
			case MEXTI_FALLING	:
				MEXTI -> RTSR &=~(1<<ID);
				MEXTI -> FTSR |=(1<<ID);			
				break;
			case MEXTI_IOC		:
				MEXTI -> RTSR |=(1<<ID);
				MEXTI -> FTSR |=(1<<ID);			
				break;
			default 			: 
				
			break;
		}
	}
}






/* array of pointer to function*/
void (*Callback[19])(void);

void MEXTI_SetCallBack(u8 ID,void(*ptr)(void))
{
	if(ID<19)
	{
		Callback[ID]=ptr;

	}
	
}

void EXTI0_IRQHandler(void){

	/* */
	Callback[0]();
	MEXTI->PR|=(1<<0);

}
void EXTI1_IRQHandler(void){

	/* */
	Callback[1]();

}
