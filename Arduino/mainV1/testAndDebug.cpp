#include "arduino.h"
#include "testAndDebug.h"
#define DEBUG

void testDebug_init() {
#ifdef DEBUG
  Serial.begin(9600);
#endif
}

void testDebug_printInt(int mess) {
#ifdef DEBUG
  Serial.println(mess);
#endif
}


void testDebug_print(char* mess) {
#ifdef DEBUG
  Serial.println(mess);
#endif
}

unsigned long test_time(void) {
  return millis();
}

int test_read_Analog(int pin) {
  int value;
  value = digitalRead(pin);
  return value;
}

void test_setPin(int pin, int value) {
  digitalWrite(pin, value);
}

