#include "arduino.h"
// definition des PINs utilisées
#define MR_MOTOR_LEFT_FRONT 37
#define MR_MOTOR_LEFT_BACK 38
#define MR_MOTOR_RIGHT_FRONT 29
#define MR_MOTOR_RIGHT_BACK 30
// definition des types de mouvements
#define MR_BACK -1
#define MR_STOP 0
#define MR_FRONT 1
// definition du status du dernier mouvement démarré
#define MR_STATE_MOVE_ONGOING 1
#define MR_STATE_MOVE_ENDED 2
// definition des Erreurs renvoyées
#define MR_ERR_OK 1
#define MR_ERR_MOVE_ALREADY_ONGOING 2
#define MR_ERR_MOVE_NOT_AUTHORIZED 3


void MR_init();
void MR_authorization(boolean p_authorization);
int MR_wheelStartMove(int leftWheelMove,int rigthtWheelMove,int moveDuration); // renvoie MR_ERR_MOVE ALREADY_ONGOING ou MR_ERR_OK
void MR_wheelMoveManagement();
int MR_wheelMoveStatus(); //renvoie MR_STATE_MOVE_ONGOING ou MR_STATE_MOVE_ENDED





