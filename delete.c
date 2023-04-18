#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "delete.h"
#include "command.h"
#include "storage.h"
#include "search.h"

void delete_usage(void) {
    printf("delete usage:\n");
}

int delete_bookmark(Command *command, int argc, char **argv) {
    if(argc < 3) {
        fputs("add command requires 1 argument\n", stderr);
        return EXIT_FAILURE;
    }

    char *temp_path = "./tmp";
    char *shortname = argv[2];

    SearchResult *search_result = search_file(command->storage_path, shortname);

    if(search_result->found == 0) {
        printf("the bookmark \"%s\" does not exist, not deleting\n", shortname);
        return EXIT_SUCCESS;
    }

    FILE *original_fp;
    FILE *temp_fp;

    original_fp = fopen(command->storage_path, "r");
    temp_fp = fopen(temp_path, "a");

    if(original_fp == NULL) {
        fputs("could not open file for read\n", stderr);
        return EXIT_FAILURE;
    }

    if(temp_fp == NULL) {
        fputs("could not open temp file for append\n", stderr);
        return EXIT_FAILURE;
    }

    char line_buffer[MAX_LINE];
    int i=1;
    while(fgets(line_buffer, MAX_LINE, original_fp) != NULL) {
        if(i != search_result->line_number) {
            fputs(line_buffer, temp_fp);
        }
        i++;
    }

    remove(command->storage_path);
    rename(temp_path, command->storage_path);

    fclose(original_fp);
    fclose(temp_fp);

    return EXIT_SUCCESS;
}
