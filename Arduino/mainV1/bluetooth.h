// definition des PINs utilisées
#define BL_RX_PIN 15 //19 // Broche 19 en tant que RX, ÃƒÂ  raccorder sur TX du HC-05
#define BL_TX_PIN 14 //18 // Broche 18 en tant que TX, ÃƒÂ  raccorder sur RX du HC-05

// définition des messages bluetooth
#define BL_MARCHE 144
#define BL_ARRET 128
#define BL_DUREE 2
#define BL_TIMEOUT_ACK 500
#define BL_TIME_MIN_BETWEEN_2_SERIALS 50 //laisse un peu de temps entre 2 communications série pour que le téléphone ne mélange pas
#define BL_TIME_MIN_BETWEEN_2_ON_OFF 1000 //temps entre l'envoie de l'état ON/OFF
#define _ACK_ 'Z'
// definition des Erreurs renvoyées
#define BL_OK 50
#define BL_ERR_NO_PARAMETER 51
#define BL_ERR_NO_MESSAGE 52
void BL_init();
char BL_getMessageType(int* type);
char BL_getMessageContent(int type, char* Content);
void BL_sendStateOnOff(boolean onOff);
void BL_sendData(void);
