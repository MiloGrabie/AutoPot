#include "arduino.h"
#include "arduino.h"
#include "moveSensor.h"

static boolean etatfindecourseUp = false;
static boolean etatfindecourseDown = false;
static int MS_sensorMoveState = MS_SENSOR_MOVE_STOP;

boolean MS_testSensorIsUp() {
  int valuefindecourseUp;
  boolean ret = false;
  valuefindecourseUp = digitalRead(MS_SENSOR_UP_TEST_PIN); // read the value of buttonpin (digital 48)
  if (valuefindecourseUp == HIGH) ret = true;
  return (ret);
}

boolean MS_testSensorIsDown() {
  int valuefindecourseDown;
  boolean ret = false;
  valuefindecourseDown = digitalRead(MS_SENSOR_DOWN_TEST_PIN); // read the value of buttonpin (digital 47)
  if (valuefindecourseDown == HIGH) ret = true;
  return (ret);
}

void MS_initSensorMove() {
  MS_sensorMoveState = MS_SENSOR_MOVE_STOP;
  //sorties moteur
  pinMode(MS_MOTOR_UP_PIN, OUTPUT);
  pinMode(MS_MOTOR_DOWN_PIN, OUTPUT);
  //capteurs fin de course
  pinMode(MS_SENSOR_UP_TEST_PIN, INPUT); // declare buttonpin (digital 48) as input (capteur1)
  pinMode(MS_SENSOR_DOWN_TEST_PIN, INPUT); // declare buttonpin (digital 47) as input (capteur2)
  // a l'initialisation on remonte systématiquement le capteur
  if (!MS_testSensorIsUp()) {
    digitalWrite (MS_MOTOR_UP_PIN, HIGH);
    digitalWrite (MS_MOTOR_DOWN_PIN, LOW) ;
  }
  do {} while (!MS_testSensorIsUp());
  digitalWrite (MS_MOTOR_UP_PIN, LOW);
  digitalWrite (MS_MOTOR_DOWN_PIN, LOW) ;
}

int MS_giveSensorMove() {
  return (MS_sensorMoveState);
}

int MS_sensorMove(int sensorMove) {
  switch (sensorMove) {
    case MS_SENSOR_MOVE_DOWN:
      if (!etatfindecourseDown) {
        digitalWrite (MS_MOTOR_DOWN_PIN, HIGH);
        digitalWrite (MS_MOTOR_UP_PIN, LOW) ;
        MS_sensorMoveState = MS_SENSOR_MOVE_DOWN;
        return (MS_ERR_OK);
      } else return (MS_ERR_SENSOR_ALREADY_DOWN);
      break;
    case MS_SENSOR_MOVE_UP:
      if (!etatfindecourseUp) {
        digitalWrite (MS_MOTOR_UP_PIN, HIGH);
        digitalWrite (MS_MOTOR_DOWN_PIN, LOW) ;
        MS_sensorMoveState = MS_SENSOR_MOVE_UP;
        return (MS_ERR_OK);
      }
      else return (MS_ERR_SENSOR_ALREADY_UP);
      break;
    case MS_SENSOR_MOVE_STOP:
      digitalWrite (MS_MOTOR_UP_PIN, LOW);
      digitalWrite (MS_MOTOR_DOWN_PIN, LOW);
      MS_sensorMoveState = MS_SENSOR_MOVE_STOP;
      return (MS_ERR_OK);
      break;
  }
  return (MS_ERR_OK);
}

void MS_sensorMoveManagement() {
  if (MS_sensorMoveState == MS_SENSOR_MOVE_UP) {
    if (MS_testSensorIsUp()) {
      MS_sensorMove (MS_SENSOR_MOVE_STOP);
    }
  }
  if (MS_sensorMoveState == MS_SENSOR_MOVE_DOWN) {
    if (MS_testSensorIsDown()) {
      MS_sensorMove (MS_SENSOR_MOVE_STOP);
    }
  }
}



