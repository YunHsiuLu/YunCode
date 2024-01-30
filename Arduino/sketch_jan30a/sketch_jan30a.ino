#include <arduinoFFT.h>

#define SAMPLES 128
#define SAMPLING_FREQUENCY 4096

arduinoFFT FFT = arduinoFFT();

unsigned int samplingPeriod;
unsigned int microSeconds;

double vReal[SAMPLES];
double vImag[SAMPLES];
double peak = 0;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  samplingPeriod = round(1000000*(1.0/SAMPLING_FREQUENCY));
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < SAMPLES; i++) {
    microSeconds = micros();

    vReal[i] = analogRead(0);
    vImag[i] = 0;

    while(micros() < (microSeconds + samplingPeriod)) {}
  }

  FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
  FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);

  peak += FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY)*2;
  count++;
  if (count == 10 ) {
    peak /= count;
    Serial.println(peak);
    count = 0;
    peak = 0;
  }
}
