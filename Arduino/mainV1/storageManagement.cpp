#include "arduino.h"
#include "storeManagement.h"

static typeMemoire memoire;

int SM_store(int p_position, int p_humidity, int p_wateringDuration) {
  int index = memoire.debut + memoire.nbElem;
  if (memoire.nbElem < SM_NB_ELEM_MEMOIRE) {
    memoire.elem[(index) % SM_NB_ELEM_MEMOIRE].id = p_position;
    memoire.elem[(index) % SM_NB_ELEM_MEMOIRE].humidity = p_humidity;
    memoire.elem[(index) % SM_NB_ELEM_MEMOIRE].waterigDuration = p_wateringDuration;
    memoire.nbElem++;
  } else return (SM_ERR_NO_SPACE_LEFT);
}


boolean SM_dataLeft(void) {
  if (memoire.nbElem != 0) return (true); else return (false);
}

elemStruct SM_getNextElem(void) {
  elemStruct element = memoire.elem[memoire.debut];
  memoire.debut = (memoire.debut + 1) % SM_NB_ELEM_MEMOIRE;
  memoire.nbElem--;
  return (element);
}

