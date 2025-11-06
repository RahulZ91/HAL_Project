/**
  * @brief  Initialize the MSP.
  * @retval None
  */
#include "stm32f4xx.h"
#include "main.h"
void HAL_MspInit(void)
{
  // Customizing the function for my project
  // 1. task 1: Setup the processor priority grouping- NVIC_PRIORITYGROUP_0 then no interrupts can be directly configured
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  // 2. task 2 : Enable the required system exceptions of the ARM Cortex M4 system exceptions
	// #include "stm32f4xx.h" includes the SCB definition - so make sure to include it
	SCB->SHCSR &= ~(0x7 << 16); // first clear the bits from location 17,18 and 19 - activated the usage fault, memory fault and bus fault exception
	SCB->SHCSR |= 0x7<<16; // set the bits 17,18 and 19

  // 3. task 3 : Setup the priority for the system exceptions
  HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
  HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
  HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);

}

/**
  * @brief  UART MSP Init.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	// Low level init for the USART 2 peripheral

	// task 1 : Enable the clock for the USART2
	__HAL_RCC_USART2_CLK_ENABLE(); // HAL macro to enable clock

	// task 2 : Pin muxing configuration
	// we are using PA2 as TX and PA3 as RX in the mode AF7
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef USART2_TXRX={0};
	USART2_TXRX.Pin=GPIO_PIN_2;
	USART2_TXRX.Mode=GPIO_MODE_AF_PP;
	USART2_TXRX.Pull=GPIO_PULLUP;  // maintains data at high line when no data is TX
	USART2_TXRX.Speed=GPIO_SPEED_FREQ_LOW; // switching frequency of the signal
	USART2_TXRX.Alternate=GPIO_AF7_USART2; // found in stm32f4xx_hal_gpio_ex.h under STMF446xx
	HAL_GPIO_Init(GPIOA, &USART2_TXRX);

	USART2_TXRX.Pin=GPIO_PIN_3;
	USART2_TXRX.Mode=GPIO_MODE_AF_PP;
	USART2_TXRX.Pull=GPIO_PULLUP;  // maintains data at high line when no data is TX
	USART2_TXRX.Speed=GPIO_SPEED_FREQ_LOW; // switching frequency of the signal
	USART2_TXRX.Alternate=GPIO_AF7_USART2; // found in stm32f4xx_hal_gpio_ex.h under STMF446xx
	HAL_GPIO_Init(GPIOA, &USART2_TXRX);

	// task 3 : Enable the USART2 IRQ in NVIC
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);

	// task 4 : Set the priority

}
