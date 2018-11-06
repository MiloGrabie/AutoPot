#include "conf.h"
#include "arduino.h"
#include "movingmotor.h"
// definier des manoeuvres complexes (demitour,...)
// int tempsManoeuvre[MAN_NB] = {2000, 2800, 1600, 4500, 1400, 400};
// int definitionManoeuvre[MAN_NB][2] = {{ARRIERE, ARRET}, {AVANT, AVANT}, {AVANT, ARRET}, {AVANT, AVANT}, {AVANT, ARRET}, {AVANT, AVANT}};
void initMotor() {
  pinMode(motorDeplacement1Front, OUTPUT);
  pinMode(motorDeplacement1Back, OUTPUT);
  pinMode(motorDeplacement2Front, OUTPUT);
  pinMode(motorDeplacement2Back, OUTPUT);


}
void movingForward () {
  digitalWrite(motorDeplacement1Front, HIGH) ;
  digitalWrite(motorDeplacement2Front, HIGH);
  digitalWrite(motorDeplacement1Back, LOW);
  digitalWrite(motorDeplacement2Back, HIGH);
}
void  movingBack () {
  digitalWrite(motorDeplacement1Front, LOW) ;
  digitalWrite(motorDeplacement2Front, LOW);
  digitalWrite(motorDeplacement1Back, HIGH);
  digitalWrite(motorDeplacement2Back, HIGH);

}

void movingStop () {
  digitalWrite(motorDeplacement1Front, LOW) ;
  digitalWrite(motorDeplacement2Front, LOW);
  digitalWrite(motorDeplacement1Back, LOW);
  digitalWrite(motorDeplacement2Back, LOW) ;
}

void movingTurnRight () {
  digitalWrite(motorDeplacement1Front, LOW) ;
  digitalWrite(motorDeplacement2Front, HIGH);
  digitalWrite(motorDeplacement1Back, LOW);
  digitalWrite(motorDeplacement2Back, LOW) ;
}

void movingTurnLeft () {
  digitalWrite(motorDeplacement1Front, HIGH) ;
  digitalWrite(motorDeplacement2Front, LOW);
  digitalWrite(motorDeplacement1Back, LOW);
  digitalWrite(motorDeplacement2Back, LOW) ;
}



