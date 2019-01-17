#include "arduino.h"
#include "moveRobot.h"


// paramètres utilisés
static int tempsDemarrageManoeuvreEnCours;
static int dureeManoeuvreEnCours;
static int state = MR_STATE_MOVE_ENDED;
static boolean mr_moveAuthorized;

void MR_init() {
  pinMode(MR_MOTOR_LEFT_FRONT, OUTPUT);
  pinMode(MR_MOTOR_LEFT_BACK, OUTPUT);
  pinMode(MR_MOTOR_RIGHT_FRONT, OUTPUT);
  pinMode(MR_MOTOR_RIGHT_BACK, OUTPUT);
  digitalWrite(MR_MOTOR_LEFT_FRONT, LOW);
  digitalWrite(MR_MOTOR_LEFT_BACK, LOW);
  digitalWrite(MR_MOTOR_RIGHT_FRONT, LOW);
  digitalWrite(MR_MOTOR_RIGHT_BACK, LOW);
  state = MR_STATE_MOVE_ENDED;
}
void MR_authorization(boolean p_authorization){
  mr_moveAuthorized = p_authorization;
}

int MR_wheelStartMove(int leftWheelMove, int rigthtWheelMove, int moveDuration) {

  if ((leftWheelMove == MR_STOP) && (rigthtWheelMove == MR_STOP)) { // permet de stopper un mouvement en cours (par exmepl arrêt d'urgence)
    state = MR_STATE_MOVE_ENDED;
  }
  if (mr_moveAuthorized) {
    if (state == MR_STATE_MOVE_ENDED) {
      dureeManoeuvreEnCours = moveDuration;
      state = MR_STATE_MOVE_ONGOING;
      tempsDemarrageManoeuvreEnCours = millis();
      switch (leftWheelMove) {
        case MR_FRONT:
          digitalWrite(MR_MOTOR_LEFT_FRONT, HIGH);
          digitalWrite(MR_MOTOR_LEFT_BACK, LOW);
          break;
        case MR_BACK:
          digitalWrite(MR_MOTOR_LEFT_FRONT, LOW);
          digitalWrite(MR_MOTOR_LEFT_BACK, HIGH);
          break;
        case MR_STOP:
          digitalWrite(MR_MOTOR_LEFT_FRONT, LOW);
          digitalWrite(MR_MOTOR_LEFT_BACK, LOW);
          break;
      }

      switch (rigthtWheelMove) {
        case MR_FRONT:
          digitalWrite(MR_MOTOR_RIGHT_FRONT, HIGH);
          digitalWrite(MR_MOTOR_RIGHT_BACK, LOW);
          break;
        case MR_BACK:
          digitalWrite(MR_MOTOR_RIGHT_FRONT, LOW);
          digitalWrite(MR_MOTOR_RIGHT_BACK, HIGH);
          break;
        case MR_STOP:
          digitalWrite(MR_MOTOR_RIGHT_FRONT, LOW);
          digitalWrite(MR_MOTOR_RIGHT_BACK, LOW);
          break;
      }
      if ((leftWheelMove == MR_STOP) && (rigthtWheelMove == MR_STOP)) { // permet de stopper un mouvement en cours (par exemple arrêt d'urgence)
        dureeManoeuvreEnCours = 0;
        state = MR_STATE_MOVE_ENDED;
      }
      return (MR_ERR_OK);
    } else {
      return (MR_ERR_MOVE_ALREADY_ONGOING);
    }
  }
  else {
    return (MR_ERR_MOVE_NOT_AUTHORIZED);
  }
}

void MR_wheelMoveManagement() {
  int tempsCourant;
  tempsCourant = millis();
  if ((tempsCourant - tempsDemarrageManoeuvreEnCours) > dureeManoeuvreEnCours) {
    MR_wheelStartMove(MR_STOP, MR_STOP, 0);
  }
}

int MR_wheelMoveStatus() {
  return (state);
}



