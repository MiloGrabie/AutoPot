#include <SoftwareSerial.h>
#define rxPin 19 // Broche 19 en tant que RX, à raccorder sur TX du HC-05
#define txPin 18 // Broche 18 en tant que TX, à raccorder sur RX du HC-05
#define MoteurPignonFront 23 
#define MoteurPignonBack 24
#define MoteurDeplacement1Front 37 //AJOUTER LES PINS
#define MoteurDeplacement1Back 38  //AJOUTER LES PINS
#define MoteurDeplacement2Front 29  //AJOUTER LES PINS
#define MoteurDeplacement2Back 30  //AJOUTER LES PINS
#define pump 22
SoftwareSerial mySerial(rxPin, txPin);
int WET; // Wet Indicator at Digital PIN D13
int DRY; // Dry Indicator at Digital PIN D12
int SENSE= A1; // Soil Sensor input at Analog PIN A1
int value= 0;
int buttonpin1=47; // Variable buttonpin = connected to digital line 47, this is where the VMA327 output has to be connected for this test
int buttonpin2=48; // Variable buttonpin = connected to digital line 48, this is where the VMA327 output has to be connected for this test
int val1;
int val2;
int CAMdetection;
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
/*capteurs fin de course*/
pinMode(buttonpin1,INPUT); // declare buttonpin (digital 47) as input
pinMode(buttonpin2,INPUT); // declare buttonpin (digital 48) as input
}

void loop() {
  // put your main code here, to run repeatedly:
  /*programme moteurs déplacement*/
 
 if ((WET==LOW)&& (pump==LOW) && (MoteurPignonFront==LOW) && (MoteurPignonBack==LOW)) 
  {
  digitalWrite(MoteurDeplacement1Front, HIGH) ;
  digitalWrite(MoteurDeplacement2Front, HIGH);
  digitalWrite(MoteurDeplacement1Back, LOW);
  digitalWrite(MoteurDeplacement2Back, LOW);
 }  
 else 
 {
  digitalWrite(MoteurDeplacement1Front, LOW) ;
  digitalWrite(MoteurDeplacement2Front, LOW);
  digitalWrite(MoteurDeplacement1Back, LOW);
  digitalWrite(MoteurDeplacement2Back, LOW);}
  /* Programme capteur humidité*/
value= analogRead(SENSE);
 value= value/10;
 Serial.println(value);
 if(value<50)
 {
 digitalWrite(WET,HIGH);
 digitalWrite(DRY,LOW);

 }
 else
 {
 digitalWrite(DRY,HIGH);
 digitalWrite(WET,LOW);
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
 /*moteur pignons cremaillere */
}
while(mySerial.available())
 Serial.print((char)mySerial.read());
 {
val1=digitalRead(buttonpin1); // read the value of buttonpin (digital 47)
val1=digitalRead(buttonpin2); // read the value of buttonpin (digital 48)
if((val1==HIGH)&& (val2==LOW)) // AJOUTER LA PRISE EN CONSIDERATION : MOTEUR ALLUME QUAND BONNE PLANTE DETECTEE
{
 digitalWrite(MoteurPignonFront,LOW); 
 digitalWrite (MoteurPignonBack,LOW);
 } 
 else if ((val1==LOW) && (val2==HIGH))
 {
  digitalWrite(MoteurPignonFront,LOW); 
  digitalWrite (MoteurPignonBack,LOW);
 }  
 else if ((val1==LOW) && (val2==LOW) && (CAMdetection==HIGH)) //REFLECHIR COMMENT RAMENER LES DONNEES RENVOYEES PAR LA CAMERA / NOM DE LA CAMERA???
  { digitalWrite(MoteurPignonFront,HIGH); 
  digitalWrite (MoteurPignonBack,LOW);
 }
 else { digitalWrite(MoteurPignonFront,LOW); } // else .. switch to low
}
 if((WET==HIGH) && (DRY==LOW))
  { digitalWrite(pump,HIGH);
    delay(5000);
    digitalWrite(pump,LOW); }
  else
  { digitalWrite(pump,LOW);
  }
}


/* Selon l'humidité, définir un certain temps d'arrosage (pompe allumée) -> arbitraire avant les tests
 *  tant que le robot ne détecte pas une tomate, ou n'arrose pas, il doit continuer à avancer (2 moteurs de déplacement)
 *moteur pignon crémaillère déclenché à chaque fois qu'une bonne plante est détectée par la caméra
 *capteur fin de course activé -> on arrête le moteur pignon crémaillères puis on remonte après 
 *la détecction du capteur humidité (+-5sec), puis on redémarre le moteur, arrêt lorsque le 2ème capteur fin de course est activé
 *comment faire un arduino qui peut lire un autre programme, récupérer les données : 3channels serial sur la arduino mega. Multithread.
 */
