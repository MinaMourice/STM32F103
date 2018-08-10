/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 10 August 2018					*/
/* Version : 01								*/
/********************************************/

#ifndef _OS_PRIVATE_H_
#define _OS_PRIVATE_H_

#define Active 1
#define Suspended 0

typedef struct
{
	void (*Taskhandler)(void);
	u16 Periodicity ;
	u8 State ;
	u16 FirstDelay ;
}Task;

#endif
