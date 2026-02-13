#include "stm32f4xx.h"
#include "gpio.h"

void GPIO_Init(void)
{
    // Enable clock GPIOC
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // PC13 output
    GPIOC->MODER &= ~(3 << (13 * 2));
    GPIOC->MODER |=  (1 << (13 * 2));   // output mode

    GPIOC->OTYPER &= ~(1 << 13);        // push pull
    GPIOC->OSPEEDR |= (3 << (13 * 2));  // high speed
    GPIOC->PUPDR &= ~(3 << (13 * 2));   // no pull
}
