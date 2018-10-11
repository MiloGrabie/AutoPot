#include "conf.h"
#include "arduino.h"

void pignonDown ()  {
  digitalWrite (motorPignonFront, HIGH);
  digitalWrite (motorPignonBack, LOW) ;
}
void pignonUp ()  {
  digitalWrite (motorPignonFront, LOW);
  digitalWrite (motorPignonBack, HIGH);
}
void pignonStop ()  {
  digitalWrite (motorPignonFront, LOW);
  digitalWrite (motorPignonBack, LOW);
}


