#include "conf.h"
#include "arduino.h"
#include "motorPignon.h"
static boolean etatfindecourseUp = false;
static boolean etatfindecourseDown = false;


void initCapteursfindecourse() { // appelee dans initMotorPignon()
  pinMode(buttonpin1, INPUT); // declare buttonpin (digital 48) as input (capteur1)
  pinMode(buttonpin2, INPUT); // declare buttonpin (digital 47) as input (capteur2)
  //retrouver le code pour les capteurs fin de course et la notice sur : https://www.lextronic.fr/io-compatible-arduino/31650-module-interrupteur-fin-de-course-2-pcs-5410329680794.html
}
int valuefindecourseUp;
int valuefindecourseDown;

boolean isPignonUp() {
  return(etatfindecourseUp);
}
boolean isPignonDown() {
    return(etatfindecourseDown);
}

void findecourseUp() {
  valuefindecourseUp = digitalRead(buttonpin1); // read the value of buttonpin (digital 48)
  if (valuefindecourseUp == HIGH)
  { (etatfindecourseUp = true);
  }
}

void findecourseDown() {
  valuefindecourseDown = digitalRead(buttonpin2); // read the value of buttonpin (digital 47)
  if (valuefindecourseDown == HIGH)
  { (etatfindecourseDown = true);
  }
}

void initMotorPignon() {
  pinMode(motorPignonUp, OUTPUT);
  pinMode(motorPignonDown, OUTPUT);
  initCapteursfindecourse();
}

char pignonDown ()  {
  etatfindecourseUp=false;
  if (!etatfindecourseDown) {
    digitalWrite (motorPignonDown, HIGH);
  digitalWrite (motorPignonUp, LOW) ;
  do {
    findecourseDown();
  } while (!etatfindecourseDown);
     pignonStop ();
  return(PI_OK);
  } else return(PI_ERR_PIGNON_DEJA_EN_BAS);
}

char pignonUp ()  {
  etatfindecourseDown=false;
  if (!etatfindecourseUp) {
    digitalWrite (motorPignonUp, HIGH);
    digitalWrite (motorPignonDown, LOW) ;
     do {
    findecourseUp();
  } while (!etatfindecourseUp);
     pignonStop();
  return(PI_OK);
  } else return(PI_ERR_PIGNON_DEJA_EN_HAUT);
}

void pignonStop ()  {
  digitalWrite (motorPignonUp, LOW);
  digitalWrite (motorPignonDown, LOW);

}




