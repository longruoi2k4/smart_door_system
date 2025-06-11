#include "uart.h"
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

extern volatile bool uart_triggered;

static void uartCommandTask(void *param) {
    while (true) {
        if (Serial.available()) {
            String cmd = Serial.readStringUntil('\n');
            cmd.trim();
            cmd.toUpperCase();
            if (cmd == "CAPTURE") {
                uart_triggered = true;
                Serial.println("UART command received: CAPTURE");
            }
        }
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void startUartCommandTask() {
    xTaskCreatePinnedToCore(uartCommandTask, "uartCommandTask", 4096, NULL, 1, NULL, 1);
}