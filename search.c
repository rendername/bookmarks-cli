#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storage.h"

#define MAX_STRING 8192

void search_usage() {
    printf("edit usage:\n");
    printf("\tbookmarks edit SHORTNAME\n\n");
    printf("examples:\n");
    printf("\tbookmarks edit google\n");
}

int searchFileForShortname(char *search_term, char *result, FILE *pFile) {
    while(fgets(result, MAX_STRING, pFile) != NULL) {
        char tokenized[MAX_STRING];
        strcpy(tokenized, result);
        if(strtok(tokenized, " ") == NULL) {
            fputs("could not tokenize string\n", stderr);
            return -1;
        }
        
        if(strcmp(search_term, tokenized) == 0) {
            return 0;
        }
    }

    return -1;
}

int search(int argc, char **argv, FILE *pFile) {
    if(argc < 3) {
        search_usage();
        return -1;
    }

    char *search_term = argv[2];
    char line[MAX_STRING];
    if(searchFileForShortname(search_term, line, pFile) == 0) {
        printf("%s", line);
    }

    return -1;
}
