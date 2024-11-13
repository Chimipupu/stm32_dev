/**
 * @file bluepill_f128kb.ino
 * @author ちみ/Chimi(https://github.com/Chimipupu)
 * @brief BluePill (Flash:128KB)のinoファイル
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024 ちみ/Chimi(https://github.com/Chimipupu)
 * 
 */

#include <stdint.h>
#include <string.h>

void setup(void)
{
    Serial.begin(115200);
}

void loop(void)
{
    Serial.printf("Serial Test\n");
    delay(1000);
}