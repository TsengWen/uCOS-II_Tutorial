#ifndef __STM32F4_USART_H
#define __STM32F4_USART_H
#ifdef __cplusplus
extern "C" {
#endif
	
#include "misc.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"
#include "attributes.h"
#include "stm32f4_gpio.h"

/*@verbatim
             |PINSPACK 1     |PINSPACK 2     |PINSPACK 3	
U(S)ARTX     |TX     RX      |TX     RX      |TX     RX

USART1       |PA9    PA10    |PB6    PB7     |-      -
USART2       |PA2    PA3     |PD5    PD6     |-      -
USART3       |PB10   PB11    |PC10   PC11    |PD8    PD9
UART4        |PA0    PA1     |PC10   PC11    |-      -
UART5        |PC12   PD2     |-      -       |-      -
USART6       |PC6    PC7     |PG14   PG9     |-      -
UART7        |PE8    PE7     |PF7    PF6     |-      -
UART8        |PE1    PE0     |-      -       |-      -
@endverbatim*/

//Change X with possible U(S)ARTs: USART1, USART2, USART3, UART4, UART5, USART6, UART7, UART8
//Set flow control
#define USART_HARDWARE_FLOW_CONTROL		USART_HardwareFlowControl_None
//Set mode
#define USART_MODE						USART_Mode_Tx | USART_Mode_Rx
//Set parity
#define USART_PARITY						USART_Parity_No
//Set stopbits
#define USART_STOP_BITS					USART_StopBits_1
//Set USART datasize
#define USART_WORD_LENGTH				USART_WordLength_8b

#define USE_USART1
#define USE_USART2
#define USE_USART3
#define USE_UART4
#define USE_UART5
#define USE_USART6
#define USE_UART7
#define USE_UART8

/**
 * @defgroup USART_Typedefs
 * @brief    USART Typedefs
 * @{
 */
 
/**
 * @brief  USART PinsPack enumeration to select pins combination for USART
 */
typedef enum {
	USART_PinsPack_1,     /*!< Select PinsPack1 from Pinout table for specific USART */
	USART_PinsPack_2,     /*!< Select PinsPack2 from Pinout table for specific USART */
	USART_PinsPack_3,     /*!< Select PinsPack3 from Pinout table for specific USART */
	USART_PinsPack_Custom /*!< Select custom pins for specific USART, callback will be called, look @ref USART_InitCustomPinsCallback */
} USART_PinsPack_t;

/**
 * @brief  USART Hardware flow control selection
 * @note   Corresponsing pins must be initialized in case you don't use "None" options
 */
typedef enum {
	UART_HardwareFlowControl_None = 0x0000,   /*!< No flow control */
	UART_HardwareFlowControl_RTS = 0x0100,    /*!< RTS flow control */
	UART_HardwareFlowControl_CTS = 0x0200,    /*!< CTS flow control */
	UART_HardwareFlowControl_RTS_CTS = 0x0300 /*!< RTS and CTS flow control */
} USART_HardwareFlowControl_t;

/**
 * @}
 */

/**
 * @defgroup USART_Macros
 * @brief    USART default values for defines
 * @{
 *
 * All values can be overwritten in your project's defines.h file.
 * 
 * Do this only in case you know what are you doing.
 */

/* Default buffer size for each USART */
#ifndef USART_BUFFER
#define USART_BUFFER 				32
#endif

/* Set default buffer size for specific USART if not set by user */
#ifndef USART1_BUFFER_SIZE
#define USART1_BUFFER_SIZE			USART_BUFFER
#endif
#ifndef USART2_BUFFER_SIZE
#define USART2_BUFFER_SIZE			USART_BUFFER
#endif
#ifndef USART3_BUFFER_SIZE
#define USART3_BUFFER_SIZE			USART_BUFFER
#endif
#ifndef UART4_BUFFER_SIZE
#define UART4_BUFFER_SIZE			USART_BUFFER
#endif
#ifndef UART5_BUFFER_SIZE
#define UART5_BUFFER_SIZE			USART_BUFFER
#endif
#ifndef USART6_BUFFER_SIZE
#define USART6_BUFFER_SIZE			USART_BUFFER
#endif
#ifndef UART7_BUFFER_SIZE
#define UART7_BUFFER_SIZE			USART_BUFFER
#endif
#ifndef UART8_BUFFER_SIZE
#define UART8_BUFFER_SIZE			USART_BUFFER
#endif

/* NVIC Global Priority */
#ifndef USART_NVIC_PRIORITY
#define USART_NVIC_PRIORITY				0x06
#endif

/* U(S)ART settings, can be changed in your defines.h project file */
/* USART1 default settings */
#ifndef USART1_HARDWARE_FLOW_CONTROL
#define USART1_HARDWARE_FLOW_CONTROL		UART_HardwareFlowControl_None
#endif
#ifndef USART1_MODE
#define USART1_MODE						USART_Mode_Tx | USART_Mode_Rx
#endif
#ifndef USART1_PARITY
#define USART1_PARITY					USART_Parity_No
#endif
#ifndef USART1_STOP_BITS
#define USART1_STOP_BITS					USART_StopBits_1
#endif
#ifndef USART1_WORD_LENGTH
#define USART1_WORD_LENGTH				USART_WordLength_8b
#endif

/* USART2 default settings */
#ifndef USART2_HARDWARE_FLOW_CONTROL
#define USART2_HARDWARE_FLOW_CONTROL		UART_HardwareFlowControl_None
#endif
#ifndef USART2_MODE
#define USART2_MODE						USART_Mode_Tx | USART_Mode_Rx
#endif
#ifndef USART2_PARITY
#define USART2_PARITY					USART_Parity_No
#endif
#ifndef USART2_STOP_BITS
#define USART2_STOP_BITS					USART_StopBits_1
#endif
#ifndef USART2_WORD_LENGTH
#define USART2_WORD_LENGTH				USART_WordLength_8b
#endif

/* USART3 default settings */
#ifndef USART3_HARDWARE_FLOW_CONTROL
#define USART3_HARDWARE_FLOW_CONTROL		UART_HardwareFlowControl_None
#endif
#ifndef USART3_MODE
#define USART3_MODE						USART_Mode_Tx | USART_Mode_Rx
#endif
#ifndef USART3_PARITY
#define USART3_PARITY					USART_Parity_No
#endif
#ifndef USART3_STOP_BITS
#define USART3_STOP_BITS					USART_StopBits_1
#endif
#ifndef USART3_WORD_LENGTH
#define USART3_WORD_LENGTH				USART_WordLength_8b
#endif

/* UART4 default settings */
#ifndef UART4_HARDWARE_FLOW_CONTROL
#define UART4_HARDWARE_FLOW_CONTROL		UART_HardwareFlowControl_None
#endif
#ifndef UART4_MODE
#define UART4_MODE						USART_Mode_Tx | USART_Mode_Rx
#endif
#ifndef UART4_PARITY
#define UART4_PARITY						USART_Parity_No
#endif
#ifndef UART4_STOP_BITS
#define UART4_STOP_BITS					USART_StopBits_1
#endif
#ifndef UART4_WORD_LENGTH
#define UART4_WORD_LENGTH				USART_WordLength_8b
#endif

/* UART5 default settings */
#ifndef UART5_HARDWARE_FLOW_CONTROL
#define UART5_HARDWARE_FLOW_CONTROL		UART_HardwareFlowControl_None
#endif
#ifndef UART5_MODE
#define UART5_MODE						USART_Mode_Tx | USART_Mode_Rx
#endif
#ifndef UART5_PARITY
#define UART5_PARITY						USART_Parity_No
#endif
#ifndef UART5_STOP_BITS
#define UART5_STOP_BITS					USART_StopBits_1
#endif
#ifndef UART5_WORD_LENGTH
#define UART5_WORD_LENGTH				USART_WordLength_8b
#endif

/* USART6 default settings */
#ifndef USART6_HARDWARE_FLOW_CONTROL
#define USART6_HARDWARE_FLOW_CONTROL		UART_HardwareFlowControl_None
#endif
#ifndef USART6_MODE
#define USART6_MODE						USART_Mode_Tx | USART_Mode_Rx
#endif
#ifndef USART6_PARITY
#define USART6_PARITY					USART_Parity_No
#endif
#ifndef USART6_STOP_BITS
#define USART6_STOP_BITS					USART_StopBits_1
#endif
#ifndef USART6_WORD_LENGTH
#define USART6_WORD_LENGTH				USART_WordLength_8b
#endif

/* UART7 default settings */
#ifndef UART7_HARDWARE_FLOW_CONTROL
#define UART7_HARDWARE_FLOW_CONTROL		UART_HardwareFlowControl_None
#endif
#ifndef UART7_MODE
#define UART7_MODE						USART_Mode_Tx | USART_Mode_Rx
#endif
#ifndef UART7_PARITY
#define UART7_PARITY						USART_Parity_No
#endif
#ifndef UART7_STOP_BITS
#define UART7_STOP_BITS					USART_StopBits_1
#endif
#ifndef UART7_WORD_LENGTH
#define UART7_WORD_LENGTH				USART_WordLength_8b
#endif

/* UART8 default settings */
#ifndef UART8_HARDWARE_FLOW_CONTROL
#define UART8_HARDWARE_FLOW_CONTROL		UART_HardwareFlowControl_None
#endif
#ifndef UART8_MODE
#define UART8_MODE						USART_Mode_Tx | USART_Mode_Rx
#endif
#ifndef UART8_PARITY
#define UART8_PARITY						USART_Parity_No
#endif
#ifndef UART8_STOP_BITS
#define UART8_STOP_BITS					USART_StopBits_1
#endif
#ifndef UART8_WORD_LENGTH
#define UART8_WORD_LENGTH				USART_WordLength_8b
#endif

/**
 * @brief  Wait till USART finishes transmission
 */
#define USART_TXEMPTY(USARTx)               ((USARTx)->SR & USART_FLAG_TXE)
#define USART_WAIT(USARTx)                  do { while (!USART_TXEMPTY(USARTx)); } while (0)

/**
 * @brief  Default string delimiter for USART
 */
#define USART_STRING_DELIMITER              '\n'

 /**
 * @}
 */

/**
 * @defgroup USART_Functions
 * @brief    USART Functions
 * @{
 */

/**
 * @brief  Initializes USARTx peripheral and corresponding pins
 * @param  *USARTx: Pointer to USARTx peripheral you will use
 * @param  pinspack: This parameter can be a value of @ref USART_PinsPack_t enumeration
 * @param  baudrate: Baudrate number for USART communication
 * @retval None
 */
void USART_Inits(USART_TypeDef* USARTx, USART_PinsPack_t pinspack, uint32_t baudrate);

/**
 * @brief  Initializes USARTx peripheral and corresponding pins with custom hardware flow control mode
 * @note   Hardware flow control pins are not initialized. Easy solution is to use @arg USART_PinsPack_Custom pinspack option 
 *         when you call @ref USART_Init() function and initialize all USART pins at a time inside @ref USART_InitCustomPinsCallback() 
 *         callback function, which will be called from my library
 * @param  *USARTx: Pointer to USARTx peripheral you will use
 * @param  pinspack: This parameter can be a value of @ref USART_PinsPack_t enumeration
 * @param  baudrate: Baudrate number for USART communication
 * @param  FlowControl: Flow control mode you will use. This parameter can be a value of @ref UART_HardwareFlowControl_t enumeration
 * @retval None
 */
void USART_InitWithFlowControl(USART_TypeDef* USARTx, USART_PinsPack_t pinspack, uint32_t baudrate, USART_HardwareFlowControl_t FlowControl);

/**
 * @brief  Puts character to USART port
 * @param  *USARTx: Pointer to USARTx peripheral you will use
 * @param  c: character to be send over USART
 * @retval None
 */
static __INLINE void USART_Putc(USART_TypeDef* USARTx, volatile char c) {
	/* Check USART if enabled */
	if ((USARTx->CR1 & USART_CR1_UE)) {	
		/* Wait to be ready, buffer empty */
		USART_WAIT(USARTx);
		/* Send data */
		USARTx->DR = (uint16_t)(c & 0x01FF);
		/* Wait to be ready, buffer empty */
		USART_WAIT(USARTx);
	}
}

/**
 * @brief  Puts string to USART port
 * @param  *USARTx: Pointer to USARTx peripheral you will use
 * @param  *str: Pointer to string to send over USART
 * @retval None
 */
void USART_Puts(USART_TypeDef* USARTx, char* str);

/**
 * @brief  Sends data array to USART port
 * @param  *USARTx: Pointer to USARTx peripheral you will use
 * @param  *DataArray: Pointer to data array to be sent over USART
 * @param  count: Number of elements in data array to be send over USART
 * @retval None
 */
void USART_Send(USART_TypeDef* USARTx, uint8_t* DataArray, uint16_t count);

/**
 * @brief  Gets character from internal USART buffer
 * @param  *USARTx: Pointer to USARTx peripheral you will use
 * @retval Character from buffer, or 0 if nothing in buffer
 */
uint8_t USART_Getc(USART_TypeDef* USARTx);

/**
 * @brief  Gets string from USART
 *
 *         This function can create a string from USART received data.
 *
 *         It generates string until "\n" is not recognized or buffer length is full.
 * 
 * @note   As of version 1.5, this function automatically adds 0x0A (Line feed) at the end of string.
 * @param  *USARTx: Pointer to USARTx peripheral you will use
 * @param  *buffer: Pointer to buffer where data will be stored from buffer
 * @param  bufsize: maximal number of characters we can add to your buffer, including leading zero
 * @retval Number of characters in buffer
 */
uint16_t USART_Gets(USART_TypeDef* USARTx, char* buffer, uint16_t bufsize);

/**
 * @brief  Checks if character c is available in internal buffer
 * @param  *USARTx: Pointer to USARTx peripheral you will use
 * @param  c: character to check if it is in USARTx's buffer
 * @retval Character status:
 *            - 0: Character was not found
 *            - > 0: Character has been found in buffer
 */
uint8_t USART_FindCharacter(USART_TypeDef* USARTx, uint8_t c);

/**
 * @brief  Checks if internal USARTx buffer is empty
 * @param  *USARTx: Pointer to USARTx peripheral you will use
 * @retval Buffer empty status:
 *            - 0: Buffer is not empty
 *            - > 0: Buffer is empty
 */
uint8_t USART_BufferEmpty(USART_TypeDef* USARTx);

/**
 * @brief  Checks if internal USARTx buffer is full
 * @param  *USARTx: Pointer to USARTx peripheral you will use
 * @retval Buffer full status:
 *            - 0: Buffer is not full
 *            - > 0: Buffer is full
 */
uint8_t USART_BufferFull(USART_TypeDef* USARTx);

/**
 * @brief  Clears internal USART buffer
 * @param  *USARTx: Pointer to USARTx peripheral you will use
 * @retval None
 */
void USART_ClearBuffer(USART_TypeDef* USARTx);

/**
 * @brief  Sets custom character for @ref USART_Gets() function to detect when string ends
 * @param  *USARTx: Pointer to USARTx peripheral you will use
 * @param  Character: Character value to be used as string end
 * @note   Character will also be added at the end for your buffer when calling @ref USART_Gets() function
 * @retval None
 */
void USART_SetCustomStringEndCharacter(USART_TypeDef* USARTx, uint8_t Character);

/**
 * @brief  Callback for custom pins initialization for USARTx.
 *
 *         When you call @ef USART_Init() function, and if you pass @arg USART_PinsPack_Custom to function,
 *         then this function will be called where you can initialize custom pins for USART peripheral.
 * @param  *USARTx: Pointer to USARTx peripheral you will use for initialization
 * @param  AlternateFunction: Alternate function which should be used for GPIO initialization
 * @retval None
 * @note   With __weak parameter to prevent link errors if not defined by user
 */
void USART_InitCustomPinsCallback(USART_TypeDef* USARTx, uint16_t AlternateFunction);

/**
 * @brief  Callback function for receive interrupt on USART1 in case you have enabled custom USART handler mode 
 * @note   With __weak parameter to prevent link errors if not defined by user
 * @param  c: character received via USART
 * @retval None
 */
__weak void USART1_ReceiveHandler(uint8_t c);

/**
 * @brief  Callback function for receive interrupt on USART2 in case you have enabled custom USART handler mode 
 * @note   With __weak parameter to prevent link errors if not defined by user
 * @param  c: character received via USART
 * @retval None
 */
__weak void USART2_ReceiveHandler(uint8_t c);

/**
 * @brief  Callback function for receive interrupt on USART3 in case you have enabled custom USART handler mode 
 * @note   With __weak parameter to prevent link errors if not defined by user
 * @param  c: character received via USART
 * @retval None
 */
__weak void USART3_ReceiveHandler(uint8_t c);

/**
 * @brief  Callback function for receive interrupt on UART4 in case you have enabled custom USART handler mode 
 * @note   With __weak parameter to prevent link errors if not defined by user
 * @param  c: character received via USART
 * @retval None
 */
__weak void UART4_ReceiveHandler(uint8_t c);

/**
 * @brief  Callback function for receive interrupt on UART5 in case you have enabled custom USART handler mode 
 * @note   With __weak parameter to prevent link errors if not defined by user
 * @param  c: character received via USART
 * @retval None
 */
__weak void UART5_ReceiveHandler(uint8_t c);

/**
 * @brief  Callback function for receive interrupt on USART6 in case you have enabled custom USART handler mode 
 * @note   With __weak parameter to prevent link errors if not defined by user
 * @param  c: character received via USART
 * @retval None
 */
__weak void USART6_ReceiveHandler(uint8_t c);

/**
 * @brief  Callback function for receive interrupt on UART7 in case you have enabled custom USART handler mode 
 * @note   With __weak parameter to prevent link errors if not defined by user
 * @param  c: character received via USART
 * @retval None
 */
__weak void UART7_ReceiveHandler(uint8_t c);

/**
 * @brief  Callback function for receive interrupt on UART8 in case you have enabled custom USART handler mode 
 * @note   With __weak parameter to prevent link errors if not defined by user
 * @param  c: character received via USART
 * @retval None
 */
__weak void UART8_ReceiveHandler(uint8_t c);

#ifdef __cplusplus
}
#endif

#endif
