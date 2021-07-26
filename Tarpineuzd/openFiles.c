#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reading(char config[256], char line[1000], int linenum, char aud[50], char audthird[50], char vid[50], char vidthird[50], char pho[50], char phothird[50], 
    char doc[50], char dochird[50], char diwatch[50], char diwatchthird[50], char typwatch[50], char typwatchthird[50]){
        FILE *fpt= NULL;
        char *pos = NULL;
        fpt = fopen(config, "r");
    	if (!fpt){
        	printf("Error, cant open config");
            exit(1);
        }
        else{
    		while(fgets(line, 256, fpt) != NULL){
                char firstColumn[256], secondColumn[256], thirdColumn[256];
                linenum++;
                if(sscanf(line, "%s%s%s", firstColumn, secondColumn, thirdColumn) != 3){
                    //fprintf(fp, "\nSyntax error, line%d\n", linenum);
                }
                pos = strstr(firstColumn, "audio");
                if(pos != NULL){
                    strcpy(aud, firstColumn);
                    strcpy(audthird, thirdColumn);
                    pos = NULL;
                }
                pos = strstr(firstColumn, "video");
                if(pos != NULL){
                    strcpy(vid, firstColumn);
                    strcpy(vidthird, thirdColumn);
                    pos = NULL;
                }
                pos = strstr(firstColumn, "photo");
                if(pos != NULL){
                    strcpy(pho, firstColumn);
                    strcpy(phothird, thirdColumn);
                    pos = NULL;
                }
                pos = strstr(firstColumn, "document");
                if(pos != NULL){
                    strcpy(doc, firstColumn);
                    strcpy(dochird, thirdColumn);
                    pos = NULL;
                }
                pos = strstr(firstColumn, "dir_to_watch");
                if(pos != NULL){
                    strcpy(diwatch, firstColumn);
                    strcpy(diwatchthird, thirdColumn);
                    pos = NULL;
                }
                pos = strstr(firstColumn, "types_to_watch");
                if(pos != NULL){
                    strcpy(typwatch, firstColumn);
                    strcpy(typwatchthird, thirdColumn);
                    pos = NULL;
                }
     
            }
            fclose(fpt);
}
}