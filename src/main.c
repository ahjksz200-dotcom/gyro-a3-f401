#include "stm32f4xx.h"
#include <stdint.h>

#include "gpio.h"
#include "spi.h"
#include "mpu6500.h"
#include "delay.h"

int main(void)
{
    SystemInit();

    GPIO_Init();
    SPI1_Init();
    MPU6500_Init();

    uint8_t id = MPU6500_ReadReg(0x75);

while (1)
{
    GPIOC->ODR ^= (1 << 13);   // toggle PC13
    delay(2000000);
}
