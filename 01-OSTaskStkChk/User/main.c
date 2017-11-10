#include "main.h"

#define LED_BLINK_STK_SIZE		64
#define LED_RED_PRIO			10
#define LED_GREEN_PRIO			9

OS_STK led_red_task_stk[LED_BLINK_STK_SIZE];
OS_STK led_green_task_stk[LED_BLINK_STK_SIZE];

OS_STK_DATA  stack_mem;
INT32U stack_size;
INT8U err;

const char *parameter = "Blink LED RED\r\n";

void task_led_red(void *pdata);
void task_led_green(void *pdata);

int main(void)
{
	CPU_IntDis();
	OSInit();
	BSP_Init();
	
	
	USART_Puts(USART1, "Using OSTaskStkChk\r\n");
	
	
	/*task create using parameter */
	OSTaskCreateExt(task_led_red,(void *)parameter,(OS_STK *)&led_red_task_stk[LED_BLINK_STK_SIZE-1],
					LED_RED_PRIO,LED_RED_PRIO,(OS_STK *)&led_red_task_stk[0],
					LED_BLINK_STK_SIZE,(void *)0,
					OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);
					
	OSTaskCreateExt(task_led_green,(void *)0,(OS_STK *)&led_green_task_stk[LED_BLINK_STK_SIZE-1],
					LED_GREEN_PRIO,LED_GREEN_PRIO,(OS_STK *)&led_green_task_stk[0],
					LED_BLINK_STK_SIZE,(void *)0,
					OS_TASK_OPT_STK_CHK|OS_TASK_OPT_STK_CLR);
	
	OSStart();
}

/* delay led red 500ms */
void task_led_red(void *pdata)
{
	char SentData[20];
	char *pcTaskName;
	pcTaskName = ( char * ) pdata;
	
	err = OSTaskStkChk(LED_RED_PRIO,&stack_mem);
	if(err == OS_ERR_NONE)
		stack_size = stack_mem.OSFree + stack_mem.OSUsed;

	sprintf(SentData,"Task Priority: %03d, ",LED_RED_PRIO);
	USART_Puts(USART1, SentData);
	sprintf(SentData,"Free: %03d, ",stack_mem.OSFree);
	USART_Puts(USART1, SentData);
	sprintf(SentData,"Used: %03d, ",stack_mem.OSUsed);
	USART_Puts(USART1, SentData);
	sprintf(SentData,"Total: %03d\r\n",stack_size);
	USART_Puts(USART1, SentData);
	
	err = OSTaskStkChk(LED_GREEN_PRIO,&stack_mem);
	if(err == OS_ERR_NONE)
		stack_size = stack_mem.OSFree + stack_mem.OSUsed;

	sprintf(SentData,"Task Priority: %03d, ",LED_GREEN_PRIO);
	USART_Puts(USART1, SentData);
	sprintf(SentData,"Free: %03d, ",stack_mem.OSFree);
	USART_Puts(USART1, SentData);
	sprintf(SentData,"Used: %03d, ",stack_mem.OSUsed);
	USART_Puts(USART1, SentData);
	sprintf(SentData,"Total: %03d\r\n",stack_size);
	USART_Puts(USART1, SentData);
	while(1)
	{
		USART_Puts(USART1,pcTaskName);
		BSP_LED_Toggle(LED_RED);
		OSTimeDlyHMSM(0u, 0u, 0u, 500u);
	}
}

/* delay led green 500ms */
void task_led_green(void *pdata)
{
	while(1)
	{
		USART_Puts(USART1, "Blink LED GREEN\r\n");
		BSP_LED_Toggle(LED_GREEN);
		OSTimeDlyHMSM(0u, 0u, 0u, 500u);
	}
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
