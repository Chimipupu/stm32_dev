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

## ビルド構成

⚠️USB CDCは下記でしかWindowsが認識しない⚠️

- **USB CDCでgeneric Serial**
- **USBのスピードはLow**

![arduinoide devenv img](/doc/STM32H743VIT6/img/devebox_h743_arduino_ide_dev_env.png)
