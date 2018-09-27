#include <SoftwareSerial.h>
#define rxPin 19 // Broche 19 en tant que RX, à raccorder sur TX du HC-05
#define txPin 18 // Broche 18 en tant que TX, à raccorder sur RX du HC-05
SoftwareSerial mySerial(rxPin, txPin);
int WET; // Wet Indicator at Digital PIN D13
int DRY; // Dry Indicator at Digital PIN D12
int SENSE= A1; // Soil Sensor input at Analog PIN A1
int value= 0;
void setup() {
  // put your setup code here, to run once:
    /* Programme capteur humidité*/
 Serial.begin(9600);
 pinMode(WET, OUTPUT);
 pinMode(DRY, OUTPUT);
 Serial.println("SOIL MOISTURE SENSOR");
 Serial.println("-----------------------------");
  /*programme module HC-05*/
 // define pin modes for tx, rx pins:
 pinMode(rxPin, INPUT);
 pinMode(txPin, OUTPUT);
 mySerial.begin(38400);
 Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  /* Programme capteur humidité*/
value= analogRead(SENSE);
 value= value/10;
 Serial.println(value);
 if(value<50)
 {
 digitalWrite(WET, HIGH);
 }
 else
 {
 digitalWrite(DRY,HIGH);
 }
 //delay(1000);
// digitalWrite(WET,LOW);
// digitalWrite(DRY, LOW);
 /*programme module HC-05*/
 int i = 0;
char someChar[32] = {0};
// when characters arrive over the serial port...
if(Serial.available()) {
 do{
 someChar[i++] = Serial.read();
 delay(3);
 }while (Serial.available() > 0);
 mySerial.println(someChar);
 Serial.println(someChar);
 /*Déplacement du robot */
}
while(mySerial.available())
 Serial.print((char)mySerial.read());
}


/* Selon l'humidité, définir un certain temps d'arrosage (pompe allumée) -> arbitraire avant les tests
 *  tant que le robot ne détecte pas une tomate, ou n'arrose pas, il doit continuer à avancer (2 moteurs de déplacement)
 *moteur pignon crémaillère déclenché à chaque fois qu'une bonne plante est détectée par la caméra
 *capteur fin de course activé -> on arrête le moteur pignon crémaillères puis on remonte après 
 *la détecction du capteur humidité (+-5sec), puis on redémarre le moteur, arrêt lorsque le 2ème capteur fin de course est activé
 */
