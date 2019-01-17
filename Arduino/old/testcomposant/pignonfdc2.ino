#define motorPignonUp 23
#define motorPignonDown 24
#define buttonpin1 49 // Variable buttonpin = connected to digital line 47, this is where the VMA327 output has to be connected for this test FIL COURT ROUGE AVEC FIL LONG ROUGE
#define buttonpin2 48 // Variable buttonpin = connected to digital line 48, this is where the VMA327 output has to be connected for this test
int valuefindecourse1;
int valuefindecourse2;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonpin1, INPUT); // declare buttonpin (digital 48) as input (capteur1)
  pinMode(buttonpin2, INPUT); // declare buttonpin (digital 47) as input (capteur2)
  pinMode(motorPignonUp, OUTPUT);
  pinMode(motorPignonDown, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
    valuefindecourse1 = digitalRead(buttonpin1); // read the value of buttonpin (digital 48)
    valuefindecourse2 = digitalRead(buttonpin2); // read the value of buttonpin (digital 47)
    Serial.println(valuefindecourse1);
   // Serial.println(valuefindecourse2);

if (valuefindecourse1 == LOW && valuefindecourse2==LOW) {
digitalWrite(motorPignonUp,HIGH);
digitalWrite(motorPignonDown, LOW);}
else if(valuefindecourse1 == HIGH && valuefindecourse2==LOW) {
digitalWrite(motorPignonUp,LOW);
digitalWrite(motorPignonDown, LOW);}
  else if(valuefindecourse1 == LOW && valuefindecourse2==HIGH) {
digitalWrite(motorPignonUp,LOW);
digitalWrite(motorPignonDown, LOW);}
else {
  digitalWrite(motorPignonUp,HIGH);
digitalWrite(motorPignonDown, HIGH);}
}

