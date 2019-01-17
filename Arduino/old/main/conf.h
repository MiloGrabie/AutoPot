
#include "arduino.h"
#define rxPin 19 // Broche 19 en tant que RX, ÃƒÂ  raccorder sur TX du HC-05
#define txPin 18 // Broche 18 en tant que TX, ÃƒÂ  raccorder sur RX du HC-05
#define motorPignonUp 23
#define motorPignonDown 24
#define motorLeftFront 40
#define motorLeftBack 39
#define motorRightFront 29
#define motorRightBack 30
#define Pump 22
#define SENSE A1 // Soil Sensor input at Analog PIN A1
#define buttonpin1 48 // Variable buttonpin = connected to digital line 47, this is where the VMA327 output has to be connected for this test
#define buttonpin2 47 // Variable buttonpin = connected to digital line 48, this is where the VMA327 output has to be connected for this test

// définition des messages bluetooth
#define MARCHE 0
#define ARRET 1
#define DUREE 2
//definition des types de manoeuvres
//#define AVANT 1
//#define ARRIERE -1
//#define ARRET 0
//#define MAN_RECUL_1 0;
//#define MAN_AVANCE_1 1;
//#define MAN_RECUL_2 2;
//#define MAN_AVANCE_2 3;
//#define MAN_NB 4] ;
