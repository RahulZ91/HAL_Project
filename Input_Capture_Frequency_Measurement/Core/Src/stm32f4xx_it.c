#include "main.h"

extern TIM_HandleTypeDef htimer2;

void SysTick_Handler()
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void TIM2_IRQHandler()
{
	HAL_TIM_IRQHandler(&htimer2);
}
