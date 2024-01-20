int raw = 0;
int Vin = 5;
double R1_prin = 197.5; // float between 197 and 198
double R2_prin = 581.5; // float between 581 and 582
double R1_mea = 0;
double R2_mea = 0;
double V = 0;
double error = 0;
//float buffer = 0;
int c = 0;
int mean_time = 20;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //raw = analogRead(A5);
  raw += analogRead(A5);

  if (c == mean_time) {
    raw = (double) raw / mean_time;
    V = raw * Vin / 1024.;
    R1_mea = R2_prin * (Vin/V-1);
    //R2_mea = V * R1_prin / (Vin - V);
    //error = fabs((R2_mea-R2_prin)/R2_prin);
    //error = fabs((R1_mea-R1_prin)/R1_prin);
    
    /*
    Serial.print("(10 times mean) raw value from A5: ");
    Serial.print(raw);
    Serial.print(" -> voltage: ");
    Serial.print(V);
    Serial.print(" -> R2 measure: ");
    Serial.print(R2_mea);
    Serial.print(" -> Error: ");
    Serial.println(error, 4);
    */

    Serial.print("(10 times mean) raw value from A5: ");
    Serial.print(raw);
    Serial.print(" -> voltage: ");
    Serial.print(V);
    Serial.print(" -> R1 measure: ");
    Serial.print(R1_mea);
    Serial.print(" -> Error: ");
    Serial.println(error, 4);
    
    raw = 0;
    c = 0;
  }
  
  c += 1;
  delay(100);
}
