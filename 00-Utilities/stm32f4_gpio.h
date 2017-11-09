#ifndef __STM32F4_GPIO_H
#define __STM32F4_GPIO_H
#ifdef __cplusplus
 extern "C" {
#endif
     
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"

/**
 * @defgroup GPIO_Functions
 * @brief    GPIO Functions
 * @{
 */
 
/**
 * @brief  Initializes GPIO pins(s)
 * @note   This function also enables clock for GPIO port
 * @param  GPIOx: Pointer to GPIOx port you will use for initialization
 * @param  GPIO_Pin: GPIO pin(s) you will use for initialization
 * @param  GPIO_Mode: Select GPIO mode. This parameter can be a value of @ref GPIOMode_TypeDef enumeration
 * @param  GPIO_OType: Select GPIO Output type. This parameter can be a value of @ref GPIOOType_TypeDef enumeration
 * @param  GPIO_PuPd: Select GPIO pull resistor. This parameter can be a value of @ref GPIOPuPd_TypeDef enumeration
 * @param  GPIO_Speed: Select GPIO speed. This parameter can be a value of @ref GPIOSpeed_TypeDef enumeration
 * @retval None
 */
void GPIO_Inits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef GPIO_Mode, GPIOOType_TypeDef GPIO_OType, GPIOPuPd_TypeDef GPIO_PuPd, GPIOSpeed_TypeDef GPIO_Speed);

/**
 * @brief  Initializes GPIO pins(s) as alternate function
 * @note   This function also enables clock for GPIO port
 * @param  GPIOx: Pointer to GPIOx port you will use for initialization
 * @param  GPIO_Pin: GPIO pin(s) you will use for initialization
 * @param  GPIO_OType: Select GPIO Output type. This parameter can be a value of @ref GPIOOType_TypeDef enumeration
 * @param  GPIO_PuPd: Select GPIO pull resistor. This parameter can be a value of @ref GPIOPuPd_TypeDef enumeration
 * @param  GPIO_Speed: Select GPIO speed. This parameter can be a value of @ref GPIOSpeed_TypeDef enumeration
 * @param  Alternate: Alternate function you will use
 * @retval None
 */
void GPIO_InitAlternate(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOOType_TypeDef GPIO_OType, GPIOPuPd_TypeDef GPIO_PuPd, GPIOSpeed_TypeDef GPIO_Speed, uint8_t Alternate);

/**
 * @brief  Deinitializes pin(s)
 * @note   Pins(s) will be set as analog mode to get low power consumption
 * @param  GPIOx: GPIOx PORT where you want to set pin as input
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to set them as input
 * @retval None
 */
void GPIO_DeInits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/**
 * @brief  Sets pin(s) as input 
 * @note   Pins HAVE to be initialized first using @ref GPIO_Init() or @ref GPIO_InitAlternate() function
 * @note   This is just an option for fast input mode
 * @param  GPIOx: GPIOx PORT where you want to set pin as input
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to set them as input
 * @retval None
 */
void GPIO_SetPinAsInput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/**
 * @brief  Sets pin(s) as output
 * @note   Pins HAVE to be initialized first using @ref GPIO_Init() or @ref GPIO_InitAlternate() function
 * @note   This is just an option for fast output mode 
 * @param  GPIOx: GPIOx PORT where you want to set pin as output
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to set them as output
 * @retval None
 */
void GPIO_SetPinAsOutput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/**
 * @brief  Sets pin(s) as analog
 * @note   Pins HAVE to be initialized first using @ref GPIO_Init() or @ref GPIO_InitAlternate() function
 * @note   This is just an option for fast analog mode 
 * @param  GPIOx: GPIOx PORT where you want to set pin as analog
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to set them as analog
 * @retval None
 */
