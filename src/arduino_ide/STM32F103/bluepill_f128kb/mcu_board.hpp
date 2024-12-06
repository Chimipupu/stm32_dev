/**
 * @file mcu_board.hpp
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief 基板ヘッダー
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#ifndef MCU_BOARD_HPP
#define MCU_BOARD_HPP

#define __BLUE_PILL__          // BluePill
// #define __BLACK_PILL__         // BlackPill

#if defined(__BLUE_PILL__)
    #define OB_LED_PIN        PC13 // LEDのGPIOピン(PC13) アクティブLow
#elif defined(__BLACK_PILL__)
    #define OB_LED_PIN        PB12 // LEDのGPIOピン(PB12) アクティブLow
#else
    #define OB_LED_PIN        PA1  // LEDのGPIOピン(PA1) アクティブLow
#endif /* __BLUE_PILL__ */

#define BUTTON_PIN            PA8  // ボタンピン(PA8) アクティブLow

#endif /* MCU_BOARD_HPP */