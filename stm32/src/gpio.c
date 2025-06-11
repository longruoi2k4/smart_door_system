#include "gpio.h"

void GPIO_EnableClock(GPIO_TypeDef *port) {
    if (port == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    if (port == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    if (port == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}

void GPIO_Config(GPIO_TypeDef *port, uint8_t pin, GPIOMode mode, GPIOPull pull) {
    port->MODER &= ~(3 << (2 * pin));
    port->MODER |= (mode << (2 * pin));

    port->PUPDR &= ~(3 << (2 * pin));
    port->PUPDR |= (pull << (2 * pin));
}

void GPIO_Write(GPIO_TypeDef *port, uint8_t pin, uint8_t value) {
    if (value)
        port->ODR |= (1 << pin);
    else
        port->ODR &= ~(1 << pin);
}

uint8_t GPIO_Read(GPIO_TypeDef *port, uint8_t pin) {
    return (port->IDR & (1 << pin)) ? 1 : 0;
}