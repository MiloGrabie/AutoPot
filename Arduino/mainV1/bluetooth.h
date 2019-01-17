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
