#include "main.h"

#define LED_BLINK_STK_SIZE		64
#define LED_RED_PRIO			10
#define LED_GREEN_PRIO			9

OS_STK led_red_task_stk[LED_BLINK_STK_SIZE];
OS_STK led_green_task_stk[LED_BLINK_STK_SIZE];

const char *parameter = "Blink LED RED\r\n";

void task_led_red(void *pdata);
void task_led_green(void *pdata);

int main(void)
{
	CPU_IntDis();
	OSInit();
	BSP_Init();
	
	/*task create using parameter */
	OSTaskCreate(task_led_red, (void*)parameter, &led_red_task_stk[LED_BLINK_STK_SIZE-1],LED_RED_PRIO);
	/*task create no using parameter */
	OSTaskCreate(task_led_green, 0, &led_green_task_stk[LED_BLINK_STK_SIZE-1],LED_GREEN_PRIO);
	
	OSStart();
}

/* delay led red 500ms */
void task_led_red(void *pdata)
{
	char *pcTaskName;
	pcTaskName = ( char * ) pdata;
	
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
