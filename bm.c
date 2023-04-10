#include <stdio.h>
#include "command.h"
#include "storage.h"

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

    const char *storage_path = getStoragePath();
    FILE *pFile;
    pFile = fopen(storage_path, "r+");

    if(pFile == NULL) {
        fprintf(stderr, "could not print %s", storage_path);
    }

    int execute_result = execute(c, argc, argv, pFile);
    fclose(pFile);
    return execute_result;
}
