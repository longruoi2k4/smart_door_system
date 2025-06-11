#ifndef UART_DRIVER_H
#define UART_DRIVER_H

void UART2_Init(void);
void UART2_SendChar(char c);
void UART2_SendString(const char *str);

#endif