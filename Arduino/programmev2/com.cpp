#include "conf.h"
#include "arduino.h"
#include"com.h"

void comInit(){
  Serial.begin(115200);
}

String comReceiver(){
  char szSerialInputBuffer[20]; // Cette variable est le code d'entré en ASCII
  int readSerialUntilEOL(char* _szSerialInputBuffer); // Cette partie décide quand arréter de lire le code venant de l'USB
  int iNbBytes; //Nombres de caracteres avant \n
  iNbBytes = Serial.readBytesUntil('\n', szSerialInputBuffer, 16); // l'arduino lira donc le code jusqu'a \n
  szSerialInputBuffer[iNbBytes] = '\0';
  String cmd = szSerialInputBuffer;
  return cmd;
}
