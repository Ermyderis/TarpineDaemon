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
	FILE *fp;
	fp = fopen ("log.txt", "a");
	daemonCreated();
	while (1) {
		//Dont block context switches, let the process sleep for some time
		sleep(3);
		fprintf(fp, "Logging info...\n");
		fflush(fp);
		// Implement and call some function that does core work for this daemon.
	}
	fclose(fp);

	return 0;
}
