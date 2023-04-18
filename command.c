#include <string.h>
#include <stdlib.h>

#include "command.h"
#include "add.h"
#include "help.h"
#include "list.h"
#include "search.h"
#include "delete.h"

char *command_list[COMMAND_COUNT] = {
    "add",
    "help",
    "list",
    "search",
    "delete",
};

int get_command_index(char *command_string) {
    for(int i=0;i<COMMAND_COUNT;i++) {
        if(strcmp(command_string, command_list[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int execute(Command *command, int argc, char **argv) {
    switch(command->command_index) {
        case Help:
            return help();
            break;
        case Add:
            return add(command, argc, argv);
            break;
        case List:
            return list(command);
            break;
        case Search:
            return search(command, argc, argv);
            break;
        case Delete:
            return delete_bookmark(command, argc, argv);
            break;
        default:
            return help();
            break;
    }

    return EXIT_FAILURE;
}
