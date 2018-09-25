/****************************************/
/* Author	: Mina Mourice				*/
/* Date		: 11 August 2018				*/
/* Version	: V01						*/
/****************************************/

#include "LSTD_Types.h"

#include "MNVK_private.h"
#include "MNVK_Interface.h"


/* Enable MNVK */
void MNVK_Enable (u8 ID)
{
	/* Check ID of interrupt */
	if ( ID <=31)
	{
		/* ISER0 */
		MNVK_ISER[0]=(1<<ID);
	}
	else{
		/* ISER1 */
		ID = ID-32 ;
		MNVK_ISER[1]=(1<<ID);
	}

}

void MNVK_Disable (u8 ID)
{
	/* Enable Interrupt */
	if ( ID <=31)
	{
		/* ISER0 */
		MNVK_ICER[0]=(1<<ID);
	}
	else{
		/* ISER1 */
		ID = ID-32 ;
		MNVK_ICER[1]=(1<<ID);
	}

}

void MNVK_ClearPending (u8 ID)
{
	/* Set Clock to be AHB/8 and Enable Interrupt */
	if ( ID <=31)
	{
		/* ISER0 */
		MNVK_ICPR[0]=(1<<ID);
	}
	else{
		/* ISER1 */
		ID = ID-32 ;
		MNVK_ICPR[1]=(1<<ID);
	}
}

void MNVK_SetPending (u8 ID)
{
	/* Set Pending Flag */
	if ( ID <=31)
	{
		/* ISER0 */
		MNVK_ISPR[0]=(1<<ID);
	}
	else{
		/* ISER1 */
		ID = ID-32 ;
		MNVK_ISPR[1]=(1<<ID);
	}
}


