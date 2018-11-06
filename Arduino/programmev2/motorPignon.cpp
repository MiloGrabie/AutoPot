#include "conf.h"
#include "arduino.h"
#include "motorPignon.h"
static boolean vpignonUp = false;
static boolean vpignonDown = false;

boolean isPignonUp() {
  return (vpignonUp);
}

boolean isPignonDown() {
  return (vpignonDown);
}

void initCapteurfindecourse() {
   pinMode(buttonpin1, INPUT); // declare buttonpin (digital 47) as input (capteur1)
   pinMode(buttonpin2, INPUT); // declare buttonpin (digital 48) as input (capteur2)
   //retrouver le code pour les capteurs fin de course et la notice sur : https://www.lextronic.fr/io-compatible-arduino/31650-module-interrupteur-fin-de-course-2-pcs-5410329680794.html
}
void initMotorPignon() {  
   pinMode(motorPignonUp, OUTPUT);
   pinMode(motorPignonDown, OUTPUT);
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
  vpignonUp = false;
}



