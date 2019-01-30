#include <simpleRPC.h>
#include "waterManagement.h"
#include "arduino.h"
#include "bluetooth.h"
#include "moveRobot.h"
#include "testAndDebug.h"
#include "storeManagement.h"

boolean marche = false;
char ret = BL_ERR_NO_MESSAGE; // retour des fonctions
int messageType;
int dureeDeFonctionnementInitial;

// tests unitaires
//int nbLoop = 0;
//boolean done = false;
int t0 = 0;
int t1;
int pos;
int hum;
int water;


void setup() {
  testDebug_init();
  testDebug_print("demarrage");
  /*init module HC-05*/
  BL_init();
  /*init moteurs robots et arrosage*/
  MR_WM_init();
}


void MR_WM_init(void) {
  /* init moteurs deplacement*/
  MR_init();
  /* init organes liés au capteur d'humidité et à l'arrosage*/
  // WM_init(); //à commenter quand il n'y a pas de capteur de fin de course
}

void getMessageFromBluetooth() {
  ret = BL_getMessageType(&messageType);
  if (ret != BL_ERR_NO_MESSAGE) {
    testDebug_printInt(messageType);
    if (messageType == BL_MARCHE) {
      // on reinitialise les actionneurs
      MR_WM_init();
      // on autorise la Raspberry à actionner le robot
      MR_authorization(true);
      WM_authorization(true);
      marche = true;
      testDebug_print("BL_MARCHE");
    }
    if (messageType == BL_ARRET) {
      // on reinitialise les actionneurs
      MR_WM_init();
      // on interdit que la Raspberry actionne le robot
      MR_authorization(false);
      WM_authorization(false);
      marche = false;
      testDebug_print("BL_ARRET");
    }
  }
}


void loop() {
  // Fonctions accessibles en rpc par la Raspberry
  interface(
    test_read_Analog, "read_analog: Return analog. @a: Pin. @return: analog value.",
    test_setPin, "set_pin: set value to pin. @pin: set the pin. @value: set the value.",
    test_time, "time: Report the system time. @return: System time.",
    MR_wheelStartMove, "MR_wheelStartMove : start new move. @leftWheelMove:-1,0,1. @rigthtWheelMove:-1,0,1. @moveDuration:in ms. @return:error code 1 OK. 2 ALREADY ONGOING. 3 NOT_AUTHORIZED.",
    WM_startMeasureAndWatering, "WM_startMeasureAndWatering : start watering cycle. @p_position:integer. @return:error code 100 OK. 101 ALREADY ONGOING. 102 NOT_AUTHORIZED.");

  //  l'arrosage et le déplaceement du robot sont exclusifs
  if (WM_getMeasureAndWateringStatus() != WM_STATUS_WATERING_ENDED) MR_authorization(false);
  else  MR_authorization(true);
  if (MR_wheelMoveStatus() != MR_STATE_MOVE_ENDED) WM_authorization(false);
  else  WM_authorization(true);

  // récupération des messages bluetooth
  getMessageFromBluetooth();

  //progressions des états d'avancement du robot et de l'arrosage
  WM_measureAndWateringManagement();
  MR_wheelMoveManagement();
  BL_sendStateOnOff(marche);
  BL_sendData();
  
  //code temporaire pour tests unitaires
  //  WM_authorization(false);
  //  if ((nbLoop == 200) && (!done)) {
  //    WM_startMeasureAndWatering();
  //    done = true;
  //  }
  //  MR_authorization(false);
  //  if ((nbLoop==200)&&(!done)) {
  //      MR_wheelStartMove(MR_FRONT, MR_BACK, 5000); //MR_BACK, MR_STOP
  //    done=true;
  //  }
  
  if (marche) {
    t1 = millis();
    if ((t1 - t0) > 5000) {
      SM_store(pos++, t0 % 1000, t1 % 1000); // simule le stockage de données toutes les 5 secondes
      t0 = t1;
    }
  }


  //
  //
  //boolean SM_dataLeft(void) {
  //  if (memoire.nbElem!=0) return(true) else return(false);
  //}
  //
  //elemStruct SM_getNextElem(void() {


}




