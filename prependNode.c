#include <stdio.h>
#include <string.h>
#include "pa1.h"

void prependNode(linkedListNode_t** head, char* str){
    linkedListNode_t * node = newLinkedListNode();
    char *ptr = strcp(str);
    (*node).value = ptr;
    (*node).next = *head;
    *head = node;
}
