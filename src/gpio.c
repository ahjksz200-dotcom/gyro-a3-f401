#include "stm32f4xx.h"
#include "gpio.h"

void GPIO_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER &= ~(3 << (4 * 2));
    GPIOA->MODER |=  (1 << (4 * 2));

    GPIOA->OTYPER &= ~(1 << 4);
    GPIOA->OSPEEDR |= (3 << (4 * 2));
    GPIOA->PUPDR &= ~(3 << (4 * 2));

    GPIOA->BSRR = (1 << 4);
}
