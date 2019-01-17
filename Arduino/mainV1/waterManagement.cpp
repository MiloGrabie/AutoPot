#include <SoftwareSerial.h>
#include "arduino.h"
#include "moveSensor.h"
#include "waterManagement.h"

static int wm_state = WM_STATUS_WATERING_ENDED;
static int wm_humidity = 0;
static unsigned int wm_pumpStartTime = 0;
static unsigned int wm_sensorPauseBeforeMeasureStartTime = 0;
static unsigned int wm_sensorPauseAfterMeasureStartTime = 0;
static int wm_wateringDuration = 0;
boolean wm_wateringAuthorized;

void WM_initHumiditySensor() {
  pinMode(MS_SENSOR_PIN, INPUT);
}

int WM_readHumiditySensor(void) {
  int value = 0;
  value = analogRead(MS_SENSOR_PIN);
  // value = value / 10;
  return (value);
}

void WM_pumpOn() {
  digitalWrite(MS_PUMP_PIN, HIGH);
}
void WM_pumpOff() {
  digitalWrite(MS_PUMP_PIN, LOW);
}

void WM_initPump() {
  pinMode(MS_PUMP_PIN, OUTPUT);
  // a l'initialisation nous arrêtons systématiquement la pompe
  WM_pumpOff();
}
void WM_authorization(boolean p_authorization) {
wm_wateringAuthorized=p_authorization;
}

void WM_init() {
  WM_initPump();
  WM_initHumiditySensor();
  MS_initSensorMove();
}

int WM_startMeasureAndWatering(void) {
  int ret = 0;
  if (wm_wateringAuthorized) {
  if (wm_state == WM_STATUS_WATERING_ENDED) {
    wm_state = WM_STATUS_SENSOR_GOING_DOWN;
    ret = MS_sensorMove(MS_SENSOR_MOVE_DOWN);
    if (ret != MS_ERR_OK) return (ret);
    else return (WM_ERR_OK);
  } else {
    return (WM_ERR_MEASURE_AND_WATERING_ALREADY_ONGOING);
  }} else {
    return (WM_ERR_WATERING_NOT_AUTHORIZED);
  }
}

int WM_measureAndWateringManagement(void) {
  int ret = 0;
  static unsigned int currentTime = 0;
  if (wm_state != WM_STATUS_WATERING_ENDED) {
    switch (wm_state) {
      case WM_STATUS_SENSOR_GOING_DOWN:
        MS_sensorMoveManagement();
        if (MS_giveSensorMove() == MS_SENSOR_MOVE_STOP) {
          wm_sensorPauseBeforeMeasureStartTime = millis();
          wm_state = WM_STATUS_SENSOR_PAUSE_BEFORE_MEASURE;
        }
        break;
      case WM_STATUS_SENSOR_PAUSE_BEFORE_MEASURE:
        currentTime = millis();
        if ((currentTime - wm_sensorPauseBeforeMeasureStartTime) > WM_SENSOR_PAUSE_TIME_BEFORE_MEASURE)
          wm_state = WM_STATUS_SENSOR_MEASURE;
        break;
      case WM_STATUS_SENSOR_MEASURE:
        wm_humidity = WM_readHumiditySensor();
        wm_wateringDuration = WM_WATERING_DURATION_DEFAULT;
        wm_sensorPauseAfterMeasureStartTime = millis();
        wm_state = WM_STATUS_SENSOR_PAUSE_AFTER_MEASURE;
        break;
      case WM_STATUS_SENSOR_PAUSE_AFTER_MEASURE:
        currentTime = millis();
        if ((currentTime - wm_sensorPauseAfterMeasureStartTime) > WM_SENSOR_PAUSE_TIME_AFTER_MEASURE) {
          ret = MS_sensorMove(MS_SENSOR_MOVE_UP);
          if (ret != MS_ERR_OK) return (ret);
          wm_state = WM_STATUS_SENSOR_GOING_UP;
        }
        break;
      case WM_STATUS_SENSOR_GOING_UP:
        MS_sensorMoveManagement();
        if (MS_giveSensorMove() == MS_SENSOR_MOVE_STOP) {
          WM_pumpOn();
          wm_pumpStartTime = millis();
          wm_state = WM_STATUS_WATERING_ON;
        }
        break;
      case WM_STATUS_WATERING_ON:
        currentTime = millis();
        if ((currentTime - wm_pumpStartTime) > wm_wateringDuration) {
          WM_pumpOff();
          wm_state = WM_STATUS_WATERING_ENDED;
        }
        break;
    }
  }
  return (WM_ERR_OK);
}

int WM_getMeasureAndWateringStatus(void) {
  return(wm_state);
}



