/*
 * =====================================================================================
 *
 *       Filename:  du.c
 *
 *    Description:  the main algorithm for reading the dirs and writing the output to 
 *                  a file for later usage by the other functions
 *
 *        Version:  1.0
 *        Created:  27.04.2018 21:15:55
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
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "du.h"


void readdirs(FILE *file, char * dir, short showHidden, short followSymlink){
    DIR *dp;
    struct dirent *ep;
    dp = opendir(dir);
    char *fulldir = malloc(10000 * sizeof(char));
    if (dp != NULL){
        while (ep = readdir(dp)){
            if (ep->d_type == DT_DIR && strcmp(ep->d_name,"..") == 0 && strcmp(ep->d_name,".") == 0){
                if (ep->d_name[0] == "." && showHidden == 1){
                    sprintf(fulldir,"%s/%s",dir,ep->d_name);
                    readdirs(file, fulldir,showHidden, followSymlink);
                } else {
                    sprintf(fulldir,"%s/%s",dir,ep->d_name);
                    readdirs(file, fulldir,showHidden, followSymlink);
                }
            } else if (ep->d_type == DT_REG){
                if (ep->d_name[0] == "." && showHidden == 1){
                    sprintf(fulldir,"%s/%s",dir,ep->d_name);
                    fprintf(file,"%s\n",fulldir);
                } else {
                    sprintf(fulldir,"%s/%s",dir,ep->d_name);
                    fprintf(file,"%s\n",fulldir);
                }
            }
        }
        (void)closedir(dp);//close the directory
    }

}

void filesreturn(char * directory, short showHidden, short followSymlink){
    FILE *f = fopen("/tmp/dufstat.tmp","w");//temp file to be gentle on memory
    readdirs(f, directory, showHidden,followSymlink);//calling the recusive function
    fclose(f);
}
