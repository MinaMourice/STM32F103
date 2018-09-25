/************************************************/
/* Author	: Mina Mourice						*/
/* Date		: 8 August 2018						*/
/* Version	: 01								*/

#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "OS_interface.h"

void ZeroOn(void);
void OneOn(void);
void TwoOn(void);
void ThreeOn(void);
void FourOn(void);
void FiveOn(void);
void SixOn(void);
void SevenOn(void);
void EightOn(void);
void NineOn(void);
void ZeroOn_2(void);
void OneOn_2(void);
void TwoOn_2(void);
void ThreeOn_2(void);
void FourOn_2(void);
void FiveOn_2(void);
void SixOn_2(void);
void SevenOn_2(void);
void EightOn_2(void);
void NineOn_2(void);
void Task1_7segmentCountUp(void){
	static u16 Counter =0 ;
	if(0==Counter){ZeroOn();Counter=1;}
	else if(1==Counter){OneOn();Counter=2;}
	else if(2==Counter){TwoOn();Counter=3;}
	else if(3==Counter){ThreeOn();Counter=4;}
	else if(4==Counter){FourOn();Counter=5;}
	else if(5==Counter){FiveOn();Counter=6;}
	else if(6==Counter){SixOn();Counter=7;}
	else if(7==Counter){SevenOn();Counter=8;}
	else if(8==Counter){EightOn();Counter=9;}
	else if(9==Counter){NineOn();Counter=0;}
}


void Task2_7segmentCountDown(void)
{
	static u16 Counter =0 ;
	if(0==Counter){ZeroOn_2();Counter=9;}
	else if(1==Counter){OneOn_2();Counter=0;}
	else if(2==Counter){TwoOn_2();Counter=1;}
	else if(3==Counter){ThreeOn_2();Counter=2;}
	else if(4==Counter){FourOn_2();Counter=3;}
	else if(5==Counter){FiveOn_2();Counter=4;}
	else if(6==Counter){SixOn_2();Counter=5;}
	else if(7==Counter){SevenOn_2();Counter=6;}
	else if(8==Counter){EightOn_2();Counter=7;}
	else if(9==Counter){NineOn_2();Counter=8;}
}

void ZeroOn(void)
{
	MDIO_SetPinValue(0,0,1);MDIO_SetPinValue(0,1,1);MDIO_SetPinValue(0,2,1);MDIO_SetPinValue(0,3,1);
	MDIO_SetPinValue(0,4,1);MDIO_SetPinValue(0,5,1);MDIO_SetPinValue(0,6,0);
}
void OneOn(void)
{
	MDIO_SetPinValue(0,0,0);MDIO_SetPinValue(0,1,1);MDIO_SetPinValue(0,2,1);MDIO_SetPinValue(0,3,0);
	MDIO_SetPinValue(0,4,0);MDIO_SetPinValue(0,5,0);MDIO_SetPinValue(0,6,0);
}
void TwoOn(void)
{
	MDIO_SetPinValue(0,0,1);MDIO_SetPinValue(0,1,1);MDIO_SetPinValue(0,2,0);MDIO_SetPinValue(0,3,1);
	MDIO_SetPinValue(0,4,1);MDIO_SetPinValue(0,5,0);MDIO_SetPinValue(0,6,1);
}
void ThreeOn(void)
{
	MDIO_SetPinValue(0,0,1);MDIO_SetPinValue(0,1,1);MDIO_SetPinValue(0,2,1);MDIO_SetPinValue(0,3,1);
	MDIO_SetPinValue(0,4,0);MDIO_SetPinValue(0,5,0);MDIO_SetPinValue(0,6,1);
}
void FourOn(void)
{
	MDIO_SetPinValue(0,0,0);MDIO_SetPinValue(0,1,1);MDIO_SetPinValue(0,2,1);MDIO_SetPinValue(0,3,0);
	MDIO_SetPinValue(0,4,0);MDIO_SetPinValue(0,5,1);MDIO_SetPinValue(0,6,1);
}
void FiveOn(void)
{
	MDIO_SetPinValue(0,0,1);MDIO_SetPinValue(0,1,0);MDIO_SetPinValue(0,2,1);MDIO_SetPinValue(0,3,1);
	MDIO_SetPinValue(0,4,0);MDIO_SetPinValue(0,5,1);MDIO_SetPinValue(0,6,1);
}
void SixOn(void)
{
	MDIO_SetPinValue(0,0,1);MDIO_SetPinValue(0,1,0);MDIO_SetPinValue(0,2,1);MDIO_SetPinValue(0,3,1);
	MDIO_SetPinValue(0,4,1);MDIO_SetPinValue(0,5,1);MDIO_SetPinValue(0,6,1);
}
void SevenOn(void)
{
	MDIO_SetPinValue(0,0,1);MDIO_SetPinValue(0,1,1);MDIO_SetPinValue(0,2,1);MDIO_SetPinValue(0,3,0);
	MDIO_SetPinValue(0,4,0);MDIO_SetPinValue(0,5,0);MDIO_SetPinValue(0,6,0);
}
void EightOn(void)
{
	MDIO_SetPinValue(0,0,1);MDIO_SetPinValue(0,1,1);MDIO_SetPinValue(0,2,1);MDIO_SetPinValue(0,3,1);
	MDIO_SetPinValue(0,4,1);MDIO_SetPinValue(0,5,1);MDIO_SetPinValue(0,6,1);
}
void NineOn(void)
{
	MDIO_SetPinValue(0,0,1);MDIO_SetPinValue(0,1,1);MDIO_SetPinValue(0,2,1);MDIO_SetPinValue(0,3,1);
	MDIO_SetPinValue(0,4,0);MDIO_SetPinValue(0,5,0);MDIO_SetPinValue(0,6,1);
}


