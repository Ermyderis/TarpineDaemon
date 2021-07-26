int createConfigFile(char *fileConfig);
int createLogFile(char *fileLog);
void daemonCreated();
void reading(char config[256], char line[1000], int linenum, char aud[50], char audthird[50], char vid[50], char vidthird[50], char pho[50], char phothird[50], char doc[50], char dochird[50], char diwatch[50], char diwatchthird[50], char typwatch[50], char typwatchthird[50]);
void getPath(char logFile[20], char confFile[20], char config[255], char logos[255]);
void createDirection(char logos[255], char videoMoveto[500], char photosMoveto[500], char musicMoveto[500], char documentsMoveto[500]);
void listFilesRecursively(char logos[255], char *basePath);
