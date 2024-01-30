int Led = 13;
int buttonpin = 3;
int val;
void setup() {
  // put your setup code here, to run once:
  pinMode(Led, OUTPUT);
  pinMode(buttonpin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(buttonpin);
  if (val == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