void ZeroOn_2(void)
{
	MDIO_SetPinValue(1,0,1);MDIO_SetPinValue(1,1,1);MDIO_SetPinValue(1,2,1);MDIO_SetPinValue(1,3,1);
	MDIO_SetPinValue(1,4,1);MDIO_SetPinValue(1,5,1);MDIO_SetPinValue(1,6,0);
}
void OneOn_2(void)
{
	MDIO_SetPinValue(1,0,0);MDIO_SetPinValue(1,1,1);MDIO_SetPinValue(1,2,1);MDIO_SetPinValue(1,3,0);
	MDIO_SetPinValue(1,4,0);MDIO_SetPinValue(1,5,0);MDIO_SetPinValue(1,6,0);
}
void TwoOn_2(void)
{
	MDIO_SetPinValue(1,0,1);MDIO_SetPinValue(1,1,1);MDIO_SetPinValue(1,2,0);MDIO_SetPinValue(1,3,1);
	MDIO_SetPinValue(1,4,1);MDIO_SetPinValue(1,5,0);MDIO_SetPinValue(1,6,1);
}
void ThreeOn_2(void)
{
	MDIO_SetPinValue(1,0,1);MDIO_SetPinValue(1,1,1);MDIO_SetPinValue(1,2,1);MDIO_SetPinValue(1,3,1);
	MDIO_SetPinValue(1,4,0);MDIO_SetPinValue(1,5,0);MDIO_SetPinValue(1,6,1);
}
void FourOn_2(void)
{
	MDIO_SetPinValue(1,0,0);MDIO_SetPinValue(1,1,1);MDIO_SetPinValue(1,2,1);MDIO_SetPinValue(1,3,0);
	MDIO_SetPinValue(1,4,0);MDIO_SetPinValue(1,5,1);MDIO_SetPinValue(1,6,1);
}
void FiveOn_2(void)
{
	MDIO_SetPinValue(1,0,1);MDIO_SetPinValue(1,1,0);MDIO_SetPinValue(1,2,1);MDIO_SetPinValue(1,3,1);
	MDIO_SetPinValue(1,4,0);MDIO_SetPinValue(1,5,1);MDIO_SetPinValue(1,6,1);
}
void SixOn_2(void)
{
	MDIO_SetPinValue(1,0,1);MDIO_SetPinValue(1,1,0);MDIO_SetPinValue(1,2,1);MDIO_SetPinValue(1,3,1);
	MDIO_SetPinValue(1,4,1);MDIO_SetPinValue(1,5,1);MDIO_SetPinValue(1,6,1);
}
void SevenOn_2(void)
{
	MDIO_SetPinValue(1,0,1);MDIO_SetPinValue(1,1,1);MDIO_SetPinValue(1,2,1);MDIO_SetPinValue(1,3,0);
	MDIO_SetPinValue(1,4,0);MDIO_SetPinValue(1,5,0);MDIO_SetPinValue(1,6,0);
}
void EightOn_2(void)
{
	MDIO_SetPinValue(1,0,1);MDIO_SetPinValue(1,1,1);MDIO_SetPinValue(1,2,1);MDIO_SetPinValue(1,3,1);
	MDIO_SetPinValue(1,4,1);MDIO_SetPinValue(1,5,1);MDIO_SetPinValue(1,6,1);
}
void NineOn_2(void)
{
	MDIO_SetPinValue(1,0,1);MDIO_SetPinValue(1,1,1);MDIO_SetPinValue(1,2,1);MDIO_SetPinValue(1,3,1);
	MDIO_SetPinValue(1,4,0);MDIO_SetPinValue(1,5,0);MDIO_SetPinValue(1,6,1);
}

