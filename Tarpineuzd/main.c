#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "libFile.h"

int main(void){
    char logFile[20] = "log.txt";
    char confFile[20] = "config.txt";
	createLogFile(logFile);
	createConfigFile(confFile);
    char config[255] = "";
    char logos[255] = "";
    getPath(logFile, confFile, config, logos);


	daemonCreated();

	FILE *fp= NULL;
    int i = 0;
    fp = fopen (logos, "a");
	time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
  	fprintf(fp, "\nDaemon started : %s\n",  asctime (timeinfo) );
    fclose(fp);

    while (i < 4)
    {
    char line[1000] = "";
    int linenum = 0;
    char aud[50] = "";
    char audthird[50] = "";
    char vid[50]= "";
    char vidthird[50]= "";
    char pho[50]= "";
    char phothird[50]= "";
    char doc[50]= "";
    char dochird[50]= "";
    char diwatch[50]= "";
    char diwatchthird[50]= "";
    char typwatch[50]= "";
    char typwatchthird[50]= "";

        fp = fopen (logos, "a");
        fprintf(fp, "\n");
        fflush(fp);
        sleep(5);
        fprintf(fp, "%d", i);
        fflush(fp);
        i++;
    //geting values from config
    reading(config, line, linenum, aud, audthird, vid, vidthird, pho, phothird, doc, dochird, diwatch, diwatchthird, typwatch, typwatchthird);


    fprintf(fp, "\n%s = %s \n%s = %s \n%s = %s", aud, audthird, vid, vidthird, pho, phothird);
    fprintf(fp, "\n%s = %s", doc, dochird);
    fprintf(fp, "\n%s = %s", typwatch, typwatchthird);
    fprintf(fp, "\n%s = %s", diwatch, diwatchthird);

    //compare strings
    char *pos;
    pos = strstr(aud, "audio");

    if(pos != NULL){
        fprintf(fp, "\nAudio: %s\n", audthird);
    }
    pos = strstr(pho, "photo");
    if(pos != NULL){
        fprintf(fp, "\nPhoto: %s\n", phothird);
    }

        fclose(fp);

        //while ens
    }
    
    fp = fopen (logos, "a");
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
  	fprintf(fp, "\nDaemon stoped : %s\n",  asctime (timeinfo) );
    fclose(fp);
    return (0);
}
