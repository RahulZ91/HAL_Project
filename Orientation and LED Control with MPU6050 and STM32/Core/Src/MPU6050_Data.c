/*
 * MPU6050_Data.c
 *
 *  Created on: Dec 28, 2025
 *      Author: hp
 */

#include "MPU6050_Data.h"
extern I2C_HandleTypeDef hi2c1;

void mpu6050_Init(I2C_HandleTypeDef *i2c,uint8_t i2c_addr)
{
	// Read one byte from the sensor
	uint8_t reg_addr=117;
	uint8_t response_buffer=0
	if(HAL_I2C_Mem_Read(&i2c, i2c_addr, reg_addr, 1, &response_buffer, 1, 500) ==HAL_OK)
	{

	}

}
