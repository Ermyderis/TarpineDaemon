#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int createConfigFile(char *fileConfig){
	FILE *fp;

	fp = fopen(fileConfig,"w");
	if(fp==NULL){
		printf("Error in opening file");
		exit(1);
	}
	
	fprintf(fp, "audio_types = mp3,flac,wav\n");
	fprintf(fp, "video_types = mkv,avi,mp4\n");
	fprintf(fp, "photo_types = svg,jpeg,png\n");
	fprintf(fp, "document_types = docx,txt,pdf\n");
	fprintf(fp, "dir_to_watch = /home/user/Downloads\n");
	fprintf(fp, "types_to_watch = audio,document\n");
	fclose(fp);

    return 0;

}

int createLogFile(char *fileLog){
FILE *fpt;

	fpt = fopen(fileLog,"w");
	if(fpt==NULL){
		printf("Error in opening file");
		exit(1);
	}
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	fprintf(fpt, "File created : %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	fclose(fpt);

    return 0;
}
