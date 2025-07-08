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
#include "app_main.hpp"

static xTaskHandle s_xTaskButton;
static xTaskHandle s_xTaskMain;

/**
 * @brief FreeRTOS ボタンタスク
 * 
 * @param p_parameter パラメータのポインタ
 */
void vTaskButton(void *p_parameter)
{
    app_btn_init();

    while (1)
    {
        app_btn_main();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

/**
 * @brief FreeRTOS メインタスク
 * 
 * @param p_parameter パラメータのポインタ
 */
void vTaskMain(void *p_parameter)
{
    app_main_init();

    while (1)
    {
        app_main();
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