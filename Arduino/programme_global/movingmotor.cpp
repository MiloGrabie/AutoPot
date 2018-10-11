#include "conf.h"
#include "arduino.h"
void movingForward () {
  digitalWrite(motorDeplacement1Front, HIGH) ;
  digitalWrite(motorDeplacement2Front, HIGH);
  digitalWrite(motorDeplacement1Back, LOW);
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


