#include <FreqCountESP.h>

void setup()
{
  int inputPin = 4;
  int timerMs = 1000;
  FreqCountESP.begin(inputPin, timerMs);
  Serial.begin(9600);
}

void loop()
{
  static uint32_t lastFrequency = 0;  // 上次測量到的頻率

  if (FreqCountESP.available())
  {
    uint32_t frequency = FreqCountESP.read();

    // 實際測量到的頻率比上一次高時，進行更新並輸出
    if (frequency > lastFrequency)
    {
      lastFrequency = frequency;

      // 檢查是否在指定範圍內（300到3000之間），並輸出
      if (frequency >= 300 && frequency <= 3000)
      {
        Serial.println(frequency);
      }
    }
  }

  delay(50);
}
