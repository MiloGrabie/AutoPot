#include "arduino.h"
#include <SoftwareSerial.h>
#include "humidityControl.h"
#include "conf.h"
static int sensorPin = 0;
/* Serial.begin(9600);
  Serial.println("SOIL MOISTURE SENSOR");
  Serial.println("-----------------------------");*/
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

void initPump() {
  pinMode(Pump, OUTPUT);
}
void pumpOn() {
  digitalWrite(Pump, HIGH);
}
void pumpOff() {
  digitalWrite(Pump, LOW);
}


