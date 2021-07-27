#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

//creating directorys if they are not exist 
void createDirection(char logos[255], char videoMoveto[500], char photosMoveto[500], char musicMoveto[500], char documentsMoveto[500]){
        FILE *fp= NULL;
        fp = fopen (logos, "a");
            
        DIR *dir1 = opendir(videoMoveto);
        if (dir1 == NULL){
                mkdir(videoMoveto,0700);

                //writind directory name and creation date to log file
  	        fprintf(fp, "\nDirectorys %s created", videoMoveto);

        }
        DIR *dir2 = opendir(photosMoveto);
        if (dir2 == NULL){
                mkdir(photosMoveto,0700);
                fprintf(fp, "\nDirectorys %s created", photosMoveto);
        }
        DIR *dir3 = opendir(musicMoveto);
        if (dir3 == NULL){
                mkdir(musicMoveto,0700);
                fprintf(fp, "\nDirectorys %s created", musicMoveto);
        }
        DIR *dir4 = opendir(documentsMoveto);
        if (dir4 == NULL){
                mkdir(documentsMoveto,0700);
                fprintf(fp, "\nDirectorys %s created", documentsMoveto);
        }
        fclose(fp);
}