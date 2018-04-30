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
//#include "du.h"
//#include "du_s.h"
#include <stdio.h>
#include <string.h>
#include "help.h"

int main(int argc, char **argv){
    for(int i = 0; i < argc; i++){
        if (strcmp(argv[i],"--help") == 0){
            help();
            return 0;
        }
    }
}