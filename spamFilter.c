#include <stdlib.h>
#include  <unistd.h>

#include "pa1.h"
#include "pa1Strings.h"

int main(int argc, char* argv[]){
    if(argc == 2){
        fprintf(stdout, LONG_USAGE);
	return EXIT_FAILURE;
    }
    if(argc == 3){
	FILE *fptr = fopen(argv[2], "r");
	if(fptr == NULL){
            perror(FILTER_ERR);
	    return EXIT_FAILURE;
	}
        linkedListNode_t ** tbl = newLinkedListArray(DEFAULT_SIZE);
        populateTable(tbl, fptr);
        launchUserQuery(tbl);
        cleanup(tbl);
        fclose(fptr);
	return EXIT_SUCCESS;
    }
    printf("%d", argc);
    fprintf(stderr, INVALID_ARGS);
    return EXIT_FAILURE;
}
