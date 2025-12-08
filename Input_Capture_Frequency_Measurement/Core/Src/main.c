#include<string.h>
#include "stm32f4xx_hal.h"
#include "main.h"
#include<stdio.h>

void SystemClockConfig(void);
void GPIO_Init(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void TIMER2_Init(void);


TIM_HandleTypeDef htimer2;

int main(void)
{
	HAL_Init();
	SystemClockConfig(); // Application specification and not in HAL
	GPIO_Init();
	TIMER2_Init();

	// Start the timer
	HAL_TIM_Base_Start_IT(&htimer2);


	while(1);

	return 0;
}

void SystemClockConfig(void)
{
	// function to configure special clock configuration
}

void TIMER2_Init(void)
{
	TIM_IC_InitTypeDef tim2IC_Config; // for the CCMR

	htimer2.Instance=TIM2;
	htimer2.Init.CounterMode=TIM_COUNTERMODE_UP;
	htimer2.Init.Period = 0xFFFFFFFF; // since timer2 is 32 bit - from the reference manual
	htimer2.Init.Prescaler=1; // division by 2 i.e 25MHz
	if(HAL_TIM_IC_Init(&htimer2) != HAL_OK)
	{
		while(1);
	}


	tim2IC_Config.ICFilter = 0x0; // digital filter configured for a clean input signal
	tim2IC_Config.ICPolarity=TIM_ICPOLARITY_RISING; // we want the event at the rising edge
	tim2IC_Config.ICPrescaler=TIM_ICPSC_DIV1; // divides by 1 so not slowed down
	tim2IC_Config.ICSelection=TIM_ICSELECTION_DIRECTTI;

	if(HAL_TIM_IC_ConfigChannel(&htimer2, &tim2IC_Config, TIM_CHANNEL_1) != HAL_OK)
	{
		while(1);
	}
}

void GPIO_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_set;
	GPIO_set.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_set.Pin=GPIO_PIN_5;
	GPIO_set.Speed=GPIO_SPEED_FREQ_LOW;
	GPIO_set.Pull=GPIO_NOPULL;

	HAL_GPIO_Init(GPIOA, &GPIO_set); // basically set the pin 5 for port A
}
