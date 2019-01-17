#define Pump 2
void setup() {
  // put your setup code here, to run once:
  pinMode(Pump, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(Pump, HIGH);
delay(2000);
digitalWrite(Pump,LOW);
delay(2000);
}
