/****************************************/
/* Author	: Mina Mourice				*/
/* Date		: 4 August 2018				*/
/* Version	: 01						*/
/****************************************/
#ifndef _MSTK_PRIVATE_H_
#define _MSTK_PRIVATE_H_

typedef struct
{
	u32 CTRL ;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}MSTK_type;	

#define MSTK ((volatile MSTK_type*)0xE000E010)


#endif