#include <Arduino.h>
#include <WiFi.h>
#include "esp_camera.h"
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "camera_config.h"
#include "http_server.h"
#include "uart.h"

// Define the global uart_triggered variable
volatile bool uart_triggered = false;

const char* ssid = "Long";
const char* password = "123456789";

void setup() {
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); // Disable brownout detector

    Serial.begin(115200);
    Serial.setDebugOutput(false);
    Serial.println();

    // Initialize camera
    camera_config_t config = get_camera_config();
    esp_err_t err = esp_camera_init(&config);
    if (err != ESP_OK) {
        Serial.printf("Camera init failed with error 0x%x", err);
        return;
    }

    // Connect to WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.println("WiFi connected");

    // Start HTTP server
    startCameraServer();

    // Start UART command task
    startUartCommandTask();
}

void loop() {
    delay(1);
}