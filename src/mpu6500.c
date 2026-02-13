#include "mpu6500.h"
#include "spi.h"

#define MPU_CS_LOW()   GPIOA->BSRR = GPIO_BSRR_BR4
#define MPU_CS_HIGH()  GPIOA->BSRR = GPIO_BSRR_BS4

#define WHO_AM_I_REG 0x75
#define PWR_MGMT_1   0x6B
#define GYRO_XOUT_H  0x43

float gyro_x = 0;
float gyro_y = 0;
float gyro_z = 0;

uint8_t MPU6500_ReadReg(uint8_t reg)
{
    uint8_t data;

    MPU_CS_LOW();
    SPI1_Transfer(reg | 0x80);
    data = SPI1_Transfer(0x00);
    MPU_CS_HIGH();

    return data;
}

void MPU6500_WriteReg(uint8_t reg, uint8_t value)
{
    MPU_CS_LOW();
    SPI1_Transfer(reg & 0x7F);
    SPI1_Transfer(value);
    MPU_CS_HIGH();
}

void MPU6500_Init(void)
{
    MPU6500_WriteReg(PWR_MGMT_1, 0x00);
}

void MPU6500_ReadGyro(void)
{
    uint8_t buffer[6];

    MPU_CS_LOW();
    SPI1_Transfer(GYRO_XOUT_H | 0x80);
    for (int i = 0; i < 6; i++)
        buffer[i] = SPI1_Transfer(0x00);
    MPU_CS_HIGH();

    int16_t gx = (buffer[0] << 8) | buffer[1];
    int16_t gy = (buffer[2] << 8) | buffer[3];
    int16_t gz = (buffer[4] << 8) | buffer[5];

    gyro_x = gx / 131.0f;
    gyro_y = gy / 131.0f;
    gyro_z = gz / 131.0f;
}
