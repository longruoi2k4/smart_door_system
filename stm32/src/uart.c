#include "uart.h"
#include "stm32f4xx.h"

void UART2_Init(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    GPIOA->MODER &= ~((3 << (2 * 2)) | (3 << (2 * 3)));
    GPIOA->MODER |= (2 << (2 * 2)) | (2 << (2 * 3));
    GPIOA->AFR[0] |= (7 << (4 * 2)) | (7 << (4 * 3));

    USART2->BRR = 16000000 / 115200;
    USART2->CR1 |= USART_CR1_TE | USART_CR1_UE;
}

void UART2_SendChar(char c) {
    while (!(USART2->SR & USART_SR_TXE));
    USART2->DR = c;
}

void UART2_SendString(const char *str) {
    while (*str) {
        UART2_SendChar(*str++);
    }
}