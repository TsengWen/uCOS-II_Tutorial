#include "main.h"

#define LED_BLINK_STK_SIZE		64
uint8_t red_prio_old, red_prio_new;			
uint8_t green_prio_old, green_prio_new;

OS_STK led_red_task_stk[LED_BLINK_STK_SIZE];
OS_STK led_green_task_stk[LED_BLINK_STK_SIZE];

void task_led_red(void *pdata);
void task_led_green(void *pdata);

int main(void)
{
	CPU_IntDis();
	OSInit();
	BSP_Init();
	
	USART_Puts(USART1, "OSTaskChangePrio\r\n");
	red_prio_old = 11;			
	green_prio_old = 21;
	
	OSTaskCreate(task_led_red, 0, &led_red_task_stk[LED_BLINK_STK_SIZE-1],red_prio_old);
	OSTaskCreate(task_led_green, 0, &led_green_task_stk[LED_BLINK_STK_SIZE-1],green_prio_old);
	
	OSStart();
}

/* delay led red 1s */
void task_led_red(void *pdata)
{
	char SentData[20];
	uint8_t index = 0;
	while(1)
	{
		if(red_prio_old <= 20)
		{
			red_prio_new = red_prio_old + 1;
			OSTaskChangePrio(red_prio_old, red_prio_new);
			red_prio_old = red_prio_new;
			
			if(red_prio_old == 20) red_prio_old =11;
		}
		sprintf(SentData,"Task led red Priority: %03d\r\n", red_prio_new);
		USART_Puts(USART1, SentData);
		BSP_LED_Toggle(LED_RED);
		OSTimeDlyHMSM(0u, 0u, 1u, 0u);
	}
}

/* delay led green 500ms */
void task_led_green(void *pdata)
{
	char SentData[20];
	uint8_t index = 0;
	while(1)
	{
		if(green_prio_old <= 30)
		{
			green_prio_new = green_prio_old + 1;
			OSTaskChangePrio(green_prio_old, green_prio_new);
			green_prio_old = green_prio_new;
			
			if(green_prio_old == 30) green_prio_old =21;
		}
		sprintf(SentData,"Task led green Priority: %03d\r\n", green_prio_new);
		USART_Puts(USART1, SentData);
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
