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
static uint8_t s_btn_k1_flg = 0;
static uint8_t s_btn_k2_flg = 0;

/**
 * @brief ボタンK1の割り込みハンドラ
 * 
 */
void btn_k1_ISR(void)
{
    s_btn_k1_flg = 1;
}

/**
 * @brief ボタンK2の割り込みハンドラ
 * 
 */
void btn_k2_ISR(void)
{
    s_btn_k2_flg = 1;
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
        if (s_btn_k1_flg != 0) {
            Serial.printf("vTaskButton ... Btn K1 = %d\n", s_btn_k1_flg);
            s_btn_k1_flg = 0;
        } else if (s_btn_k2_flg != 0) {
            Serial.printf("vTaskButton ... Btn K2 = %d\n", s_btn_k2_flg);
            s_btn_k2_flg = 0;
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
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
        if ((s_btn_k1_flg != 0) || (s_btn_k2_flg != 0)) {
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