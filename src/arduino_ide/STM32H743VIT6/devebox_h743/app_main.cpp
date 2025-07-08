/**
 * @file app_main.cpp
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief アプリ
 * @version 0.1
 * @date 2025-7-8
 * 
 * @copyright Copyright (c) 2024,2025 Chimipupu(https://github.com/Chimipupu)
 * 
 */

#include "app_main.hpp"
#include "mcu_board.hpp"
#include <Arduino.h>

static bool debounce_button(button_state_t *p_btn_state);

static uint8_t s_led_val = 1;
static button_state_t s_btn_k1 = {0, 0, 0, OB_BTN_K1_PIN};
static button_state_t s_btn_k2 = {0, 0, 0, OB_BTN_K2_PIN};

/**
 * @brief ボタンK1の割り込みハンドラ
 * 
 */
void btn_k1_ISR(void)
{
    uint32_t current_time = xTaskGetTickCountFromISR() * portTICK_PERIOD_MS;

    // 前回の割り込みから十分な時間が経過した場合のみフラグを立てる
    if (current_time - s_btn_k1.last_interrupt_time > DEBOUNCE_TIME_MS) {
        s_btn_k1.interrupt_flag = 1;
        s_btn_k1.last_interrupt_time = current_time;
    }
}

/**
 * @brief ボタンK2の割り込みハンドラ
 * 
 */
void btn_k2_ISR(void)
{
    uint32_t current_time = xTaskGetTickCountFromISR() * portTICK_PERIOD_MS;

    // 前回の割り込みから十分な時間が経過した場合のみフラグを立てる
    if (current_time - s_btn_k2.last_interrupt_time > DEBOUNCE_TIME_MS) {
        s_btn_k2.interrupt_flag = 1;
        s_btn_k2.last_interrupt_time = current_time;
    }
}

/**
 * @brief ボタンのチャタリング対策のデバウンス
 * 
 * @param p_btn_state ボタン状態の構造体ポインタ
 * @return true ボタンが押された（立ち上がりエッジ）
 * @return false ボタンが押されていない、または既に処理済み
 */
static bool debounce_button(button_state_t *p_btn_state)
{
    uint8_t current_pin_state = 0;

    if (p_btn_state->interrupt_flag == 0) {
        return false;
    }

    // 割り込みフラグをクリア
    p_btn_state->interrupt_flag = 0;

    // 現在のピン状態を読み取り
    current_pin_state = digitalRead(p_btn_state->pin_number);

    // ボタンが押された状態（LOW）で、前回が押されていない場合
    if (current_pin_state == LOW && p_btn_state->button_pressed == 0) {
        p_btn_state->button_pressed = 1;
        return true;  // 立ち上がりエッジを検出
    // ボタンが離された状態（HIGH）の場合
    } else if (current_pin_state == HIGH && p_btn_state->button_pressed == 1) {
        p_btn_state->button_pressed = 0;
    }

    return false;
}

/**
 * @brief ボタンアプリ初期化
 * 
 */
void app_btn_init(void)
{
    pinMode(OB_LED_D2_PIN, OUTPUT);
    pinMode(OB_BTN_K1_PIN, INPUT_PULLUP);
    pinMode(OB_BTN_K2_PIN, INPUT_PULLUP);
}

/**
 * @brief ボタンアプリ
 * 
 */
void app_btn_main(void)
{
    // K1ボタンのデバウンス処理
    if (debounce_button(&s_btn_k1)) {
        Serial.printf("vTaskButton ... Btn K1 pressed\n");
    }

    // K2ボタンのデバウンス処理
    if (debounce_button(&s_btn_k2)) {
        Serial.printf("vTaskButton ... Btn K2 pressed\n");
    }
}

/**
 * @brief アプリメイン初期化
 * 
 */
void app_main_init(void)
{
    // (TODO)
}

/**
 * @brief アプリメイン
 * 
 */
void app_main(void)
{
    // ボタンが押されている状態をチェック
    if (s_btn_k1.button_pressed || s_btn_k2.button_pressed) {
        Serial.printf("vTaskMain\n");
        Serial.printf("Serial & LED Test(val = %d)\n", s_led_val);
        digitalWrite(OB_LED_D2_PIN, s_led_val);
        s_led_val = !s_led_val;
    }
}