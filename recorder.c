#include <stdio.h>
#include <stdlib.h>
#include "wavutils.h"

int main(int argc, char **argv){
	char filename[100];
	char option;
	int duration;
	system("title Audio recorder by:hwpoison");
	printf("  AUDIO RECORDER =============\n");
	printf(" 1)Play file\n 2)Record new file\n>");
	scanf("%c", &option);
	printf("File name:");
	scanf("%s", filename);
	if( option == '1'){
		PlayWavFile(filename);
	}
	if ( option == '2' ){
		printf("Duration(secs):");
		scanf("%d", &duration);
		RecordAndSaveWav(filename, duration);
		printf("Do you wanna play the file? y/n:");
		scanf(" %c", &option);
		if( option == 'y' ){
			PlayWavFile(filename);
		}else{
			printf("Okey..\n");
			exit(0);
		}
	}
	printf("Goodbye! :)\n");
	system("pause");
	return 0;
}

