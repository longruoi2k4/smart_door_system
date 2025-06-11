#include "l298n.h"
#include "gpio.h"

#define MOTOR_PIN1_PORT GPIOB
#define MOTOR_PIN2_PORT GPIOB
#define MOTOR_PIN1      0
#define MOTOR_PIN2      1

void Motor_Init(void) {
    GPIO_EnableClock(MOTOR_PIN1_PORT);
    GPIO_Config(MOTOR_PIN1_PORT, MOTOR_PIN1, GPIO_OUTPUT, GPIO_NO_PULL);
    GPIO_Config(MOTOR_PIN2_PORT, MOTOR_PIN2, GPIO_OUTPUT, GPIO_NO_PULL);
}

void Motor_Open(void) {
    GPIO_Write(MOTOR_PIN1_PORT, MOTOR_PIN1, 1);
    GPIO_Write(MOTOR_PIN2_PORT, MOTOR_PIN2, 0);
}

void Motor_Close(void) {
    GPIO_Write(MOTOR_PIN1_PORT, MOTOR_PIN1, 0);
    GPIO_Write(MOTOR_PIN2_PORT, MOTOR_PIN2, 1);
}

void Motor_Stop(void) {
    GPIO_Write(MOTOR_PIN1_PORT, MOTOR_PIN1, 0);
    GPIO_Write(MOTOR_PIN2_PORT, MOTOR_PIN2, 0);
}