#include "stm32f4xx.h"
#include "gpio.h"

void GPIO_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
}
