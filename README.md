# STM32評価F/W開発
STM32のFreeRTOS搭載F/Wの個人開発リポジトリ🥳

- 📍CPU ... [STM32F103C8T6](https://www.st.com/en/microcontrollers-microprocessors/stm32f103c8.html)
  - 📍[ARM Cortex-M3🔗](https://www.arm.com/ja/products/silicon-ip-cpu/cortex-m/cortex-m3)

- 📍OS ... [FreeRTOS🔗](https://www.freertos.org/)
  - 📍CPU ... ✅FreeRTOS (搭載済み)

## 📍開発環境

### 📍IDE
- 📍[Arduino IDE v2.33🔗](https://github.com/arduino/arduino-ide/releases/tag/2.3.3)
  - 📍[STM32duino🔗](https://github.com/stm32duino)
  - 📍[STM32FreeRTOS🔗](https://github.com/stm32duino/STM32FreeRTOS)

### 📍基板
- 📍[RobotDyn BlackPill🔗](https://robotdyn.com/stm32-arm-arduino-mini-system-dev-board-blue-pill-with-arduino-bootloader.html)

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