#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "list.h"
#include "storage.h"

void list_usage(void) {
    printf("list usage:\n");
}

int list(Command *command) {
    FILE *fp;
    fp = fopen(command->storage_path, "r");

    if(!fp) {
        fputs("Error opening storage file\n", stderr);
        return EXIT_FAILURE;
    }

    char c;
    while((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}
