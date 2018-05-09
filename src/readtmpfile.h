#ifndef READTMPFILE_H
    #define READTMPFILE_H
    typedef struct{
        char *name;
	long size;
    }FileInformations;
    int readFile(char **name, long *size, int debug, int *index, int lines);
#endif
