/**
 * @file mcu_board.hpp
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief 基板ヘッダー
 * @version 0.1
 * @date 2024-12-7
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#ifndef MCU_BOARD_HPP
#define MCU_BOARD_HPP

#define __DEV_E_BOX_H743__
#ifdef __DEV_E_BOX_H743__
    // 基板
    #define OB_LED_D2_PIN     PA1 // 基板実装LED  「D2」ピン アクティブLow
    #define OB_BTN_K1_PIN     PE3 // 基板実装ボタン「K1」ピン アクティブLow
    #define OB_BTN_K2_PIN     PC5 // 基板実装ボタン「K2」ピン アクティブLow

    // USB
    #define USB_DM_PIN       PA11 // USB DM(D-)ピン
    #define USB_DP_PIN       PA12 // USB DP(D+)ピン

    // UART
    #define UART_RXD1_PIN    PA10 // UART RXD1
    #define UART_TXD1_PIN     PA9 // UART TXD1

    // SDIO
    #define SDIO_CMD_PIN      PD2 // SDIO CMD   <-> TF Slot Vss
    #define SDIO_SCK_PIN     PC12 // SDIO SCK   <-> TF Slot CLK
    #define SDIO_D0_PIN       PC8 // SDIO DATA0 <-> TF Slot DAT0
    #define SDIO_D1_PIN       PC9 // SDIO DATA1 <-> TF Slot DAT1
    #define SDIO_D2_PIN      PC10 // SDIO DATA2 <-> TF Slot DAT3
    #define SDIO_D3_PIN      PC11 // SDIO DATA3 <-> TF Slot CMD

    // SPI
    #define SPI_CS_PIN        PB12 // SPI CS
    #define SPI_CLK_PIN       PB13 // SPI CLK
    #define SPI_MISO_PIN      PB14 // SPI MISO
    #define SPI_MOSI_PIN      PB15 // SPI MOSI

    // QSPI
    #define QSPI_CS_PIN        PB6 // QSPI CS
    #define QSPI_CLK_PIN       PB2 // QSPI CLK
    #define QSPI_IO0_PIN      PD11 // QSPI IO0
    #define QSPI_IO1_PIN      PD12 // QSPI IO1
    #define QSPI_IO2_PIN       PE2 // QSPI IO2
    #define QSPI_IO3_PIN      PD13 // QSPI IO3
#endif /* __DEV_E_BOX_H743__ */

#endif /* MCU_BOARD_HPP */