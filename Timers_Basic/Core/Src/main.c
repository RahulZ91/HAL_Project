#include<string.h>
#include "stm32f4xx_hal.h"
#include "main.h"
#include<stdio.h>

void SystemClockConfig(void);

int main(void)
{
	HAL_Init();
	SystemClockConfig(); // Application specification and not in HAL


	while(1);

	return 0;
}

void SystemClockConfig(void)
{
	// function to configure special clock configuration
}
