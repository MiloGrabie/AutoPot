#include "conf.h"
#include "arduino.h"
#include "motorPignon.h"
static boolean vpignonUp = false;
static boolean vpignonDown = false;
static boolean etatfindecourse1 = false;
static boolean etatfindecourse2 = false;

boolean isPignonUp() {
  return (vpignonUp);
}

boolean isPignonDown() {
  return (vpignonDown);
}

boolean findecourse1on() {
  return (etatfindecourse1);
}
boolean findecourse2on() {
  return (etatfindecourse2);
}
void initCapteursfindecourse() {
  pinMode(buttonpin1, INPUT); // declare buttonpin (digital 48) as input (capteur1)
  pinMode(buttonpin2, INPUT); // declare buttonpin (digital 47) as input (capteur2)
  //retrouver le code pour les capteurs fin de course et la notice sur : https://www.lextronic.fr/io-compatible-arduino/31650-module-interrupteur-fin-de-course-2-pcs-5410329680794.html
}
int valuefindecourse1;
int valuefindecourse2;


void findecourse1() {
  valuefindecourse1 = digitalRead(buttonpin1); // read the value of buttonpin (digital 48)
  if (valuefindecourse1 == HIGH)
  { (etatfindecourse1 = true);
  }
}

void findecourse2() {
  valuefindecourse2 = digitalRead(buttonpin2); // read the value of buttonpin (digital 47)
  if (valuefindecourse2 == HIGH)
  { (etatfindecourse2 = true);
  }
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



