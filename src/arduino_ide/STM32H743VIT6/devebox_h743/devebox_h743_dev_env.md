# 開発環境(DevEBox H743)

DevEBoxのでSTM32H743の開発環境は下記の通り

## 📍IDE

- 📍[Arduino IDE v2.34🔗](https://github.com/arduino/arduino-ide/releases/tag/2.3.4)
  - 📍[STM32duino🔗](https://github.com/stm32duino)

### 設定内容

⚠️USB CDCは下記でしかWindowsが認識しない⚠️

- **USB CDCでgeneric Serial**
- **USBのスピードはLow**

![arduinoide devenv img](/doc/STM32H743VIT6/img/devebox_h743_arduino_ide_dev_env.png)

## 📍OS (RTOS)

- 📍[FreeRTOS🔗](https://www.freertos.org/)
  - ➡️ [STM32FreeRTOS🔗](https://github.com/stm32duino/STM32FreeRTOS)

## 📍基板

- 📍[DevEBox STM32H743🔗](https://github.com/mcauser/MCUDEV_DEVEBOX_H7XX_M)
  - 📍CPU ... [STM32H743VIT6🔗](https://www.st.com/ja/microcontrollers-microprocessors/stm32h743-753.html)
    - 📍[ARM Cortex-M7🔗](https://www.arm.com/ja/products/silicon-ip-cpu/cortex-m/cortex-m7)