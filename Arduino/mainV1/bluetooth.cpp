#include "conf.h"
#include "arduino.h"
#include "bluetooth.h"
#include <SoftwareSerial.h>

int i = 0;
static char someChar[32] = {0};
// when characters arrive over the serial port...
SoftwareSerial mySerial(BL_RX_PIN, BL_TX_PIN); // RX, TX
void BL_init() {
  pinMode(BL_RX_PIN, INPUT);
  pinMode(BL_TX_PIN, OUTPUT);
    Serial3.begin(9600);
         
}

// on récupère le type de message
char BL_getMessageType(int* type) {
  if (Serial3.available()) {
    *type = (int)Serial3.read();
    return (BL_OK);
  }
  else return (BL_ERR_NO_MESSAGE);
}

char BL_getMessageContent(int type, char* Content) {
  if (type == BL_MARCHE) return (BL_ERR_NO_PARAMETER);
  if (type == BL_ARRET) return (BL_ERR_NO_PARAMETER);
  if (type == BL_DUREE) {
    for (i = 1; i >= 0; i--) {
       do {} while (!Serial3.available());
      Content[i] = Serial3.read();
    }
    return (BL_OK);
  }
}


void BL_write(char* mess) {
  Serial3.println(mess);
}



