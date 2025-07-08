# DevEBox 開発環境(Arduino IDE)

Arduino IEDでのDevEBox(STM32H743VIT6)の開発環境

## 📍IDE

- 📍[Arduino IDE v2.36🔗](https://github.com/arduino/arduino-ide/releases/tag/2.3.6)
  - 📍[STM32duino v2.10.1🔗](https://github.com/stm32duino/Arduino_Core_STM32/releases/tag/2.10.1)

## 📍OS (RTOS)

- 📍[FreeRTOS🔗](https://www.freertos.org/)
  - ➡️ [STM32duino FreeRTOS v10.3.2🔗](https://github.com/stm32duino/STM32FreeRTOS)

## 📍基板

- 📍[DevEBox STM32H743🔗](https://github.com/mcauser/MCUDEV_DEVEBOX_H7XX_M)
  - マイコン
    - 📍[STM32H743VIT6🔗](https://www.st.com/ja/microcontrollers-microprocessors/stm32h743-753.html)
    - CPU
      - 📍[ARM Cortex-M7🔗](https://www.arm.com/ja/products/silicon-ip-cpu/cortex-m/cortex-m7)
- 📍[DevEBox STM32H743🔗](https://github.com/mcauser/MCUDEV_DEVEBOX_H7XX_M)
  - マイコン
    - 📍[STM32H743VIT6🔗](https://www.st.com/ja/microcontrollers-microprocessors/stm32h743-753.html)
      - CPU: [ARM Cortex-M7🔗](https://www.arm.com/ja/products/silicon-ip-cpu/cortex-m/cortex-m7)
      - クロック: 最大480MHz
      - フラッシュメモリ: 2048KB
      - RAM: 1060KB
      - GPIO: 82本
      - 16bitタイマ: 12個
      - 32bitタイマ: 2個
      - モータ制御用タイマ: 2個
      - 低電力タイマ: 5個
      - 高分解能タイマ: 1個
      - 16bit ADC: 3個（20チャネル）
      - 12bit DAC: 2チャネル
      - コンパレータ: 2個
      - アンプ: 2個
      - SPI: 6個
      - QUADSPI: 1個
      - I2S: 3個
      - I2C: 4個
      - U(S)ART: 8個（4+4）
      - LP UART: 1個
      - CAN: 2個
      - SDIO: 2個
      - FMC: 1個
      - USB OTG FS: 1個
      - USB OTG HS: 1個
      - イーサネット: 1個
      - MDIOS: 1個
      - TFT LCD: 1個
      - SAI: 4個
      - SPDIFRX: 4個
      - DFSDM: 1個
      - DCMI: 1個
      - SWPMI: 1個
      - TRNG: 1個

## ビルド構成

⚠️USB CDCは下記でしかWindowsが認識しない⚠️

- **USB CDCでgeneric Serial**
- **USBのスピードはLow**

![arduinoide devenv img](/doc/STM32H743VIT6/img/devebox_h743_arduino_ide_dev_env.png)
