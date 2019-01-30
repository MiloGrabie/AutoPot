// definition des Erreurs renvoyées
#define SM_OK 200
#define SM_ERR_NO_SPACE_LEFT 201
#define SM_NB_ELEM_MEMOIRE 1000


typedef struct{
  int id;
  int humidity;
  int waterigDuration;
}elemStruct;

typedef struct{
  int debut = 0;
  int nbElem = 0;
  elemStruct elem[SM_NB_ELEM_MEMOIRE];
}typeMemoire;

int SM_store(int p_position,int p_humidity,int p_wateringDuration);
boolean SM_dataLeft(void);
elemStruct SM_getNextElem(void);

