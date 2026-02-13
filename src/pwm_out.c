#include "stm32f4xx.h"

void PWM_OUT_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

    GPIOB->MODER |= (2 << (4*2)); // PB4 AF
    GPIOB->AFR[0] |= (2 << (4*4));

    TIM3->PSC = 84 - 1;      // 1MHz
    TIM3->ARR = 20000 - 1;   // 20ms (50Hz)

    TIM3->CCR1 = 1500;

    TIM3->CCMR1 |= (6 << 4);
    TIM3->CCER |= TIM_CCER_CC1E;

    TIM3->CR1 |= TIM_CR1_CEN;
}

void PWM_OUT_Set(uint8_t ch, uint16_t value)
{
    TIM3->CCR1 = value;
}
