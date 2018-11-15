#include <SoftwareSerial.h>
#include "conf.h"
#include "humiditySensor.h"
#include "arduino.h"
#include "bluetooth.h"
#include "movingmotor.h"
#include "motorPignon.h"
#define DEBUG

boolean isWet = false;
boolean pumpOn = false;
boolean motorPignonFrontOn = false;
boolean motorPignonBackOn = false;
boolean marche = false;


char ret = 0; // retour des fonctions

char messageType;
int dureeDeFonctionnementInitial;

void setup() {
  // put your setup code here, to run once:
  /* init capteur humidité*/
  initHumiditySensor(SENSE);
  /*init module HC-05*/
  initBluetooth();
  /* init moteurs deplacement*/
  initmovingMotor();
  /* init moteurs pignon*/
  initMotorPignon();
  /*init capteurs fin de course*/
  initCapteursfindecourse();
  /*init pompe*/
  initPump();
}

void loop() {
  // put your main code here, to run repeatedly:
  /*programme bluetooth*/

  ret = getMessageType(messageType);
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
  /*programme moteur déplacement*/
  if ((!isWet ) && (!pumpOn) && (!isPignonUp()) && (!isPignonDown()))
  {
    movingForward () ;
  }
  else
  {
    movingStop () ;
  }

  /*programme moteur pignon*/
  if ((isPignonUp()) && (findecourse1on))
  {
    pignonStop () ;
  }
  
  if ((isPignonDown()) && (findecourse2on))
  {
    pignonStop () ;
  }


}

/* Selon l'humiditÃƒÂ©, dÃƒÂ©finir un certain temps d'arrosage (pompe allumÃƒÂ©e) -> arbitraire avant les tests
    tant que le robot ne dÃƒÂ©tecte pas une tomate, ou n'arrose pas, il doit continuer ÃƒÂ  avancer (2 moteurs de dÃƒÂ©placement)
  moteur pignon crÃƒÂ©maillÃƒÂ¨re dÃƒÂ©clenchÃƒÂ© ÃƒÂ  chaque fois qu'une bonne plante est dÃƒÂ©tectÃƒÂ©e par la camÃƒÂ©ra
  capteur fin de course activÃƒÂ© -> on arrÃƒÂªte le moteur pignon crÃƒÂ©maillÃƒÂ¨res puis on remonte aprÃƒÂ¨s
  la dÃƒÂ©tecction du capteur humiditÃƒÂ© (+-5sec), puis on redÃƒÂ©marre le moteur, arrÃƒÂªt lorsque le 2ÃƒÂ¨me capteur fin de course est activÃƒÂ©
  comment faire un arduino qui peut lire un autre programme, rÃƒÂ©cupÃƒÂ©rer les donnÃƒÂ©es : 3channels serial sur la arduino mega. Multithread.
*/


