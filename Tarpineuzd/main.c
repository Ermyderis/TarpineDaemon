#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "fileCreating.h"

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
    FILE *fpc= NULL;
    int i = 0;
    fpc = fopen (config, "a");
    fprintf(fpc, "writed");
    fflush(fpc);
    fclose(fpc);

    while (i < 10)
    {
        char ch;
        fp = fopen (logos, "a");
        fprintf(fp, "\n");
        fflush(fp);
        sleep(5);
        fprintf(fp, "%d", i);
        fflush(fp);
        i++;

        fpc = fopen (config, "r");
        while((ch = fgetc(fpc)) != EOF){
            fprintf(fp, "%c", ch);
            fflush(fp);
        }
        fclose(fpc);


        fclose(fp);
    }

    return (0);
}
