#include "irsensor.h"
#include "gpio.h"

#define PIR_PORT GPIOA
#define PIR_PIN  0

void PIR_Init(void) {
    GPIO_EnableClock(PIR_PORT);
    GPIO_Config(PIR_PORT, PIR_PIN, GPIO_INPUT, GPIO_NO_PULL);
}

int PIR_Detected(void) {
    if(GPIO_Read(PIR_PORT, PIR_PIN)) {
        return 0;
    }
    return 1;
}