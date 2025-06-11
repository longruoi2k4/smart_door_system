#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "stm32f4xx.h"

typedef enum {
    GPIO_INPUT,
    GPIO_OUTPUT,
    GPIO_AF,
    GPIO_ANALOG
} GPIOMode;

typedef enum {
    GPIO_NO_PULL,
    GPIO_PULL_UP,
    GPIO_PULL_DOWN
} GPIOPull;

void GPIO_EnableClock(GPIO_TypeDef *port);
void GPIO_Config(GPIO_TypeDef *port, uint8_t pin, GPIOMode mode, GPIOPull pull);
void GPIO_Write(GPIO_TypeDef *port, uint8_t pin, uint8_t value);
uint8_t GPIO_Read(GPIO_TypeDef *port, uint8_t pin);

#endif