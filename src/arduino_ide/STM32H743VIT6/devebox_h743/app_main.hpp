/**
 * @file app_main.hpp
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief アプリヘッダー
 * @version 0.1
 * @date 2025-7-8
 * 
 * @copyright Copyright (c) 2024,2025 Chimipupu(https://github.com/Chimipupu)
 * 
 */

#ifndef APP_MAIN_HPP
#define APP_MAIN_HPP

#include <stdint.h>
#include <string.h>
#include <Arduino.h>
#include <STM32FreeRTOS.h>

// デバウンス時間（ミリ秒）
#define DEBOUNCE_TIME_MS 50

// デバウンス用の構造体
typedef struct {
    uint8_t interrupt_flag;       // 割り込みフラグ
    uint8_t button_pressed;       // ボタン押下状態
    uint32_t last_interrupt_time; // 最後の割り込み時刻
    uint8_t pin_number;           // ピン番号
} button_state_t;

void app_btn_init(void);
void app_btn_main(void);
void app_main(void);
void app_main_init(void);

#endif /* APP_MAIN_HPP */