#include <simpleRPC.h>
#include "conf.h"
#include "humidityControl.h"
#include "arduino.h"
#include "movingmotor.h"
#include "motorPignon.h"

void setup(void){
  Serial.begin(9600);
  /* init capteur humidité*/
  initHumiditySensor(SENSE);
  /*init pompe*/
  initPump();
  /* init moteurs deplacement*/
  initmovingMotor();
  /* init moteurs pignon et capteurs fin de course*/
  initMotorPignon();

}

unsigned long time(void) {
  return millis();
}

int read_Analog(int pin){
  int value;
  value = digitalRead(pin);
  return value;
}

void setPin(int pin, int value) {
  digitalWrite(pin, value);
}

void loop(void) {
  interface(
    read_Analog, "read_analog: Return analog. @a: Pin. @return: analog value.",
    pignonStop, "pignon_stop: Stop the pignon.",
    pignonUp, "pignon_up: Upward.",
    pignonDown, "pignon_down: Upward.",
    movingForward, "moving_forward: get Forward",
    movingStop, "moving_stop: Stop the motor.",
    movingBack, "moving_back: Get back.",
    setPin, "set_pin: set value to pin. @pin: set the pin. @value: set the value.",
    time, "time: Report the system time. @return: System time.");  

}


