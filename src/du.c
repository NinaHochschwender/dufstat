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
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "du.h"


void readdirs(FILE *file, char * dir, short showHidden, short followSymlink){
    DIR *dp;
    struct dirent *ep;
    dp = opendir(dir);
	int fileTest = 0;
	struct stat filestat;
    char *fulldir = malloc(10000 * sizeof(char));
    if (dp != NULL){
        while (ep = readdir(dp)){
			sprintf( fulldir, "%s/%s", dir, ep->d_name );
            fileTest = 0;
			if (( fileTest = open (fulldir, O_RDONLY)) >= -1){
				if ( fstat ( fileTest, &filestat) >= 0){	
					if (S_ISDIR( filestat.st_mode)){
						if(strcmp(ep->d_name,"..") == 0){
							
						} else if((strcmp(ep->d_name,".") == 0 && strlen(ep->d_name) == 1)){

						}else{
                		/*
						if (strstr(ep->d_name, ".") == 0){
							if(showHidden == 1){
                    			readdirs(file, fulldir, showHidden, followSymlink);
							}
            	    	} else {
            	        	readdirs(file, fulldir, showHidden, followSymlink);
            	    	}
						*/
						readdirs(file, fulldir, showHidden, followSymlink);
						printf("%s\n", ep->d_name);

						 }
            		} else if ( S_ISREG( filestat.st_mode )){
						/*
            	    	if (strstr(ep->d_name, ".") == 0){
							if (showHidden == 1){
            	    			fprintf(file,"%s;%li\n",fulldir,filestat.st_size);
							}
            	    	} else {
            	            fprintf(file,"%s;%li\n",fulldir,filestat.st_size);
            	    	}
						*/
						fprintf(file, "%s;%li\n", fulldir, filestat.st_size);
						printf("%s;%li\n", fulldir,filestat.st_size);
            		}
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
