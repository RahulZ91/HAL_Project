/**
  * @brief  Initialize the MSP.
  * @retval None
  */
#include "stm32f4xx.h"
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
