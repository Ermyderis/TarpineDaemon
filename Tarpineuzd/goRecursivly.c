#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "libFile.h"

void listFilesRecursively(char logos[255], char *basePath){
        //char path[1000];
        //to change path to move files
        char videoMoveto[500] = "/home/kali/Desktop/testas nr.2/Videos";
        char photosMoveto[500] = "/home/kali/Desktop/testas nr.2/Pictures";
        char musicMoveto[500] = "/home/kali/Desktop/testas nr.2/Music";
        char documentsMoveto[500] = "/home/kali/Desktop/testas nr.2/Documents";

            FILE *fp= NULL;
            fp = fopen (logos, "a");
            fprintf(fp, "Conect to recur");
            fclose(fp);

        //char moveOnly[500] = "audio_types,document_types";
        //creating directorys if they not exists
        createDirection(logos, videoMoveto, photosMoveto, musicMoveto, documentsMoveto);




        }
