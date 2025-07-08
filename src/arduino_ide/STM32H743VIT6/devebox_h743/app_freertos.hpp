/**
 * @file app_freertos.hpp
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief FreeRTOS アプリヘッダー
 * @version 0.1
 * @date 2025-7-8
 * 
 * @copyright Copyright (c) 2024,2025 Chimipupu(https://github.com/Chimipupu)
 * 
 */

#ifndef APP_FREERTOS_HPP
#define APP_FREERTOS_HPP

#include <stdint.h>
#include <string.h>
#include <Arduino.h>
#include <STM32FreeRTOS.h>

void btn_k1_ISR(void);
void btn_k2_ISR(void);
void app_freertos_init();

#endif /* APP_FREERTOS_HPP */