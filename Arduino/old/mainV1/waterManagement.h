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

