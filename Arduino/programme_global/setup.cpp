#include <SoftwareSerial.h>
#include "conf.h"
#include "arduino.h"
int WET; // Wet Indicator at Digital PIN D13  A BOUGER
SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  // put your setup code here, to run once:
  /* Programme capteur humidité*/
  Serial.begin(9600);
  pinMode(WET, OUTPUT);
  Serial.println("SOIL MOISTURE SENSOR");
  Serial.println("-----------------------------");
  /*programme module HC-05*/
  // define pin modes for tx, rx pins:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  /* init moteurs*/
  pinMode(motorPignonFront, OUTPUT);
  pinMode(motorPignonBack, OUTPUT);
  pinMode(motorDeplacement1Front, OUTPUT);
  pinMode(motorDeplacement1Back, OUTPUT);
  pinMode(motorDeplacement2Front, OUTPUT);
  pinMode(motorDeplacement2Back, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(motorDeplacement2Back, OUTPUT);
  pinMode(motorDeplacement2Back, OUTPUT);



  /*
    pinMode(MoteurPignonFront,OUTPUT)
    pinMode(MoteurPignonFront,OUTPUT) A MODIF
    pinMode(MoteurPignonFront,OUTPUT)
  */
  mySerial.begin(38400);
  Serial.begin(38400);
  /*capteurs fin de course*/
  pinMode(buttonpin1, INPUT); // declare buttonpin (digital 47) as input
  pinMode(buttonpin2, INPUT); // declare buttonpin (digital 48) as input
}
