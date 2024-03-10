#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "pa1.h"
#define MAXLEN 30

void populateTable(linkedListNode_t** hashtbl, FILE* dataFile){
    char readbuf[BUFSIZ];
    if(dataFile == NULL){
	perror("Failed to read data file.");
	return;
    }
   // fseek(dataFile, 0 , SEEK_END);
   // int size = ftell(dataFile);
   // if(size == 0){
   //     return; 
   // }
    while(fgets(readbuf, MAXLEN, dataFile)){
	char *ptr = strchr(readbuf, '\n');
	if(ptr != NULL){
            *ptr = '\0';
	    for(int i = 0; readbuf[i] != '\0'; i++){
	        readbuf[i] = tolower(readbuf[i]);
	    } 
	}
	else{
	    for(int i = 0; i < strlen(readbuf); i++){
                readbuf[i] = tolower(readbuf[i]);
	    }
	}
	llTableAddString(hashtbl, readbuf);
    }
    
        
}
