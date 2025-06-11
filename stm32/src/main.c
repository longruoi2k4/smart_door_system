#include "l298n.h"
#include "irsensor.h"
#include "uart.h"
#include "delay.h"

#include "stm32f4xx.h"


int main(void) {
    Motor_Init(); // Khởi tạo điều khiển motor bằng l298n
    PIR_Init(); // khởi tạo ir sensor
    UART2_Init(); // khởi tạo giao tiếp uart với esp32-cam
    Delay_Init(); // Khởi tạo SysTick cho delay

    while (1) {
        if (PIR_Detected()) {
            UART2_SendString("CAPTURE\n");
            Motor_Open();
            delay_ms(2000);
            Motor_Close();
            UART2_SendString("CLOSED\n");
            delay_ms(2000);
        }
    }
}