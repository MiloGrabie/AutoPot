#include "conf.h"
#include "arduino.h"
#include "setup.cpp"
#include <SoftwareSerial.h>

int value = 0 ;
value = analogRead(SENSE);
value = value / 10;
Serial.println(value);
if (value < 50)
{
  digitalWrite(WET, HIGH);
}
else
{
  digitalWrite(WET, LOW);
}


