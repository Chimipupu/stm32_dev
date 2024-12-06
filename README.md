# STM32評価F/W開発

STM32のFreeRTOS搭載F/Wの個人開発リポジトリ🥳

## 📍開発環境

### 📍IDE

- 📍[Arduino IDE v2.34🔗](https://github.com/arduino/arduino-ide/releases/tag/2.3.4)
  - 📍[STM32duino🔗](https://github.com/stm32duino)
  - 📍[STM32FreeRTOS🔗](https://github.com/stm32duino/STM32FreeRTOS)

### 📍OS (RTOS)

- 📍[FreeRTOS🔗](https://www.freertos.org/)
  - 📍CPU ... ✅FreeRTOS (搭載済み)

### 📍基板

#### STM32F1

- 📍[RobotDyn BlackPill🔗](https://robotdyn.com/stm32-arm-arduino-mini-system-dev-board-blue-pill-with-arduino-bootloader.html)
  - 📍CPU ... [STM32F103CBT6🔗](https://www.st.com/en/microcontrollers-microprocessors/stm32f103c8.html)
    - 📍[ARM Cortex-M3🔗](https://www.arm.com/ja/products/silicon-ip-cpu/cortex-m/cortex-m3)

#### STM32H7

- 📍[DevEBox STM32H743🔗](https://github.com/mcauser/MCUDEV_DEVEBOX_H7XX_M)
  - 📍CPU ... [STM32H743VIT6🔗](https://www.st.com/ja/microcontrollers-microprocessors/stm32h743-753.html)
    - 📍[ARM Cortex-M7🔗](https://www.arm.com/ja/products/silicon-ip-cpu/cortex-m/cortex-m7)

## 📍実装機能

**凡例(✅実装＆テスト完了、🆗実装済み、🚩TODO、❌TBD)**

### OS(FreeRTOS)

- 📍OS ... FreeRTOS
  - ✅メインタスク
    - ✅状態遷移、LED処理
  - 🚩ボタンタスク
    - 🚩ボタン処理
      - 🚩ボタン単押し ... TODO
      - 🚩ボタン複数押し判定 ... TODO
      - 🚩ボタン長押し判定 ... TODO
      - 🚩ボタン超長押し判定 ... TODO