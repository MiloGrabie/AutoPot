
#define BL_OK 0
#define BL_ERR_NO_PARAMETER 1
#define BL_ERR_NO_MESSAGE 2
void initBluetooth();
char getMessageType(char* type);
char getMessageContent(char type,char* Content);
