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

int list(FILE *pFile) {
    const char* filePath = getStoragePath();

    char current;
    while(current != EOF) {
        current = fgetc(pFile);
        printf("%c", current);
    }

    return 0;
}
