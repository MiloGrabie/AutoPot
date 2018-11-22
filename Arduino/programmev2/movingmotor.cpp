#include "conf.h"
#include "arduino.h"
#include "movingmotor.h"
// definier des manoeuvres complexes (demi-tour,...)
#define MAN_NB_MAX_ETAT_MANOEUVRE 20
#define NB_ETATS_MANOEUVRE_LEFT_UTURN 4
#define NB_ETATS_MANOEUVRE_RIGHT_UTURN 4

// paramètres pour une manoeuvre de demi tour à gauche
static int tempsManoeuvreLeftUTurn[NB_ETATS_MANOEUVRE_LEFT_UTURN] = {2000, 2000, 2000, 2000};
static int definitionManoeuvreLeftUTurn[NB_ETATS_MANOEUVRE_LEFT_UTURN][2] = {{ARRIERE, ARRET}, {ARRET, AVANT}, {ARRIERE, ARRET}, {ARRET, AVANT}};

// paramètres pour une manoeuvre de demi tour à droite
static int tempsManoeuvreRightUTurn[NB_ETATS_MANOEUVRE_RIGHT_UTURN] = {2000, 2000, 2000, 2000};
static int definitionManoeuvreRigthUTurn[NB_ETATS_MANOEUVRE_RIGHT_UTURN][2] = {{ARRET, ARRIERE}, {AVANT, ARRET}, {ARRET, ARRIERE}, {AVANT, ARRET}};


// paramètres utilisés pour gérer une manoeuvre
static int * tempsManoeuvre;
static int definitionManoeuvre[MAN_NB_MAX_ETAT_MANOEUVRE][2];
static int nbEtatsManoeuvre = 0;
static int noEtatManoeuvre = 0;
static int tempsDemarrageEtatManoeuvreEnCours;



void initmovingMotor() {
  pinMode(motorLeftFront, OUTPUT);
  pinMode(motorLeftBack, OUTPUT);
  pinMode(motorRightFront, OUTPUT);
  pinMode(motorRightBack, OUTPUT);
}

void movingForward () {
  if (nbEtatsManoeuvre == 0) {
    digitalWrite(motorLeftFront, HIGH) ;
    digitalWrite(motorRightFront, HIGH);
    digitalWrite(motorLeftBack, LOW);
    digitalWrite(motorRightBack, LOW);
  }
}

void  movingBack () {
  if (nbEtatsManoeuvre == 0) {
    digitalWrite(motorLeftFront, LOW) ;
    digitalWrite(motorRightFront, LOW);
    digitalWrite(motorLeftBack, HIGH);
    digitalWrite(motorRightBack, HIGH);
  }
}

void movingStop () {
  if (nbEtatsManoeuvre == 0) {
    digitalWrite(motorLeftFront, LOW) ;
    digitalWrite(motorRightFront, LOW);
    digitalWrite(motorLeftBack, LOW);
    digitalWrite(motorRightBack, LOW) ;
  }
}

void movingTurnRight () {
  if (nbEtatsManoeuvre == 0) {
    digitalWrite(motorLeftFront, HIGH) ;
    digitalWrite(motorRightFront, LOW);
    digitalWrite(motorLeftBack, LOW);
    digitalWrite(motorRightBack, LOW) ;
  }
}

void movingTurnLeft () {
  if (nbEtatsManoeuvre == 0) {
    digitalWrite(motorLeftFront, LOW) ;
    digitalWrite(motorRightFront, HIGH);
    digitalWrite(motorLeftBack, LOW);
    digitalWrite(motorRightBack, LOW) ;
  }
}

void affecteManoeuvreCourante(int p[MAN_NB_MAX_ETAT_MANOEUVRE][2], int p_nbEtatsManoeuvre) {
  for (int i = 0; i < p_nbEtatsManoeuvre; i++)
    for (int j = 0; j < 2; j++)
      definitionManoeuvre[i][j] = p[i][j];
}

void movingManoeuvreRigthUTurn(boolean *manoeuvreRunning) {
  if (nbEtatsManoeuvre != 0) { // pas de manoeuvre en cours
    tempsManoeuvre = tempsManoeuvreRightUTurn;
    affecteManoeuvreCourante(definitionManoeuvreRigthUTurn, NB_ETATS_MANOEUVRE_RIGHT_UTURN);
    nbEtatsManoeuvre = NB_ETATS_MANOEUVRE_RIGHT_UTURN;
    noEtatManoeuvre = 0;
    tempsDemarrageEtatManoeuvreEnCours = millis();
    *manoeuvreRunning=true;
  }
}

void movingManoeuvreLeftUTurn (boolean *manoeuvreRunning) {
  if (nbEtatsManoeuvre != 0) { // pas de manoeuvre en cours
    tempsManoeuvre = tempsManoeuvreLeftUTurn;
    affecteManoeuvreCourante(definitionManoeuvreLeftUTurn, NB_ETATS_MANOEUVRE_LEFT_UTURN);
    nbEtatsManoeuvre = NB_ETATS_MANOEUVRE_LEFT_UTURN;
    noEtatManoeuvre = 0;
    tempsDemarrageEtatManoeuvreEnCours = millis();
    *manoeuvreRunning=true;
  }
}

void movingManoeuvreControl(boolean *manoeuvreRunning) {
  int tempsCourant;
  if (nbEtatsManoeuvre != 0) { // une manoeuvre est en cours
    tempsCourant = millis();
    if ((tempsCourant - tempsDemarrageEtatManoeuvreEnCours) > tempsManoeuvre[noEtatManoeuvre]) {
      noEtatManoeuvre++;
      tempsDemarrageEtatManoeuvreEnCours = tempsCourant;
      if (noEtatManoeuvre == nbEtatsManoeuvre) {  //la manoeuvre est terminée
        nbEtatsManoeuvre = 0;
        digitalWrite(motorLeftBack, LOW);
        digitalWrite(motorRightBack, LOW) ;
        *manoeuvreRunning=false;
      }
    }
  }
  if (nbEtatsManoeuvre != 0) {
    switch (definitionManoeuvre[noEtatManoeuvre][0]) {
      case AVANT:
        digitalWrite(motorLeftFront, HIGH);
        digitalWrite(motorLeftBack, LOW);
        break;
      case ARRIERE:
        digitalWrite(motorLeftFront, LOW);
        digitalWrite(motorLeftBack, HIGH);
        break;
      case STOP:
        digitalWrite(motorLeftFront, LOW);
        digitalWrite(motorLeftBack, LOW);
        break;
        default:break;
    }
    switch (definitionManoeuvre[noEtatManoeuvre][1]) {
      case AVANT:
        digitalWrite(motorRightFront, HIGH);
        digitalWrite(motorRightBack, LOW);
        break;
      case ARRIERE:
        digitalWrite(motorRightFront, LOW);
        digitalWrite(motorRightBack, HIGH);
        break;
      case STOP:
        digitalWrite(motorRightFront, LOW);
        digitalWrite(motorRightBack, LOW);
        break;
         default:break;
    }
  }
}




