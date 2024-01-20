int raw0 = 0;
int raw1 = 0;
//int raw2 = 0;
//int raw3 = 0;
//int raw4 = 0;
int raw5 = 0;
int Vin = 5;
double R1_prin = 584; // float between 585 and 583
//double R1_prin = 197.5; // float between 197 and 198
double V1 = 0;
double V2 = 0;
double V3 = 0;
double V4 = 0;
double V5 = 0;
double I = 0;
//double error = 0;
int c = 0;
int mean_time = 20;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  raw0 += analogRead(A0);
  raw1 += analogRead(A1);
  //raw2 += analogRead(A1);
  //raw3 += analogRead(A2);
  //raw4 += analogRead(A4);
  raw5 += analogRead(A5);
  if (c == mean_time) {
    raw0 = (double) raw0 / mean_time;
    raw1 = (double) raw1 / mean_time;
    //raw2 = (double) raw2 / mean_time;
    //raw3 = (double) raw3 / mean_time;
    //raw4 = (double) raw4 / mean_time;
    raw5 = (double) raw5 / mean_time;
    V1 = raw0 * Vin / 1024.;
    V2 = raw1 * Vin / 1024.;
    //V3 = raw3 * Vin / 1024.;
    //V4 = raw4 * Vin / 1024.;
    V5 = raw5 * Vin / 1024.;
    I = V5 / R1_prin;
    //I = V5 / R2_prin;

    Serial.print(V1, 10);
    Serial.print(",");
    Serial.print(V2, 10);
    Serial.print(",");
    Serial.print(V5, 10);
    Serial.print(",");
    Serial.println(I, 10);

    raw0 = 0;
    raw1 = 0;
    //raw2 = 0;
    //raw3 = 0;
    //raw4 = 0;
    raw5 = 0;
    c = 0;
  }
  
  c += 1;
  delay(100);
}
