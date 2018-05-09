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
#include "help.h"
#include "du.h"
#include "du_s.h"
#include "readtmpfile.h"

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
    char cwd[1024];
    int summing = 0;
    int debug = 0;
    int index;
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
        if (strcmp(argv[i], "perreiter") == 0){
            printf("fuck off\n");
            return 0;
        }
    }
	if (getcwd(cwd, sizeof(cwd)) != NULL){
		filesreturn(cwd, 0, 0,debug);	
	} else {
		perror("getcwd error");
        return 1;
	}
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
		lines--;
		char **name = malloc(lines * sizeof(char*));
		long *sizes = malloc(lines * sizeof(long));
		if (name == NULL || sizes == NULL){
			puts("nooo");
			exit(1);
		}
		
		for (int i = 0; i <= lines; i++){
			name[i] = malloc(1000);
			if(name[i] == NULL){
				puts("nooo");
				exit(1);
			} else {
				strcpy(name[i],"in");
			}
		}
		for(int i = 0; i <= lines; i++)
			printf("%s\n",name[i]);	
		if (readFile(name,sizes,debug,&index,lines) != 0){
            for (int i = 0; i <= lines; i++){
				if(name[i] != NULL)
					free(name[i]);
			}
			free(name);
			free(sizes);
			return 1;
    	}
    	if (summing == 1){
    	    printf("%20s%li",".", sumoffiles(sizes, lines));
			for (int i = 0; i <= lines; i++){
				if(name[i] != NULL)
					free(name[i]);
			}
    	    free(name);
			free(sizes);
			return 0;
	    } else {
	        for (int i = 0; i <= lines;i++){
				if(name[i] != NULL)
	            	printf("%-40s %li\n",name[i], sizes[i]);
    	    }
			for (int i = 0; i <= lines; i++){
				//if(name[i] != NULL)
					free(name[i]);
			}
			free(name);
			free(sizes);
        	return 2;
    	}
	}
}
