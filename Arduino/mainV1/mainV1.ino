//#include <simpleRPC.h>
#include <SoftwareSerial.h>
#include "conf.h"
#include "waterManagement.h"
#include "arduino.h"
#include "bluetooth.h"
#include "moveRobot.h"

#define DEBUG

boolean marche = false;

char ret = BL_ERR_NO_MESSAGE; // retour des fonctions
int messageType;
int dureeDeFonctionnementInitial;
int t1 = 0;
int t2 = 0;
int nbLoop=0;
boolean done = false;
char someChar[32]={0};


void setup() {
#ifdef DEBUG
  Serial.begin(9600);
#endif
Serial.println("demarrage");
  /*init module HC-05*/
  BL_init();

MR_WM_init();
}


void MR_WM_init(void) {
  /* init moteurs deplacement*/
  MR_init();
  
  /* init organes liés au capteur d'humidité et à l'arrosage*/
 // WM_init(); //à commenter quand il n'y a pas de capteur de fin de course
}
unsigned long test_time(void) {
  return millis();
}

int test_read_Analog(int pin) {
  int value;
  value = digitalRead(pin);
  return value;
}

void test_setPin(int pin, int value) {
  digitalWrite(pin, value);
}


void getMessageFromBluetooth() {
  ret = BL_getMessageType(&messageType);
  if (ret != BL_ERR_NO_MESSAGE) {
     Serial.println(messageType);
      if (messageType == BL_MARCHE) {
        MR_WM_init();
        #ifdef DEBUG
        Serial.println("BL_MARCHE");
        #endif
      }
    if (messageType == BL_ARRET) {
    Serial.println("BL_ARRET");}
    if (messageType == BL_DUREE) { 
      Serial.println("BL_DUREE");
    }
    if (messageType == BL_MARCHE) marche = true;
    if (messageType == BL_ARRET) marche = false;
    if (messageType == BL_DUREE) {
      ret = BL_getMessageContent(BL_DUREE, (char*)&dureeDeFonctionnementInitial);
    }
  }
}


void loop() {
//
//  interface(
//    test_read_Analog, "read_analog: Return analog. @a: Pin. @return: analog value.",
//    test_setPin, "set_pin: set value to pin. @pin: set the pin. @value: set the value.",
//    test_time, "time: Report the system time. @return: System time.",
//    MR_wheelStartMove, "MR_wheelStartMove : start new move. @leftWheelMove:-1,0,1. @rigthtWheelMove:-1,0,1. @moveDuration:in ms. @return:error code 1 OK. 2 ALREADY ONGOING. 3 NOT_AUTHORIZED.",
//    WM_startMeasureAndWatering, "WM_startMeasureAndWatering : start watering cycle. @return:error code 100 OK. 101 ALREADY ONGOING. 102 NOT_AUTHORIZED.");

 //  l'arrosage et le déplaceement du robot sont exclusifs
  if (WM_getMeasureAndWateringStatus() != WM_STATUS_WATERING_ENDED) MR_authorization(false);
  else  MR_authorization(true);
  if (MR_wheelMoveStatus() != MR_STATE_MOVE_ENDED) WM_authorization(false);
  else  WM_authorization(true);
  
  // put your main code here, to run repeatedly:
  /*programme bluetooth*/
  
 getMessageFromBluetooth();


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

  WM_measureAndWateringManagement();
  MR_wheelMoveManagement();
  t2=millis();
  if ((t2-t1)>1000) {
  if (marche) BL_write("ON");
  if (!marche) BL_write("OFF");
    t1=t2;
  }
}




