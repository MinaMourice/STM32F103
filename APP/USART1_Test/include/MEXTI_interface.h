/****************************************/
/* Author	: Mina Mourice				*/
/* Date		: 11 August 2018				*/
/* Version	: V01						*/
/****************************************/ 
#ifndef _MEXTI_INTERFACE_H_
#define _MEXTI_INTERFACE_H_

#define MEXTI_RISING	21
#define MEXTI_FALLING	6
#define MEXTI_IOC		96

/* Enable MEXTI */
void MEXTI_Enable (u8 ID);
      
void MEXTI_Disable (u8 ID);
      
void MEXTI_SetMode(u8 ID,u8 Mode);
      
void MEXTI_SetCallBack(u8 ID,void(*ptr)(void));
	  
#endif
