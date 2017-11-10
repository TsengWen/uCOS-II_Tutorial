#define   BSP_MODULE
#include  <bsp.h>


void  BSP_Init (void)
{
	SystemInit();
	//RCC_GetClocksFreq(&RCC_Clocks);
	//SysTick_Config(RCC_Clocks.HCLK_Frequency / 100);
	SysTick_Config(SystemCoreClock / 100);
    BSP_LED_Init();
	
	USART_Inits(USART1, USART_PinsPack_1, 115200);
	USART_Puts(USART1, "\r\nuC/OS-II STM32F429ZI-DISC\r\n");
	USART_Puts(USART1, "-----------------------------\r\n");
}


/*
*********************************************************************************************************
*                                           BSP_LED_Init()
*
* Description : Initialize any or all the LEDs on the board.
*
* Argument(s) : led     The ID of the LED to control:
*
*                       0    inialize ALL  LEDs
*                       1    inialize user LED1
*                       2    inialize user LED2
*                       3    inialize user LED3
*                       4    inialize user LED4
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);

	//GPIO initialize
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
	GPIO_Init(GPIOG, &GPIO_InitStructure);
}


/*
*********************************************************************************************************
*                                             BSP_LED_On()
*
* Description : Turn ON any or all the LEDs on the board.
*
* Argument(s) : led     The ID of the LED to control:
*
*                       0    turns ON ALL  LEDs
*                       1    turns ON user LED1
*                       2    turns ON user LED2
*                       3    turns ON user LED3
*                       4    turns ON user LED4
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_On (Led_TypeDef  led)
{
	switch (led)
	{
		case LED_GREEN:
			GPIOG->BSRRL = BSP_LED_GREEN;
			break;

		case LED_RED:
			GPIOG->BSRRL = BSP_LED_RED;
			break;

		case LED_ALL:
			GPIOG->BSRRL = BSP_LED_GREEN;
			GPIOG->BSRRL = BSP_LED_RED;
			break;

		default:
			break;
	}
}


/*
*********************************************************************************************************
*                                              BSP_LED_Off()
*
* Description : Turn OFF any or all the LEDs on the board.
*
* Argument(s) : led     The ID of the LED to control:
*
*                       0    turns OFF ALL the LEDs
*                       1    turns OFF user LED1
*                       2    turns OFF user LED2
*                       3    turns OFF user LED3
*                       4    turns OFF user LED4
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_Off (Led_TypeDef  led)
{
	switch (led)
	{
		case LED_GREEN:
			GPIOG->BSRRH = BSP_LED_GREEN;
			break;

		case LED_RED:
			GPIOG->BSRRH = BSP_LED_RED;
			break;

		case LED_ALL:
			GPIOG->BSRRH = BSP_LED_GREEN;
			GPIOG->BSRRH = BSP_LED_RED;
			break;

		default:
			break;
	}
}


/*
*********************************************************************************************************
*                                            BSP_LED_Toggle()
*
* Description : TOGGLE any or all the LEDs on the board.
*
* Argument(s) : led     The ID of the LED to control:
*
*                       0    TOGGLE ALL the LEDs
*                       1    TOGGLE user LED1
*                       2    TOGGLE user LED2
*                       3    TOGGLE user LED3
*                       4    TOGGLE user LED4
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void BSP_LED_Toggle(Led_TypeDef  led)
{
	switch (led)
	{
		case LED_GREEN:
			GPIOG->ODR ^= BSP_LED_GREEN;
			break;

		case LED_RED:
			GPIOG->ODR ^= BSP_LED_RED;
			break;

		case LED_ALL:
			GPIOG->ODR ^= BSP_LED_GREEN;
			GPIOG->ODR ^= BSP_LED_RED;
			break;

		default:
			break;
	}
}
