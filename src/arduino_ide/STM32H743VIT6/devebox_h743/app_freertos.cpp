/**
 * @file app_freertos.cpp
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief FreeRTOS アプリ
 * @version 0.1
 * @date 2025-7-8
 * 
 * @copyright Copyright (c) 2024,2025 Chimipupu(https://github.com/Chimipupu)
 * 
 */

#include "mcu_board.hpp"
#include "app_freertos.hpp"

static xTaskHandle s_xTaskButton;
static xTaskHandle s_xTaskMain;
static uint8_t s_led_val = 1;

// デバウンス時間（ミリ秒）
#define DEBOUNCE_TIME_MS 50

// デバウンス用の構造体
typedef struct {
    uint8_t interrupt_flag;       // 割り込みフラグ
    uint8_t button_pressed;       // ボタン押下状態
    uint32_t last_interrupt_time; // 最後の割り込み時刻
    uint8_t pin_number;           // ピン番号
} button_state_t;

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
bool debounce_button(button_state_t *p_btn_state)
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
 * @brief FreeRTOS ボタンタスク
 * 
 * @param p_parameter パラメータのポインタ
 */
void vTaskButton(void *p_parameter)
{
    while (1)
    {
        // K1ボタンのデバウンス処理
        if (debounce_button(&s_btn_k1)) {
            Serial.printf("vTaskButton ... Btn K1 pressed\n");
        }

        // K2ボタンのデバウンス処理
        if (debounce_button(&s_btn_k2)) {
            Serial.printf("vTaskButton ... Btn K2 pressed\n");
        }

        vTaskDelay(10 / portTICK_PERIOD_MS);  // より細かいポーリング
    }
}

/**
 * @brief FreeRTOS メインタスク
 * 
 * @param p_parameter パラメータのポインタ
 */
void vTaskMain(void *p_parameter)
{
    while (1)
    {
        // ボタンが押されている状態をチェック
        if (s_btn_k1.button_pressed || s_btn_k2.button_pressed) {
            Serial.printf("vTaskMain\n");
            Serial.printf("Serial & LED Test(val = %d)\n", s_led_val);
            digitalWrite(OB_LED_D2_PIN, s_led_val);
            s_led_val = !s_led_val;
        }
        vTaskDelay(20 / portTICK_PERIOD_MS);
    }
}

void app_freertos_init()
{
    // FreeRTOSタスク生成
    xTaskCreate(vTaskButton,       // コールバック関数ポインタ
                "vTaskButton",     // タスク名
                256,               // スタック
                nullptr,           // パラメータ
                3,                 // 優先度(0～7、7が最優先)
                &s_xTaskButton     // タスクハンドル
                );

    xTaskCreate(vTaskMain,         // コールバック関数ポインタ
                "vTaskMain",       // タスク名
                4096,              // スタック
                nullptr,           // パラメータ
                7,                 // 優先度(0～7、7が最優先)
                &s_xTaskMain       // タスクハンドル
                );

    // FreeRTOS スケジュール開始
    vTaskStartScheduler();
}