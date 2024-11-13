/**
 * @file bluepill_f128kb.ino
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief BluePill (Flash:128KB)のinoファイル
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#include "mcu_board.hpp"
#include "app_freertos.hpp"

void setup(void)
{
    // GPIO 初期化
    pinMode(OB_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    attachInterrupt(BUTTON_PIN, buttonISR, CHANGE);

    // Serial(USB-CDC) 初期化
    Serial.begin(115200);

    // FreeRTOS 初期化
    app_freertos_init();
}

void loop(void)
{
    // NOP
}