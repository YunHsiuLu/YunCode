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
  static uint32_t sensitivityThreshold = 300;  // 初始閾值
  static uint32_t maxFrequency = 0;  // 用於追蹤最大頻率的變數

  if (FreqCountESP.available())
  {
    uint32_t frequency = FreqCountESP.read();

    // 更新最大頻率
    if (frequency > maxFrequency)
    {
      maxFrequency = frequency;
    }
  }

  // 在循環結束後輸出最大頻率
  if (!FreqCountESP.available())
  {
    if (maxFrequency > sensitivityThreshold)
    {
      Serial.println(maxFrequency);
      
      // 更新閾值為最大頻率，使下次只有更高的頻率才能觸發程式
      sensitivityThreshold = maxFrequency;
    }

    maxFrequency = 0;  // 重置最大頻率
  }

  delay(50);
}
