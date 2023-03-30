#include <stdio.h>
#include <string.h>
#include "add.h"
#include "storage.h"

void usage() {
    printf("add usage:\n");
    printf("\tbookmarks add SHORTNAME URL [TAGS]\n\n");
    printf("examples:\n");
    printf("\tbookmarks add google google.com search\n");
    printf("\tbookmarks add amazon amazon.com shopping prime movies\n");
}

int add(int argc, char** argv) {
    if(argc < 4) {
        usage();
        return -1;
    }

    const char* filePath = "test.txt";

    FILE *pFile = fopen(filePath, "w");
    if(pFile == NULL) {
        printf("Error could not open file: %s\n", filePath);
        return -1;
    }

    char* workingText = join(argv[2], " ", argv[3]);

    if(argc > 4) {
        for(int i=4;i<argc;i++) {
            workingText = join(workingText, ",", argv[i]);
        }
    }

    printf("%s\n", workingText);
    
    fclose(pFile);

    // 1. open file
    // 2. look if SHORTNAME is in file case sensitive
    // if exists notify, show the record, and return -1
    // if not exists
    // 3. append SHORTNAME, URL, and optional tags to file
    // 4. close file
    // 5. return success
    

    return 0;
}
