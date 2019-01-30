// definition des PINs utilisées
#define BL_RX_PIN 15 //19 // Broche 19 en tant que RX, ÃƒÂ  raccorder sur TX du HC-05
#define BL_TX_PIN 14 //18 // Broche 18 en tant que TX, ÃƒÂ  raccorder sur RX du HC-05

// définition des messages bluetooth
#define BL_MARCHE 144
#define BL_ARRET 128
#define BL_DUREE 2

// definition des Erreurs renvoyées
#define BL_OK 50
#define BL_ERR_NO_PARAMETER 51
#define BL_ERR_NO_MESSAGE 52
void BL_init();
char BL_getMessageType(int* type);
char BL_getMessageContent(int type, char* Content);
void BL_write(char* mess);
void BL_sendStateOnOff(boolean onOff);

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

// definition des PINs utilisées
#define MS_MOTOR_UP_PIN 23
#define MS_MOTOR_DOWN_PIN 24
#define MS_SENSOR_UP_TEST_PIN 48 
#define MS_SENSOR_DOWN_TEST_PIN 47 

// definition des Erreurs renvoyées
#define MS_ERR_OK 10
#define MS_ERR_SENSOR_ALREADY_UP 11
#define MS_ERR_SENSOR_ALREADY_DOWN 12

// definition des types de mouvements
#define MS_SENSOR_MOVE_DOWN 1
#define MS_SENSOR_MOVE_UP 2
#define MS_SENSOR_MOVE_STOP 3

void MS_initSensorMove();
int MS_sensorMove(int sensorMove);
void MS_sensorMoveManagement();
int MS_giveSensorMove(); // renvoie un type de mouvement

// definition des PINs utilisées
#define MS_PUMP_PIN 22
#define MS_SENSOR_PIN A1 
// definition des états de l'arrosage
#define WM_STATUS_SENSOR_GOING_DOWN 1
#define WM_STATUS_SENSOR_PAUSE_BEFORE_MEASURE 2
#define WM_STATUS_SENSOR_MEASURE 3
#define WM_STATUS_SENSOR_PAUSE_AFTER_MEASURE 4
#define WM_STATUS_SENSOR_GOING_UP 5
#define WM_STATUS_WATERING_ON 6
#define WM_STATUS_WATERING_ENDED 7
#define WM_WATERING_DURATION_DEFAULT 3000   /* en millisecondes*/
#define WM_SENSOR_PAUSE_TIME_BEFORE_MEASURE 1000
#define WM_SENSOR_PAUSE_TIME_AFTER_MEASURE 1000
// definition des Erreurs renvoyées
#define WM_ERR_OK 100
#define WM_ERR_MEASURE_AND_WATERING_ALREADY_ONGOING 101
#define WM_ERR_WATERING_NOT_AUTHORIZED 102
void WM_init();
void WM_authorization(boolean p_authorization);
int WM_startMeasureAndWatering(void);
int WM_measureAndWateringManagement(void);
int WM_getMeasureAndWateringStatus(void);
// definition des Erreurs renvoyées
#define SM_OK 200
#define SM_ERR_NO_SPACE_LEFT 201
#define SM_NB_ELEM_MEMOIRE 200


typedef struct{
  int pos;
  int humidity;
  int waterigDuration;
}elemStruct;

typedef struct{
  int debut = 0;
  int nbElem = 0;
  elemStruct elem[SM_NB_ELEM_MEMOIRE];
}typeMemoire;

int SM_store(int p_position,int p_humidity,int p_wateringDuration);