void GPIO_SetPinAsAnalog(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/** 
 * @brief  Sets pin(s) as alternate function
 * @note   For proper alternate function, you should first init pin using @ref GPIO_InitAlternate() function.
 *            This functions is only used for changing GPIO mode
 * @param  GPIOx: GPIOx PORT where you want to set pin as alternate
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to set them as alternate
 * @retval None
 */
void GPIO_SetPinAsAlternate(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/**
 * @brief  Sets pull resistor settings to GPIO pin(s)
 * @note   Pins HAVE to be initialized first using @ref GPIO_Init() or @ref GPIO_InitAlternate() function
 * @param  *GPIOx: GPIOx PORT where you want to select pull resistor
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to set them as output
 * @param  GPIO_PuPd: Pull resistor option. This parameter can be a value of @ref GPIOPuPd_TypeDef enumeration
 * @retval None
 */
void GPIO_SetPullResistor(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOPuPd_TypeDef GPIO_PuPd);

/**
 * @brief  Sets pin(s) low
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to set pin low
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to set them low
 * @retval None
 */
#define GPIO_SetPinLow(GPIOx, GPIO_Pin)			((GPIOx)->BSRRH = (GPIO_Pin))

/**
 * @brief  Sets pin(s) high
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to set pin high
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to set them high
 * @retval None
 */
#define GPIO_SetPinHigh(GPIOx, GPIO_Pin) 		((GPIOx)->BSRRL = (GPIO_Pin))

/**
 * @brief  Sets pin(s) value
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to set pin value
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to set them value
 * @param  val: If parameter is 0 then pin will be low, otherwise high
 * @retval None
 */
#define GPIO_SetPinValue(GPIOx, GPIO_Pin, val)	((val) ? GPIO_SetPinHigh(GPIOx, GPIO_Pin) : GPIO_SetPinLow(GPIOx, GPIO_Pin))

/**
 * @brief  Toggles pin(s)
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to toggle pin value
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to toggle them all at a time
 * @retval None
 */
#define GPIO_TogglePinValue(GPIOx, GPIO_Pin)		((GPIOx)->ODR ^= (GPIO_Pin))

/**
 * @brief  Sets value to entire GPIO PORT
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to set value
 * @param  value: Value for GPIO OUTPUT data
 * @retval None
 */
#define GPIO_SetPortValue(GPIOx, value)			((GPIOx)->ODR = (value))

/**
 * @brief  Gets input data bit
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to read input bit value
 * @param  GPIO_Pin: GPIO pin where you want to read value
 * @retval 1 in case pin is high, or 0 if low
 */
#define GPIO_GetInputPinValue(GPIOx, GPIO_Pin)	(((GPIOx)->IDR & (GPIO_Pin)) == 0 ? 0 : 1)

/**
 * @brief  Gets output data bit
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to read output bit value
 * @param  GPIO_Pin: GPIO pin where you want to read value
 * @retval 1 in case pin is high, or 0 if low
 */
#define GPIO_GetOutputPinValue(GPIOx, GPIO_Pin)	(((GPIOx)->ODR & (GPIO_Pin)) == 0 ? 0 : 1)

/**
 * @brief  Gets input value from entire GPIO PORT
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to read input data value
 * @retval Entire PORT INPUT register
 */
#define GPIO_GetPortInputValue(GPIOx)			((GPIOx)->IDR)

/**
 * @brief  Gets output value from entire GPIO PORT
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to read output data value
 * @retval Entire PORT OUTPUT register
 */
#define GPIO_GetPortOutputValue(GPIOx)			((GPIOx)->ODR)

/**
 * @brief  Gets port source from desired GPIOx PORT
 * @note   Meant for private use, unless you know what are you doing
 * @param  GPIOx: GPIO PORT for calculating port source
 * @retval Calculated port source for GPIO
 */
uint16_t GPIO_GetPortSource(GPIO_TypeDef* GPIOx);

/**
 * @brief  Gets pin source from desired GPIO pin
 * @note   Meant for private use, unless you know what are you doing
 * @param  GPIO_Pin: GPIO pin for calculating port source
 * @retval Calculated pin source for GPIO pin
 */
uint16_t GPIO_GetPinSource(uint16_t GPIO_Pin);

/**
 * @brief  Locks GPIOx register for future changes
 * @note   You are not able to config GPIO registers until new MCU reset occurs
 * @param  *GPIOx: GPIOx PORT where you want to lock config registers
 * @param  GPIO_Pin: GPIO pin(s) where you want to lock config registers
 * @retval None
 */
void GPIO_Lock(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/** 
 * @brief  Gets bit separated pins which were used at least once in library and were not deinitialized
 * @param  *GPIOx: Pointer to GPIOx peripheral where to check used GPIO pins
 * @retval Bit values for used pins
 */
uint16_t GPIO_GetUsedPins(GPIO_TypeDef* GPIOx);

/** 
 * @brief  Gets bit separated pins which were not used at in library or were deinitialized
 * @param  *GPIOx: Pointer to GPIOx peripheral where to check used GPIO pins
 * @retval Bit values for free pins
 */
uint16_t GPIO_GetFreePins(GPIO_TypeDef* GPIOx);

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4__H */

