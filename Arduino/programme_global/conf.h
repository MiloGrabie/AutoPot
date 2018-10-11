#define rxPin 19 // Broche 19 en tant que RX, Ã  raccorder sur TX du HC-05
#define txPin 18 // Broche 18 en tant que TX, Ã  raccorder sur RX du HC-05
#define motorPignonFront 23
#define motorPignonBack 24
#define motorDeplacement1Front 37
#define motorDeplacement1Back 38
#define motorDeplacement2Front 29
#define motorDeplacement2Back 30
#define pump 22
#define sense A1 // Soil Sensor input at Analog PIN A1
#define buttonpin1 47 // Variable buttonpin = connected to digital line 47, this is where the VMA327 output has to be connected for this test
#define buttonpin2 48 // Variable buttonpin = connected to digital line 48, this is where the VMA327 output has to be connected for this test
//movingmotor
void movingForward ();
void movingBack () ;
void movingStop () ;
void movingTurnRight ();
void movingTurnLeft ();
//motorPignon
void pignonUp ();
void pignonBack ();
void pignonStop ();


