/*
 * main.c
 *
 *  Created on: Jul 28, 2018
 *      Author: Mina Mourice
 */
#include "LSTD_Types.h"
#include "MRCC_interface.h"
#include "MDIO_interface.h"

void delay (int a)
{
 volatile int i,j;
 for (i=0 ; i < a ; i++)
 {
  j++;
 }
 return;
}
void main(void)
{
	MRCC_InitializeClock();
	MDIO_Initialization();
while(1){
	All_On();
	delay(500000);
	All_Off();
	delay(500000);
}


}
