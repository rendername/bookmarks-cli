#include <stdio.h>
#include <string.h>
#include "search.h"
#include "add.h"
#include "storage.h"

#define MAX_PATH 8192
#define MAX_STRING 8192

void add_usage() {
    printf("add usage:\n");
    printf("\tbookmarks add SHORTNAME URL [TAGS]\n\n");
    printf("examples:\n");
    printf("\tbookmarks add google google.com search\n");
    printf("\tbookmarks add amazon amazon.com shopping prime movies\n");
}

int add(int argc, char** argv) {
    if(argc < 4) {
        add_usage();
        return -1;
    }

    char *shortname = argv[2];
    char search_result[MAX_STRING];
    if(searchFileForShortname(shortname, search_result) == 0) {
        printf("cannot add bookmark for %s, it already exsits\n", shortname);
        return -1;
    }

    const char* filePath = getStoragePath();
    FILE *pFile = fopen(filePath, "a");
    if(pFile == NULL) {
        printf("Error could not open file: %s\n", filePath);
        return -1;
    }

    char buffer[MAX_PATH];
    strcat(buffer, argv[2]);
    strcat(buffer, " ");
    strcat(buffer, argv[3]);

    if(argc > 4) { // we have at least one tag
        strcat(buffer, " ");
        for(int i=4;i<argc;i++) {
            strcat(buffer, argv[i]);
            strcat(buffer, ",");
        }
    }

    strcat(buffer, "\n");
    fprintf(pFile, "%s", buffer);
    fclose(pFile);

    return 0;
}
