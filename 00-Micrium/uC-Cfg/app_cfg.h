#ifndef  APP_CFG_MODULE_PRESENT
#define  APP_CFG_MODULE_PRESENT

#define  APP_CFG_MUTEX_PRIO                     2u
#define  APP_CFG_TASK_START_PRIO                3u
#define  APP_CFG_TASK_EVENT0_PRIO               4u
#define  APP_CFG_TASK_EVENT1_PRIO               5u
#define  APP_CFG_TASK_EQ0_PRIO                  6u
#define  APP_CFG_TASK_EQ1_PRIO                  7u
#define  OS_TASK_TMR_PRIO                (OS_LOWEST_PRIO - 2u)


/*
*********************************************************************************************************
*                                            TASK STACK SIZES
*                             Size of the task stacks (# of OS_STK entries)
*********************************************************************************************************
*/

#define  APP_CFG_TASK_START_STK_SIZE            256u
#define  APP_CFG_TASK_EQ_STK_SIZE               512u
#define  APP_CFG_TASK_OBJ_STK_SIZE              256u

#endif
