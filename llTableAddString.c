#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa1.h"

void llTableAddString(linkedListNode_t** hashtbl, char* string){
    unsigned int hashVal = hash(string);
    int index = hashVal % DEFAULT_SIZE;
    linkedListNode_t** curr = hashtbl + index;
    prependNode(curr, string);
}

