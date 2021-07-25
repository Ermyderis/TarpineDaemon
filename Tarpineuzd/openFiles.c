#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reading(char config[256], char line[1000], int linenum, char aud[50], char audthird[50], char vid[50], char vidthird[50], char pho[50], char phothird[50], 
    char doc[50], char dochird[50], char diwatch[50], char diwatchthird[50], char typwatch[50], char typwatchthird[50]){
        FILE *fpt= NULL;
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
                if(linenum == 1){
                    strcpy(aud, firstColumn);
                    strcpy(audthird, thirdColumn);
                }
                if(linenum == 2){
                    strcpy(vid, firstColumn);
                    strcpy(vidthird, thirdColumn);
                }
                if(linenum == 3){
                    strcpy(pho, firstColumn);
                    strcpy(phothird, thirdColumn);
                }
                if(linenum == 4){
                    strcpy(doc, firstColumn);
                    strcpy(dochird, thirdColumn);
                }
                if(linenum == 5){
                    strcpy(diwatch, firstColumn);
                    strcpy(diwatchthird, thirdColumn);
                }
                if(linenum == 6){
                    strcpy(typwatch, firstColumn);
                    strcpy(typwatchthird, thirdColumn);
                }
     
            }
            fclose(fpt);
}
}