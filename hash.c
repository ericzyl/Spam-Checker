#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa1.h"

unsigned int hash(char* str){
    unsigned int hashVal = HASH_START_VAL;
    int len = strlen(str);

    for(int i = 0; i < len; i+=2){
        hashVal = hashVal*HASH_PRIME + (int)str[i];	
    }

    for(int i = 1; i < len; i+=2){
        hashVal = hashVal*HASH_PRIME + (int)str[i];	
    }

    return hashVal;
}

