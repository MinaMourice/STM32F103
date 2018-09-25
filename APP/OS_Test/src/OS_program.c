/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 10 August 2018					*/
/* Version : 01								*/
/********************************************/


#include "LSTD_Types.h"

#include "MSTk_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
Task SysTasks[NUMBER_OF_TASKS] = {0};

volatile u8 TickCount =0 ;
/* Scheduler */
void Scheduler (void)
{
	u8 i ;
	TickCount++;
	for (i=0 ; i<2;i++)
	{
		if(SysTasks[i].State==Active)
		{
			if(SysTasks[i].FirstDelay==0)
			{
					SysTasks[i].Taskhandler();
			}
			else
			{
				SysTasks[i].FirstDelay--;
			}
		}
	}
}

/* OS Initialization : To sent scheduler function to systick callback */
void OS_Start(void)
{
	/* Set Systick Call back */
	MSTK_SetCallback(Scheduler);
	
	/* Configure Tick Time */
	MSTK_Start(1000000);
}

/* Create Task 
return	0 : Wrong Periority
		1 : Correct Periority
*/
u8 OS_CreateTask(void (*Handler)(void) , u16 Periodicity,u8 Priority)
{
	u8 Result ;
	if(	(Priority <NUMBER_OF_TASKS) && (SysTasks[Priority].Periodicity == 0) )
	{
		SysTasks[Priority].Taskhandler = Handler ;
		SysTasks[Priority].Periodicity = Periodicity;
		SysTasks[Priority].State=Active;
		Result	=	1;
	}
	else{
		Result = 0;
	}
	return Result ;
}




/* Delete Task */
void OS_DeleteTask(u8 Priority)
{
	if(	Priority<NUMBER_OF_TASKS )
	{
		SysTasks[Priority].Periodicity=0;
	}
}

/* Suspend Tssk */
u8 OS_SuspendTask(u8 Priority){
	u8 Result ;
	if(	(Priority <NUMBER_OF_TASKS) && (SysTasks[Priority].Periodicity == 0) )
	{
		SysTasks[Priority].State=Suspended;
		Result=1;
	}
	else
		Result =0 ;
	return Result;
}

/* Activate Task */
u8 OS_ActivateTask(u8 Priority)
{
	u8 Result ;
	if(	Priority<NUMBER_OF_TASKS )
	{
		SysTasks[Priority].State=Active;
		Result=1;
	}
	else
	{
		Result=0;
	}
	return Result;
}
