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
        time_t rawtime;
        struct tm * timeinfo;


        fp = fopen (logos, "a");
        
            
        DIR *dir1 = opendir(videoMoveto);
        if (dir1 == NULL){
                mkdir(videoMoveto,0777);

                time ( &rawtime );
                timeinfo = localtime ( &rawtime );
                //writind directory name and creation date to log file
  	        fprintf(fp, "\nDirectorys %s created: %s", videoMoveto, asctime (timeinfo) );

        }
        DIR *dir2 = opendir(photosMoveto);
        if (dir2 == NULL){
                mkdir(photosMoveto,0777);
                fprintf(fp, "Directorys %s created: %s", photosMoveto, asctime (timeinfo) );
        }
        DIR *dir3 = opendir(musicMoveto);
        if (dir3 == NULL){
                mkdir(musicMoveto,0777);
                fprintf(fp, "Directorys %s created: %s", musicMoveto, asctime (timeinfo) );
        }
        DIR *dir4 = opendir(documentsMoveto);
        if (dir4 == NULL){
                mkdir(documentsMoveto,0777);
                fprintf(fp, "Directorys %s created: %s", documentsMoveto, asctime (timeinfo) );
        }
        fclose(fp);
}