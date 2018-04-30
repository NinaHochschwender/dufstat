/*
 * =====================================================================================
 *
 *       Filename:  du_s.c
 *
 *    Description:  the sources for summarizing du
 *
 *        Version:  1.0
 *        Created:  27.04.2018 18:27:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nils Hochschwender
 *   Organization:  None
 *
 * =====================================================================================
 */
#include "du_s.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

long sumoffiles(long * size){
    long sizes;
    for(int i = 0; i < (sizeof(size)/sizeof(long)); i++){
        sizes += size[i];
    }
}
