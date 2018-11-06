
#include "arduino.h"
#define rxPin 19 // Broche 19 en tant que RX, ÃƒÂ  raccorder sur TX du HC-05
#define txPin 18 // Broche 18 en tant que TX, ÃƒÂ  raccorder sur RX du HC-05
#define motorPignonUp 23
#define motorPignonDown 24
#define motorDeplacement1Front 37
#define motorDeplacement1Back 38
#define motorDeplacement2Front 29
#define motorDeplacement2Back 30
#define PUMP 22
#define SENSE A1 // Soil Sensor input at Analog PIN A1
#define buttonpin1 47 // Variable buttonpin = connected to digital line 47, this is where the VMA327 output has to be connected for this test
#define buttonpin2 48 // Variable buttonpin = connected to digital line 48, this is where the VMA327 output has to be connected for this test
//movingmotor
//void movingForward ();
//void movingBack () ;
//void movingStop () ;
//void movingTurnRight ();
//void movingTurnLeft ();
//motorPignon
//void pignonUp ();
//void pignonBack ();
//void pignonStop ();
boolean isPignonUp();
boolean isPignonDown();
//void test3 ();

//void test1 ();
//void test2 ();
// définition des messages bluetooth
#define MARCHE 0
#define ARRET 1
#define DUREE 2

/*//------- setup ------
  // test car fonctionne pas dans setup.cpp
  #include <SoftwareSerial.h>
  //#include "conf.h"
  #include "arduino.h"
  //int wet; // wet Indicator at Digital PIN D13  A BOUGER
  //SoftwareSerial mySerial(rxPin, txPin);

  void setup() {
  // put your setup code here, to run once:
  /* Programme capteur humiditÃ©*/
/* Serial.begin(9600);
  Serial.println("SOIL MOISTURE SENSOR");
  Serial.println("-----------------------------");*/
// pinMode(wet, OUTPUT);

/*programme module HC-05*/
// define pin modes for tx, rx pins:
/* pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600);*/
// A MODIF
/* init moteurs*/
/* pinMode(motorPignonFront, OUTPUT);
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
/* mySerial.begin(38400);
  Serial.begin(38400);*/
/*capteurs fin de course*/
/*pinMode(buttonpin1, INPUT); // declare buttonpin (digital 47) as input
  pinMode(buttonpin2, INPUT); // declare buttonpin (digital 48) as input
  }*/

