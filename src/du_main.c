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

int main(int argc, char **argv){
    char cwd[1024];
    int summing = 0;
    int debug = 0;
	char **files;
    long *size;
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
    if (readFile(&files,&size,debug,&index) != 0){
        return 1;
    }
    if (summing == 1){
        printf("%20s%li",".", sumoffiles(size));
        return 0;
    } else {
        for (int i = 0; i <= index;i++){
            printf("%-40s %li\n",files[i],size[i]);
        }
        return 1;
    }
}
