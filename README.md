# STM32評価F/W開発

STM32のFreeRTOS搭載F/Wの個人開発リポジトリ🥳

## 📍IDE

- 📍[Arduino IDE v2.36🔗](https://github.com/arduino/arduino-ide/releases/tag/2.3.6)
  - 📍[STM32duino v2.10.1🔗](https://github.com/stm32duino/Arduino_Core_STM32/releases/tag/2.10.1)

## 📍OS (RTOS)

- 📍[FreeRTOS🔗](https://www.freertos.org/)
  - ➡️ [STM32duino FreeRTOS v10.3.2🔗](https://github.com/stm32duino/STM32FreeRTOS)

## 📍基板

### STM32F1

- 📍[RobotDyn BlackPill🔗](https://robotdyn.com/stm32-arm-arduino-mini-system-dev-board-blue-pill-with-arduino-bootloader.html)
  - マイコン
    - 📍[STM32F103CBT6🔗](https://www.st.com/en/microcontrollers-microprocessors/stm32f103c8.html)
    - CPU
      - 📍[ARM Cortex-M3🔗](https://www.arm.com/ja/products/silicon-ip-cpu/cortex-m/cortex-m3)

### STM32H7

- 📍[DevEBox STM32H743🔗](https://github.com/mcauser/MCUDEV_DEVEBOX_H7XX_M)
  - マイコン
    - 📍[STM32H743VIT6🔗](https://www.st.com/ja/microcontrollers-microprocessors/stm32h743-753.html)
    - CPU
      - 📍[ARM Cortex-M7🔗](https://www.arm.com/ja/products/silicon-ip-cpu/cortex-m/cortex-m7)

## 📍実装機能

- 凡例(✅実装＆テスト完了、🆗実装済み、🚩TODO、❌TBD)

- 📍OS ... FreeRTOS
  - ✅メインタスク
    - ✅状態遷移、LED処理
  - 🚩ボタンタスク
    - 🚩ボタン処理
      - 🚩ボタン単押し ... TODO
      - 🚩ボタン複数押し判定 ... TODO
      - 🚩ボタン長押し判定 ... TODO
      - 🚩ボタン超長押し判定 ... TODO