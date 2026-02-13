#include "stm32f4xx.h"
#include <stdint.h>

#include "spi.h"
#include "mpu6500.h"
#include "delay.h"

void GPIO_Init(void);

int main(void)
{
    SystemInit();

    GPIO_Init();        // Chip select pin
    SPI1_Init();        // SPI1
    MPU6500_Init();     // Init MPU

    // Đọc WHO_AM_I để kiểm tra
    uint8_t id = MPU6500_ReadReg(0x75);

    // Nếu đúng MPU6500 thì id = 0x70
    // Bạn có thể đặt breakpoint xem biến id

    while (1)
    {
        MPU6500_ReadGyro();

        // Debug xem:
        // gyro_x
        // gyro_y
        // gyro_z

        delay(50000);
    }
}
void GPIO_Init(void)
{
    // Enable GPIOA clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // PA4 output (CS)
    GPIOA->MODER &= ~(3 << (4 * 2));
    GPIOA->MODER |=  (1 << (4 * 2));   // Output mode

    GPIOA->OTYPER &= ~(1 << 4);        // Push pull
    GPIOA->OSPEEDR |= (3 << (4 * 2));  // High speed
    GPIOA->PUPDR &= ~(3 << (4 * 2));   // No pull

    // Set CS high
    GPIOA->BSRR = (1 << 4);
}
