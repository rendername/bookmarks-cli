#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "storage.h"

int main(int argc, char **argv) {
    if(argc < 2) {
        fputs("must have at least 1 argument\n", stderr);
        return EXIT_FAILURE;
    }

    char *command_string = argv[1];
    int command_index = get_command_index(command_string);

    if(command_index == -1) {
        printf("command \"%s\" not found\n", command_string);
        return EXIT_FAILURE;
    }

    char *storage_path = get_storage_path();

    Command command = {
        .command_index = command_index,
        .command_string = command_string,
        .storage_path = storage_path,
    };

    return execute(&command, argc, argv);
}
