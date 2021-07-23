#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fileCreating.h"

int main(void){
	createLogFile("log.txt");
	createConfigFile("config.txt");

	return 0;
}
