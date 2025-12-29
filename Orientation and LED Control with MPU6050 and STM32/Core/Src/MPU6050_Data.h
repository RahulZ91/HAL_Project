/*
 * MPU6050_Data.h
 *
 *  Created on: Dec 28, 2025
 *      Author: hp
 */
#include "main.h"
#ifndef SRC_MPU6050_DATA_H_
#define SRC_MPU6050_DATA_H_
extern I2C_HandleTypeDef hi2c1;

typedef enum
{
	MPU6050_OK,
	MPU6050_ERR
}mpu6050_status_t;

mpu6050_status_t mpu6050_Init(I2C_HandleTypeDef *i2c,uint8_t i2c_addr);

#endif /* SRC_MPU6050_DATA_H_ */


