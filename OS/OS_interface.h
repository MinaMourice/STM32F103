/********************************************/
/* Author  : Mina Mourice					*/
/* Date	   : 10 August 2018					*/
/* Version : 01								*/
/********************************************/

#ifndef _OS_INTERFACE_H_
#define _OS_INTERFACE_H_

#define NUMBER_OF_TASKS 255

/* OS Initialization : To sent scheduler function to systick callback */
void OS_Start(void);

/* Create Task 
return	0 : Wrong Periority
		1 : Correct Periority
*/
u8 OS_CreateTask(void (*Handler)(void) , u16 Periodicity,u8 Priority);

/* Delete Task */
void OS_DeleteTask(u8 Priority);

/* Suspend Tssk */
u8 OS_SuspendTask(u8 Priority);

/* Activate Task */
u8 OS_ActivateTask(u8 Priority);


#endif
