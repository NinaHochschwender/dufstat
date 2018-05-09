/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  main
 *
 *        Version:  1.0
 *        Created:  27.04.2018 21:24:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nils Hochschwender
 *   Organization:  None
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fnmatch.h>
#include "help.h"
#include "du.h"
#include "du_s.h"
#include "readtmpfile.h"

//todo check if it can be removed
/*
void freeingFiles(FileInformations *fi, int index){
	for(int i = 0; i < index; i++){
		if(fi[i].name != NULL){
			free(fi[i].name);
		}
	}
	free(fi);
}
*/

int main(int argc, char **argv){
    char cwd[1024];//path
    int summing = 0;//if the -s or --summarize flag is enabled
    int debug = 0;//todo remove in the end
    int index;//useless todo remove
	//checking the userinput
    if (argc > 1){
		if (strncmp("-",argv[argc-1],1) != 0){
			strcpy(cwd, argv[argc-1]);
		} else {
			if (getcwd(cwd, sizeof(cwd)) == NULL){
       			exit(1);
			}
		}
		for(int i = 0; i < argc; i++){
        	if (strcmp(argv[i],"--help") == 0){
            	help();
            	return 0;
        	}
        	if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--summarize") == 0){
            	summing = 1;
        	}
        	if (strcmp(argv[i], "--debug") == 0){
            	debug = 1;
        	}
    	}
	} else {
		if (getcwd(cwd, sizeof(cwd)) == NULL){
				exit(1);
		}
	}
	filesreturn(cwd,0,0,debug);
    //reading from the shell
    FILE *shell;
    int status;
    int lines;//num lines
    char *tmp = (char*) malloc(80 * sizeof(char));
    shell = popen("cat /tmp/dufstat.tmp | wc -l", "r");
    if (shell == NULL){
        return 1;
    }
    while (fgets(tmp, 79, shell) != NULL){
        lines = atoi(tmp);
    }
    printf("%i\n", lines);
    free(tmp);
    status = pclose(shell);
    if (status == -1){
        return 1;
    } else {
		lines;
		char **name = malloc((lines - 1) * sizeof(char*));
		long *sizes = calloc(lines - 1,sizeof(long));
		if (name == NULL || sizes == NULL){
			puts("nooo");
			exit(1);
		}
		
		for (int i = 0; i < lines; i++){
			name[i] = calloc(1000,sizeof(char));
			if(name[i] == NULL){
				puts("nooo");
				exit(1);
			} else {
				strcpy(name[i],"in");
			}
		}
		int errs = readFile(name,sizes,debug,&index,lines);
	    //printf("%i\n",errs);
		if (errs != 0){
            for (int i = 0; i < lines; i++){
				//if(name[i] != NULL)
					free(name[i]);
			}
			free(name);
			free(sizes);
			exit(1);
    	}
    	if (summing == 1){
    	    printf("%-20s%li\n",".", sumoffiles(sizes, lines));
			for (int i = 0; i < lines; i++){
				if(name[i] != NULL)
					free(name[i]);
			}
    	    free(name);
			free(sizes);
			exit(0);
	    } else {
	        for (int i = 0; i < lines;i++){
				if(name[i] != NULL)
	            	printf("%-40s %li\n",name[i], sizes[i]);
    	    }
			for (int i = 0; i < lines; i++){
				//if(name[i] != NULL)
					free(name[i]);
			}
			free(name);
			free(sizes);
        	return 2;
    	}
	}
}
