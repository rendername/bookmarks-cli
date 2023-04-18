#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "add.h"
#include "command.h"
#include "search.h"

void add_usage(void) {
    printf("add usage:\n");
}

int add(Command *command, int argc, char **argv) {
    if(argc < 4) {
        fputs("add command requires at least 3 arguments\n", stderr);
        return EXIT_FAILURE;
    }

    char *shortname = argv[2];

    SearchResult *search_result = search_file(command->storage_path, shortname);

    if(search_result->found == 1) {
        printf("the bookmark \"%s\" already exists, not adding\n", shortname);
        return EXIT_SUCCESS;
    }

    FILE *fp;
    fp = fopen(command->storage_path, "a");

    if(fp == NULL) {
        fputs("could not open bookmarks file for writing\n", stderr);
        return EXIT_FAILURE;
    }

    char buffer[MAX_LINE];
    strcat(buffer, argv[2]);
    strcat(buffer, " ");
    strcat(buffer, argv[3]);

    if(argc > 4) {
        strcat(buffer, " ");
        for(int i=4;i<argc;i++) {
            strcat(buffer, argv[i]);
            strcat(buffer, ",");
        }
    }

    fprintf(fp, "%s\n", buffer);

    fclose(fp);

    return EXIT_SUCCESS;
}
