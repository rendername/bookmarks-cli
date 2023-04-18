#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>

#define COMMAND_COUNT 5

enum eCommand {
    Add,
    Help,
    List,
    Search,
    Delete,
};

typedef struct Command {
    int command_index;
    char *command_string;
    char *storage_path;
} Command;

int get_command_index(char *command_string);
int execute(Command *command, int argc, char **argv);

#endif // end COMMAND_H
