#ifndef MPU6500_H
#define MPU6500_H

#include "stm32f4xx.h"
#include <stdint.h>

void MPU6500_Init(void);
uint8_t MPU6500_ReadReg(uint8_t reg);
void MPU6500_WriteReg(uint8_t reg, uint8_t data);
void MPU6500_ReadGyro(void);

extern float gyro_x;
extern float gyro_y;
extern float gyro_z;

#endif
