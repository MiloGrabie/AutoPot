#include "conf.h"
#include "arduino.h"
static boolean vpignonUp = false;
static boolean vpignonDown = false;

boolean isPignonUp() {
  return(vpignonUp);
}

boolean isPignonDown() {
    return(vpignonDown);
}

void pignonDown ()  {
  digitalWrite (motorPignonDown, HIGH);
  digitalWrite (motorPignonUp, LOW) ;
  vpignonDown = true;
}
void pignonUp ()  {
  digitalWrite (motorPignonUp, HIGH);
  digitalWrite (motorPignonDown, LOW) ;
  vpignonUp = true;
}
void pignonStop ()  {
  digitalWrite (motorPignonUp, LOW);
  digitalWrite (motorPignonDown, LOW);
  vpignonDown = false;
  vpignonUp=false;
}



