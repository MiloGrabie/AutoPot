#include "arduino.h"
#include "bluetooth.h"
#include "testAndDebug.h"
#include "storeManagement.h"
#include <SoftwareSerial.h>
static int td_onOff = 0;
static int tf_onOff = 0;
static int td_send = 0;
static int tf_send = 0;
int i = 0;
boolean connecte = false;
static char someChar[32] = {0};
// when characters arrive over the serial port...


void BL_init() {
  Serial3.begin(9600);
}

void BL_sendAck(void) {
  Serial3.print(_ACK_);
}
void BL_writeln(char* mess) {
  Serial3.println(mess);
}

void BL_write(char* mess) {
  Serial3.print(mess);
}

void BL_writeInt(int mess) {
  Serial3.print(mess);
}

void BL_writelnInt(int mess) {
  Serial3.println(mess);
}
boolean BL_getAck(void) {
  int td = millis();
  int tf;
  char ack;
  do {
    tf = millis();
  } while (!Serial3.available() && (tf - td) < BL_TIMEOUT_ACK);
  if (Serial3.available()) {
    ack = (char)Serial3.read();
    if (ack == _ACK_) {
      connecte = true;
      return (true);
    } else {
      connecte = false;
      return (false);
    }
  } else {
    connecte = false;
    return (false);
  }
}

// on récupère le type de message
char BL_getMessageType(int* type) {
  if (!connecte) BL_getAck();
  if (connecte) {
    if (Serial3.available()) {
      *type = (int)Serial3.read();
      return (BL_OK);
    }
    else return (BL_ERR_NO_MESSAGE);
  } else
    return (BL_ERR_NO_MESSAGE);
}

char BL_getMessageContent(int type, char* Content) {
  if (!connecte) BL_getAck();
  if (connecte) {
    if (type == BL_MARCHE) return (BL_ERR_NO_PARAMETER);
    if (type == BL_ARRET) return (BL_ERR_NO_PARAMETER);
    if (type == BL_DUREE) {
      for (i = 1; i >= 0; i--) {
        do {} while (!Serial3.available());
        Content[i] = Serial3.read();
      }
      return (BL_OK);
    }
  } else
    return (BL_ERR_NO_PARAMETER);
}



void BL_sendStateOnOff(boolean onOff) {

  tf_onOff = millis();
  if (!connecte) BL_getAck();
  if (((tf_onOff - td_onOff) > BL_TIME_MIN_BETWEEN_2_ON_OFF)&&((tf_onOff - td_send) > BL_TIME_MIN_BETWEEN_2_SERIALS)) {
    if (connecte) {
      if (onOff) {
        BL_writeln("ON,");
        testDebug_print("ON");
        BL_getAck();
      }
      if (!onOff) {
        BL_writeln("OFF,");
        testDebug_print("OFF");
        BL_getAck();
      }
    }
    td_onOff = tf_onOff;
  }
}


void BL_sendData(void) {
  elemStruct Elem;
  tf_send = millis();
  if (!connecte) BL_getAck();
  if (((tf_send - td_send) > BL_TIME_MIN_BETWEEN_2_SERIALS)&&((tf_send - td_onOff)>BL_TIME_MIN_BETWEEN_2_SERIALS)) {
    if (connecte) {
      if (SM_dataLeft()) {
        testDebug_print("DATA");
        Elem = SM_getNextElem();
        BL_write("DATA,");
        BL_writeInt(Elem.id);
        BL_write(",");
        BL_writeInt(Elem.humidity);
        BL_write(",");
        BL_writeInt(Elem.waterigDuration);
        BL_writeln(",");
        BL_getAck();
      }
    }
    td_send = tf_send;
  }
}



