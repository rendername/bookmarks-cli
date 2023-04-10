#include <stdio.h>
#include <string.h>
#include "list.h"
#include "storage.h"

void list_usage() {
    printf("list usage:\n");
    printf("\tbookmarks list\n\n");
    printf("examples:\n");
    printf("\tbookmarks list\n");
}

int list() {
    const char* filePath = getStoragePath();

    FILE *pFile = fopen(filePath, "r");
    if(pFile == NULL) {
        printf("Error could not open file: %s\n", filePath);
        return -1;
    }
    
    char current;
    while(current != EOF) {
        current = fgetc(pFile);
        printf("%c", current);
    }

    fclose(pFile);

    return 0;
}
