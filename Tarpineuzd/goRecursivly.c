#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "libFile.h"

void listFilesRecursively(char logos[255], char *basePath, char aud[50], char audthird[50], char vid[50], char vidthird[50], 
char pho[50], char phothird[50], char doc[50], char dochird[50], char diwatch[50], char diwatchthird[50], char typwatch[50], char typwatchthird[50]){
        //to change path to move files
        char videoMoveto[500] = "/home/kali/Videos";
        char photosMoveto[500] = "/home/kali/Pictures";
        char musicMoveto[500] = "/home/kali/Music";
        char documentsMoveto[500] = "/home/kali/Documents";
            FILE *fp= NULL;
            FILE *file= NULL;
        //creating directorys if they not exists
        createDirection(logos, videoMoveto, photosMoveto, musicMoveto, documentsMoveto);

        char whattomoveto[500];
        char whatToMove[500];
        char path[100];
        struct dirent *dp;
        DIR *dir = opendir(basePath); //open the path
        //Unable to open directory stream
        if (dir == NULL){
            fp = fopen (logos, "a");
            //fprintf(fp, "Directory not exist");
            fclose(fp);
                return;
                closedir(dir);
                }
        //if able to read something from the directory
        else{
        while ((dp = readdir(dir)) != NULL){
                if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
                char* ext;
	            ext = strchr(dp->d_name,'.');
                //if extinction exist
                if (ext != NULL){
                //watch if ext is in one of types
                char *followFile = NULL; 
                followFile = strstr(audthird,ext);

                ///////////////
                char *filemove;
                filemove = strstr(typwatchthird,aud);
                if(followFile != NULL && filemove != NULL){

                    strcpy(whatToMove, basePath);
                    strcat(whatToMove, "/");
                    strcat(whatToMove, dp->d_name);

                    strcpy(whattomoveto, musicMoveto);
                    strcat(whattomoveto, "/");
                    strcat(whattomoveto, dp->d_name);
                    rename(whatToMove, whattomoveto);
                    fp = fopen (logos, "a");
                    file = fopen(whattomoveto,"r");
                    if (file != NULL){
                        fprintf(fp, "\n%s moved to %s\n", whatToMove, whattomoveto);
                    }
                    fclose(file);
                    fclose(fp);

                    followFile = NULL;
                    filemove = NULL; 
                }
                /////////////////


                  ///////////////
                followFile = strstr(vidthird,ext);
                filemove = strstr(typwatchthird,vid);
                if(followFile != NULL && filemove != NULL){

                    strcpy(whatToMove, basePath);
                    strcat(whatToMove, "/");
                    strcat(whatToMove, dp->d_name);

                    strcpy(whattomoveto, videoMoveto);
                    strcat(whattomoveto, "/");
                    strcat(whattomoveto, dp->d_name);
                    rename(whatToMove, whattomoveto);
                    fp = fopen (logos, "a");
                    file = fopen(whattomoveto,"r");
                    if (file != NULL){
                        fprintf(fp, "\n%s moved to %s\n", whatToMove, whattomoveto);
                    }
                    fclose(file);
                    fclose(fp);

                    followFile = NULL;
                    filemove = NULL; 
                }
                /////////////////

                  ///////////////
                followFile = strstr(phothird,ext);
                filemove = strstr(typwatchthird,pho);
                if(followFile != NULL && filemove != NULL){

                    strcpy(whatToMove, basePath);
                    strcat(whatToMove, "/");
                    strcat(whatToMove, dp->d_name);

                    strcpy(whattomoveto, photosMoveto);
                    strcat(whattomoveto, "/");
                    strcat(whattomoveto, dp->d_name);
                    rename(whatToMove, whattomoveto);
                    fp = fopen (logos, "a");
                    file = fopen(whattomoveto,"r");
                    if (file != NULL){
                        fprintf(fp, "\n%s moved to %s\n", whatToMove, whattomoveto);
                    }
                    fclose(file);

                    fclose(fp);

                    followFile = NULL;
                    filemove = NULL; 
                }
                /////////////////

                     ///////////////
                followFile = strstr(dochird,ext);
                filemove = strstr(typwatchthird,doc);
                if(followFile != NULL && filemove != NULL){

                    strcpy(whatToMove, basePath);
                    strcat(whatToMove, "/");
                    strcat(whatToMove, dp->d_name);

                    strcpy(whattomoveto, documentsMoveto);
                    strcat(whattomoveto, "/");
                    strcat(whattomoveto, dp->d_name);
                    rename(whatToMove, whattomoveto);
                    fp = fopen (logos, "a");
                  
                    file = fopen(whattomoveto,"r");
                    if (file != NULL){
                        fprintf(fp, "\n%s moved to %s\n", whatToMove, whattomoveto);
                    }
                    fclose(file);
                    fclose(fp);

                    followFile = NULL;
                    filemove = NULL; 
                }
                /////////////////
          


                //ext
                }



                //Construct new path from our base path
                strcpy(path, basePath);
                strcat(path, "/");
                strcat(path, dp->d_name);
                listFilesRecursively(logos, path, aud, audthird, vid, vidthird, pho, phothird, doc, dochird, diwatch, diwatchthird, typwatch, typwatchthird);
                }
        }
        closedir(dir);
        }
       
    
        }
