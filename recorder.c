#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wavutils.h"

// aux function to extract args values
const char *get_arg_value(int argc, char **argv, const char *target_arg){
    for(int arg_idx = 0; arg_idx < argc; arg_idx++){
        if(!strcmp(argv[arg_idx], target_arg)) // <arg> <value> 
            return argv[arg_idx+1]==NULL?"":argv[arg_idx+1];
    }
    return NULL;
}

int main(int argc, char **argv){
	char filename[100];
	const char *input_arg = NULL;
	int duration = 3;

	if ((input_arg = get_arg_value(argc, argv, "--record")) != NULL){
		strcpy(filename, input_arg);
		
		if ((input_arg = get_arg_value(argc, argv, "--duration")) != NULL){
        	duration = atoi(input_arg);
    	}
        
        printf("[+] Recording by %d seconds under '%s'...\n", duration, filename);
        recordAndSaveWav(filename, duration);
    }else if ((input_arg = get_arg_value(argc, argv, "--play")) != NULL) {
    	 strcpy(filename, input_arg);
    	 printf("[+] Playing %s\n", filename);
    	 playWavFile(filename);
    }

	return 0;
}

