int GLED= 13; // Wet Indicator at Digital PIN D13
int RLED= 12; // Dry Indicator at Digital PIN D12
int SENSE= 0; // Soil Sensor input at Analog PIN A0
int value= 0;
void setup() {
    // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(GLED, OUTPUT);
 pinMode(RLED, OUTPUT);
 Serial.println("SOIL MOISTURE SENSOR");
 Serial.println("-----------------------------");
}
void loop() {
   // put your main code here, to run repeatedly:
 value= analogRead(SENSE);
 value= value/10;
 Serial.println(value);
 if(value<50)
 {
 digitalWrite(GLED, HIGH);
 }
 else
 {
 digitalWrite(RLED,HIGH);
 }
 delay(1000);
 digitalWrite(GLED,LOW);
 digitalWrite(RLED, LOW);
}
