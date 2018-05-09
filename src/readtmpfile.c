#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readtmpfile.h"
int readFile(char **name, long *size, int debug, int *index, int lines){
    //reading the file
	FILE *f = fopen("/tmp/dufstat.tmp","rb");
	char *str1 = (char*) malloc(10000);
	char *str2 = (char*) malloc(80);
	int c = 0;
	for (int i = 0; i <= lines; i++){
		if (feof(f)){
			puts("1");
			break;
		}
		if (fscanf(f,"%s %s", str1, str2) == EOF){
			fclose(f);
			free(str1);
			free(str2);
			return 1;
		}
		//name[i] = (char*) malloc((strlen(str1) + 1) * sizeof(char));
		if(name[i] == NULL){
			fclose(f);
			free(str1);
			free(str2);
			return 1;
		}
		strcpy(name[i], str1);
		printf("%s\t%s\n", str1,str2);
		size[i] = atol(str2);	
		c++;
	}
    fclose(f);
	index = &c;
	printf("%i\t%i",lines,c);
	free(str1);
	free(str2);
	/*
	//end
	//trying to read the csv
    char *buf1 = (char*) malloc(10000);
    char *buf2 = (char*) malloc(21);
    char *line = (char*) malloc(10000);
	char *ptr;
    char delimiter[] = "\n";
	char **inlines = (char **) malloc(lines * sizeof(char*));
    ptr = strtok(string, delimiter);
    int i = 0;
    while(ptr != NULL){
	    
		strcpy(line, ptr);
        inlines[i] = (char *) malloc((strlen(line)+1)*sizeof(char));
		strcpy(inlines[i], line);
        
		printf("%li\n", strlen(buf1) + 1);
        fi[i].name = (char*) malloc(strlen(buf1) + 1);
        fi[i].size = atol(buf2);
        printf("%li\n", fi[i].size);
		if(fi[i].name == NULL ){
			puts("Somethings wrong, I can feel it. If it is what I think, we are in big big truble but I don't know what!");
			return 1;
		}
		strcpy(fi[i].name, buf1);
		
        i++;
        ptr = strtok(NULL, delimiter);
   	}
	for(int j = 0; j < i; j++){
		sscanf(inlines[j],"%s %s",buf1,buf2);
		fi[j].name = (char *) malloc((strlen(buf1)+1) * sizeof(char));
		strcpy(fi[j].name,buf1);
		fi[j].size = atol(buf2);
	}
    free(string);
    free(line);
    free(buf1);
    free(buf2);
	free(inlines);
    index = &i;
	*/
	
	return 0;
}
