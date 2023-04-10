#ifndef COMMAND_H
#define COMMAND_H

enum eCommand {
    Help,
    List,
    Add,
    Edit,
    Search,
};

typedef struct Command {
    char* commandString;
    int commandIndex;
} Command;

int getCommandIndex(char* commandString);

int help();
int list();
int execute(Command c, int argc, char** argv);

#endif // !COMMAND_H
