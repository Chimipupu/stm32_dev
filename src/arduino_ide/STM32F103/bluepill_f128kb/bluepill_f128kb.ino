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

#include <stdint.h>
#include <string.h>

// #define __BLUE_PILL__          // BluePill
// #define __BLACK_PILL__         // BlackPill

#if defined(__BLUE_PILL__)
    #define OB_LED_PIN        PC13 // LEDのGPIOピン(PC13) アクティブLow
#elif defined(__BLACK_PILL__)
    #define OB_LED_PIN        PB12 // LEDのGPIOピン(PB12) アクティブLow
#else
    #define OB_LED_PIN        PA1  // LEDのGPIOピン(PA1) アクティブLow
#endif /* __BLUE_PILL__ */

#define BUTTON_PIN        PA8  // ボタンピン(PA8) アクティブLow

static uint8_t s_led_val = 1;

void buttonISR(void)
{
    s_led_val = !s_led_val;
}

void setup(void)
{
    // GPIO 初期化
    pinMode(OB_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    attachInterrupt(BUTTON_PIN, buttonISR, CHANGE);

    // Serial(USB-CDC) 初期化
    Serial.begin(115200);
}

void loop(void)
{
    Serial.printf("Serial & LED Test(val = %d)\n", s_led_val);
    digitalWrite(OB_LED_PIN, s_led_val);
    delay(500);
}