#ifndef MPU6500_H
#define MPU6500_H

#include <stdint.h>

void MPU6500_Init(void);
void MPU6500_Read(void);

extern float gyro_x;
extern float gyro_y;
extern float gyro_z;

#endif
