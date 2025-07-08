/**
 * @file devebox_h743.ino
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief BluePill (Flash:128KB)のinoファイル
 * @version 0.1
 * @date 2025-7-8
 * 
 * @copyright Copyright (c) 2024,2025 Chimipupu(https://github.com/Chimipupu)
 * 
 */

#include "mcu_board.hpp"
#include "app_freertos.hpp"

extern void btn_k1_ISR(void);
extern void btn_k2_ISR(void);

void setup(void)
{
    // GPIO 初期化
    pinMode(OB_LED_D2_PIN, OUTPUT);
    pinMode(OB_BTN_K1_PIN, INPUT_PULLUP);
    pinMode(OB_BTN_K2_PIN, INPUT_PULLUP);
    attachInterrupt(OB_BTN_K1_PIN, btn_k1_ISR, CHANGE);
    attachInterrupt(OB_BTN_K2_PIN, btn_k2_ISR, CHANGE);

    // Serial(USB-CDC) 初期化
    Serial.begin(115200);

    // FreeRTOS 初期化
    app_freertos_init();
}

void loop(void)
{
    // NOP
}