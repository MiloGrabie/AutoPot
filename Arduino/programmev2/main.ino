#include <SoftwareSerial.h>
#include "conf.h"
#include "humidityControl.h"
#include "arduino.h"
#include "bluetooth.h"
#include "movingmotor.h"
#include "motorPignon.h"
#define DEBUG


boolean marche = true;

boolean leftUTurnNeeded = false;
boolean rightUTurnNeeded = false;
boolean manoeuvreRunning = false;
boolean humidityControl = false;

char ret = 0; // retour des fonctions

char messageType;
int dureeDeFonctionnementInitial;

void setup() {
  // put your setup code here, to run once:
  /* init capteur humidité*/
  initHumiditySensor(SENSE);
    /*init pompe*/
  initPump();
  
  /*init module HC-05*/
  initBluetooth();
  /* init moteurs deplacement*/
  initmovingMotor();
  /* init moteurs pignon et capteurs fin de course*/
  initMotorPignon();

     humidityControl = true;

}

void getMessageFromBluetooth() {
  ret = getMessageType(&messageType);
  if (ret != BL_ERR_NO_MESSAGE) {
    if (messageType == MARCHE) marche = true;
    if (messageType == ARRET) marche = false;
    if (messageType == DUREE) {
      ret = getMessageContent(DUREE, (char*)&dureeDeFonctionnementInitial);
#ifdef DEBUG
      if (ret != BL_OK) Serial.println("Err Message duree");
#endif
    }
  }
}


void getMessageFromRasberry() {
// leftUTurnNeeded = false;
// rightUTurnNeeded = false;
// humidityControl = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  /*programme bluetooth*/

  getMessageFromBluetooth();
  getMessageFromRasberry();
  if (marche&&!manoeuvreRunning&&!leftUTurnNeeded&&!rightUTurnNeeded&!humidityControl) {
    movingForward ();
  }
//  delay(5000);

  if (humidityControl) {
    movingStop();
     pignonDown ();
     pignonUp () ;
    //+controle arrosage
  }
     humidityControl = false;
//  if (!marche) {
//        movingStop();
//    //+arret total et rmontage du pignon
//  }


 rightUTurnNeeded = true;
  if (rightUTurnNeeded) {
    movingManoeuvreRigthUTurn(&manoeuvreRunning);
 }

//  if (leftUTurnNeeded) {
//    movingManoeuvreLeftUTurn(&manoeuvreRunning);
//  }
//
//
 /*programme moteur pignon*/
  movingManoeuvreControl(&manoeuvreRunning);

 pumpOn();


}
/* Selon l'humiditÃƒÂ©, dÃƒÂ©finir un certain temps d'arrosage (pompe allumÃƒÂ©e) -> arbitraire avant les tests
    tant que le robot ne dÃƒÂ©tecte pas une tomate, ou n'arrose pas, il doit continuer ÃƒÂ  avancer (2 moteurs de dÃƒÂ©placement)
  moteur pignon crÃƒÂ©maillÃƒÂ¨re dÃƒÂ©clenchÃƒÂ© ÃƒÂ  chaque fois qu'une bonne plante est dÃƒÂ©tectÃƒÂ©e par la camÃƒÂ©ra
  capteur fin de course activÃƒÂ© -> on arrÃƒÂªte le moteur pignon crÃƒÂ©maillÃƒÂ¨res puis on remonte aprÃƒÂ¨s
  la dÃƒÂ©tecction du capteur humiditÃƒÂ© (+-5sec), puis on redÃƒÂ©marre le moteur, arrÃƒÂªt lorsque le 2ÃƒÂ¨me capteur fin de course est activÃƒÂ©
  comment faire un arduino qui peut lire un autre programme, rÃƒÂ©cupÃƒÂ©rer les donnÃƒÂ©es : 3channels serial sur la arduino mega. Multithread.
*/


