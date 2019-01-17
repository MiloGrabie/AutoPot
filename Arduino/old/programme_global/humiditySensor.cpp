#include "Arduino.h"
#include "setup.cpp"
#include "conf.h"
//#include <SoftwareSerial.h>
void test () {
int value = 0;
value = analogRead(sense);
value = value / 10;
if (value < 50) {
  digitalWrite(WET, HIGH);
}
else {
  digitalWrite(WET, LOW);
}

}
