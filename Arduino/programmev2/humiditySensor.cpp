#include "arduino.h"
#include <SoftwareSerial.h>
static int sensorPin=0;

void initHumiditySensor(int pin) {
  sensorPin = pin;
  pinMode(pin, INPUT);
}
  
int readHumiditySensor(void) {
  int value = 0;
  value = analogRead(sensorPin);
  value = value / 10;
  return (value);
}



