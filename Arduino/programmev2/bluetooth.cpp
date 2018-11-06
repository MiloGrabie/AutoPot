// A CHANGER
#include "conf.h"
#include "arduino.h"
#include "bluetooth.h"
#include <SoftwareSerial.h>


int i = 0;
static char someChar[32] = {0};
// when characters arrive over the serial port...
SoftwareSerial mySerial(rxPin, txPin); // RX, TX
void initBluetooth() {
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
 mySerial.begin(38400);
}

// on récupère le type de message
char getMessageType(char* type) {
  if (mySerial.available()) {
    *type=mySerial.read();
    return (BL_OK);
      }
  else return(BL_ERR_NO_MESSAGE);
}

char getMessageContent(char type,char* Content) {
    if (type==MARCHE) return(BL_ERR_NO_PARAMETER);
    if (type==ARRET) return(BL_ERR_NO_PARAMETER);
    if (type==DUREE) {
      for (i=0;i<2;i++) {
        Content[i] = mySerial.read();
    }
    return(BL_OK);
    }
}


void writeMessage() {
}



