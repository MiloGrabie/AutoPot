//------- setup ------
// test car fonctionne pas dans setup.cpp
#include <SoftwareSerial.h>
#include "conf.h"
#include "humiditySensor.h"
#include "arduino.h"
#include "bluetooth.h"
#include "movingmotor.h"

#define DEBUG

//int wet; // wet Indicator at Digital PIN D13  A BOUGER
//SoftwareSerial mySerial(rxPin, txPin);


boolean isWet= false;
boolean pumpOn= false;
boolean motorPignonFrontOn= false;
boolean motorPignonBackOn= false;
boolean marche=false;


char ret=0; // retour des fonctions

char messageType;
int dureeDeFonctionnementInitial;

void setup() {
  // put your setup code here, to run once:
  /* Programme capteur humiditÃ©*/
  /* Serial.begin(9600);
    Serial.println("SOIL MOISTURE SENSOR");
    Serial.println("-----------------------------");*/

  initHumiditySensor(SENSE);
  initBluetooth();
  /*programme module HC-05*/
  // define pin modes for tx, rx pins:
  /* pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    mySerial.begin(9600);
    Serial.begin(9600);*/
  // A MODIF
  /* init moteurs*/
//  pinMode(motorPignonFront, OUTPUT);
//  pinMode(motorPignonBack, OUTPUT);
//  pinMode(PUMP, OUTPUT);

initMotor();


  /*
    pinMode(MoteurPignonFront,OUTPUT)
    pinMode(MoteurPignonFront,OUTPUT) A MODIF
    pinMode(MoteurPignonFront,OUTPUT)
  */
  /* mySerial.begin(38400);
    Serial.begin(38400);*/
  /*capteurs fin de course*/
//  pinMode(buttonpin1, INPUT); // declare buttonpin (digital 47) as input
//  pinMode(buttonpin2, INPUT); // declare buttonpin (digital 48) as input
}


void loop() {
  // put your main code here, to run repeatedly:
  /*programme moteurs dÃƒÂ©placement*/
  
  ret = getMessageType(messageType);
  if (ret!=BL_ERR_NO_MESSAGE) {
        if (messageType==MARCHE) marche=true;
        if (messageType==ARRET) marche=false;
                if (messageType==DUREE) {
                  ret = getMessageContent(DUREE,(char*)&dureeDeFonctionnementInitial);
                  #ifdef DEBUG
                  if (ret!=BL_OK) Serial.println("Err Message duree");
                  #endif
                }
  }
  
  if ((!isWet ) && (!pumpOn) && (!isPignonUp()) && (!isPignonDown()))
  {
    movingForward () ;
  }
  else
  {
    movingStop () ;
  }
}



/* Selon l'humiditÃƒÂ©, dÃƒÂ©finir un certain temps d'arrosage (pompe allumÃƒÂ©e) -> arbitraire avant les tests
    tant que le robot ne dÃƒÂ©tecte pas une tomate, ou n'arrose pas, il doit continuer ÃƒÂ  avancer (2 moteurs de dÃƒÂ©placement)
  moteur pignon crÃƒÂ©maillÃƒÂ¨re dÃƒÂ©clenchÃƒÂ© ÃƒÂ  chaque fois qu'une bonne plante est dÃƒÂ©tectÃƒÂ©e par la camÃƒÂ©ra
  capteur fin de course activÃƒÂ© -> on arrÃƒÂªte le moteur pignon crÃƒÂ©maillÃƒÂ¨res puis on remonte aprÃƒÂ¨s
  la dÃƒÂ©tecction du capteur humiditÃƒÂ© (+-5sec), puis on redÃƒÂ©marre le moteur, arrÃƒÂªt lorsque le 2ÃƒÂ¨me capteur fin de course est activÃƒÂ©
  comment faire un arduino qui peut lire un autre programme, rÃƒÂ©cupÃƒÂ©rer les donnÃƒÂ©es : 3channels serial sur la arduino mega. Multithread.
*/


