#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa1.h"

int checkTable(char* str, linkedListNode_t** hashtbl){
    linkedListNode_t *curr = retrieveLinkedList(hashtbl, str);
    if(curr == NULL){
        return 0;
    }
    while(curr != NULL){
        if(strcmp(str, (*curr).value) == 0){
            return 1;
	}
	curr = (*curr).next;
    }
    return 0;
}
