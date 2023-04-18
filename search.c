#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "search.h"

SearchResult *search_file(char *storage_path, char *shortname) {
    SearchResult result;
    SearchResult *pResult = &result;

    pResult->found = 0;

    FILE *fp;
    fp = fopen(storage_path, "r");

    if(fp == NULL) {
        fputs("could not open bookmarks file for reading/searching\n", stderr);
        return pResult;
    }

    int line_number = 0;
    char line_buffer[MAX_LINE];
    while(fgets(line_buffer, MAX_LINE, fp) != NULL) {
        ++line_number;
        char tokenized[MAX_LINE];
        strcpy(tokenized, line_buffer);
        strtok(tokenized, " ");
        if(strcmp(tokenized, shortname) == 0) {
            fclose(fp);
            pResult->line = line_buffer;
            pResult->shortname = shortname;
            pResult->line_number = line_number;
            pResult->found = 1;

            return pResult;
        }
    }

    return pResult;
}

void search_usage(void) {
    printf("search usage:\n");
}

int search(Command *command, int argc, char **argv) {
    if(argc < 3) {
        fputs("search command requires at least 2 arguments\n", stderr);
        return EXIT_FAILURE;
    }

    char *shortname = argv[2];

    SearchResult *search_result = search_file(command->storage_path, shortname);
    if(search_result->found == 0) {
        printf("%s not found\n", shortname);
        return EXIT_FAILURE;
    }

    fputs(search_result->line, stdout);

    return EXIT_SUCCESS;
}
