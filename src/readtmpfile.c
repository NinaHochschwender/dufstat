#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readtmpfile.h"
int readFile(char **fstring, long *sizes, int debug, int *index){
    FILE *f = fopen("/tmp/dufstat.tmp","rb");
    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    rewind(f);
    char *string = malloc(len + 1);
    fread(string, len, 1, f);
    fclose(f);
    puts(string);
    FILE *shell;
    int status;
    int lines;
    char *tmp = malloc(80 * sizeof(char));
    shell = popen("cat /tmp/dufstat.tmp | wc -l", "r");
    if (shell == NULL){
        return 1;
    }
    while (fgets(tmp, 79, shell) != NULL){
        lines = atoi(tmp);
    }
    printf("%li\n", lines);
    free(tmp);
    status = pclose(shell);
    if (status == -1){
        return 1;
    } else {
        char *ptr;
        char delimiter[] = "\n";
        char *line = malloc(10000);
        ptr = strtok(string, delimiter);
        int i = 0;
        char *ptr2;
        char delim[] = ";";
        puts("1");
        char *buf1 = malloc(10000);
        char *buf2 = malloc(21);
        puts("2");
        fstring = malloc((lines+1) * sizeof(char *));
        puts("3");
        sizes = malloc((lines+1) * sizeof(long));
        puts("4");
        while(ptr != NULL){
            strcpy(line, ptr);
            puts(line);
            ptr2 = strtok(line, delim);

            strcpy(buf1, ptr2);
            puts(buf1);
            ptr2 = strtok(NULL, delim);
            strcpy(buf2, ptr2);
            printf("%i\n", strlen(buf1)+1);
            fstring[i] = malloc(strlen(buf1) + 1);
            strcpy(fstring[i], buf1);
            sizes[i] = atol(buf2);
            i++;
            ptr = strtok(NULL, delimiter);
        }
        free(string);
        free(ptr);
        //free(line);
        free(buf1);
        free(buf2);
        index = &i;
    } 
}