#include "conf.h"
#include "arduino.h"
#define ARRIERE -1
#define STOP 0
#define AVANT 1

void initmovingMotor();
void movingManoeuvreLeftUTurn(boolean *manoeuvreRunning);
void movingManoeuvreRigthUTurn(boolean *manoeuvreRunning);
void movingManoeuvreControl(boolean *manoeuvreRunning);


void movingForward ();
void movingBack ();
void movingStop ();
void movingTurnRight();
void movingTurnLeft();


