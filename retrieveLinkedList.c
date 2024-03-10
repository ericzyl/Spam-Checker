#include <stdio.h>
#include <stdlib.h>
#include "pa1.h"

linkedListNode_t *retrieveLinkedList(linkedListNode_t** hashtbl, char* string){
    int index = hash(string) % DEFAULT_SIZE;
    return *(hashtbl+index);
}
