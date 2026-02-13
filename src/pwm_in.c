#include "stm32f4xx.h"

volatile uint32_t pwm_value = 1500;

void PWM_IN_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    GPIOA->MODER |= (2 << (0*2));
    GPIOA->AFR[0] |= (1 << (0*4));

    TIM2->PSC = 84 - 1;
    TIM2->CCMR1 |= 1;
    TIM2->CCER |= TIM_CCER_CC1E;
    TIM2->DIER |= TIM_DIER_CC1IE;

    NVIC_EnableIRQ(TIM2_IRQn);
    TIM2->CR1 |= TIM_CR1_CEN;
}

void TIM2_IRQHandler(void)
{
    if (TIM2->SR & TIM_SR_CC1IF)
    {
        pwm_value = TIM2->CCR1;
        TIM2->SR &= ~TIM_SR_CC1IF;
    }
}

uint16_t PWM_IN_Get(uint8_t ch)
{
    return pwm_value;
}
