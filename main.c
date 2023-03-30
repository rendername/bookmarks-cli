#include <stdio.h>
#include "command.h"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("must have at least one command\n");
        return -1;
    }

    Command c;
    c.commandString = argv[1];
    c.commandIndex = getCommandIndex(c.commandString);

    if(c.commandIndex == -1) {
        printf("%s command not valid\n", c.commandString);
        return -1;
    }


    return execute(c, argc, argv);
}
