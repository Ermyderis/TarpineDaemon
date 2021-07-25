#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "libFile.h"

int main(void){
	createLogFile("log.txt");
	createConfigFile("config.txt");

    char buf[100];
    getcwd(buf,100);
    printf("%s \n",buf);
    char config[255];
    char logos[255];
    //config with path
    strcpy(config, buf);
    strcat(config, "/config.txt");
    printf(config);
    printf("\n");
    //logo with path
    strcpy(logos, buf);
    strcat(logos, "/log.txt");
    printf(logos);
    printf("\n");
    

	daemonCreated();


	FILE *fp= NULL;
    int i = 0;

    while (i < 10)
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

        fclose(fp);

        //while ens
    }
    fprintf(fp, "daemon stoped");
    return (0);
}
