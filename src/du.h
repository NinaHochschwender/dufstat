/*
 * =====================================================================================
 *
 *       Filename:  du.h
 *
 *    Description:  the main algorithm for reading the dirs and writing the output to 
 *    		    a file for later usage by the other functions
 *
 *        Version:  1.0
 *        Created:  27.04.2018 18:43:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nils Hochschwender
 *   Organization:  None
 *
 * =====================================================================================
 */

#ifndef DU_H
	#define DU_H
	void readdirs(FILE *file, char * dir, short showHidden, short followSymlink);//function to be called. never call this in other then du.c
	void filesreturn(char * directory, short showHidden, short followSymlink);//caller function
#endif
