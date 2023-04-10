#include "command.h"
#include "add.h"
#include "list.h"
#include "edit.h"
#include "search.h"
#include <stdio.h>
#include <string.h>

const int commandCount = 5;
const char* commandList[] = {
    "help",
    "list",
    "add",
    "edit",
    "search",
};

int getCommandIndex(char* commandString) {
    for(int i=0;i<commandCount;i++) {
        if(strcmp(commandString, commandList[i]) == 0)
            return i;
    }
    return -1;
}

int help() {
    printf("running help\n");
    return 0;
}

int execute(Command c, int argc, char** argv) {
    switch(c.commandIndex) {
        case Help:
            return help();
            break;
        case List:
            return list();
            break;
        case Add:
            return add(argc, argv);
            break;
        case Edit:
            return edit(argc, argv);
            break;
        case Search:
            return search(argc, argv);
            break;
        default:
            return help();
            break;
    }
}
