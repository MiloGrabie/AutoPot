 #include "conf.h"
#include "arduino.h"
#include <SoftwareSerial.h>
int i = 0;
char someChar[32] = {0};
// when characters arrive over the serial port...
if (Serial.available()) {
  do {
    someChar[i++] = Serial.read();
    delay(3);
  } while (Serial.available() > 0);
  mySerial.println(someChar);
  Serial.println(someChar);

