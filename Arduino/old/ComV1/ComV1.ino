#include "config.h"

void setup(){
  comInit();
}

void loop(){ // Boucle principal
  String cmd = comReceiver();
  Serial.println(cmd);
}
