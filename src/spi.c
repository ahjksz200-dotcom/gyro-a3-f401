#include "stm32f4xx.h"
#include "spi.h"

void SPI1_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

    // PA5 = SCK
    // PA6 = MISO
    // PA7 = MOSI
    GPIOA->MODER |= (2<<(5*2)) | (2<<(6*2)) | (2<<(7*2));
    GPIOA->AFR[0] |= (5<<(5*4)) | (5<<(6*4)) | (5<<(7*4));

    SPI1->CR1 = SPI_CR1_MSTR | SPI_CR1_SSI | SPI_CR1_SSM;
    SPI1->CR1 |= SPI_CR1_BR_0;   // chia clock cho an toàn
    SPI1->CR1 |= SPI_CR1_SPE;
}

uint8_t SPI1_Transfer(uint8_t data)
{
    while (!(SPI1->SR & SPI_SR_TXE));
    *((__IO uint8_t*)&SPI1->DR) = data;

    while (!(SPI1->SR & SPI_SR_RXNE));
    return *((__IO uint8_t*)&SPI1->DR);
}
