#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void getPath(char logFile[20], char confFile[20], char config[255], char logos[255]){
    char buf[100];
    getcwd(buf,100);

    //config with path
    strcpy(config, buf);
    strcat(config, "/");
    strcat(config, confFile);

    //logo with path
    strcpy(logos, buf);
    strcat(logos, "/");
    strcat(logos, logFile);


}