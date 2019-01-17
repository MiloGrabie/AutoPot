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
