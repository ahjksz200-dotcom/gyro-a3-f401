#include "stm32f4xx.h"
#include <stdint.h>

#include "gpio.h"
#include "spi.h"
#include "mpu6500.h"
#include "delay.h"

int main(void)
{
    SystemInit();

    // Enable clock GPIOC cho LED PC13
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // PC13 output
    GPIOC->MODER &= ~(3 << (13 * 2));
    GPIOC->MODER |=  (1 << (13 * 2));

    GPIOC->OTYPER &= ~(1 << 13);
    GPIOC->OSPEEDR |= (3 << (13 * 2));
    GPIOC->PUPDR &= ~(3 << (13 * 2));

    // LED OFF ban đầu (PC13 active LOW)
    GPIOC->ODR |= (1 << 13);

    GPIO_Init();        // CS pin (PA4)
    SPI1_Init();        // SPI1
    MPU6500_Init();     // Init MPU

    while (1)
    {
        uint8_t id = MPU6500_ReadReg(0x75);

        if (id == 0x70)
        {
            // LED ON (SPI OK)
            GPIOC->ODR &= ~(1 << 13);
        }
        else
        {
            // LED OFF (SPI lỗi)
            GPIOC->ODR |= (1 << 13);
        }

        delay(2000000);
    }
}
