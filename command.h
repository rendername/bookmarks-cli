#ifndef command
#define command

enum eCommand {
    Help,
    List,
    Add,
};

typedef struct Command {
    char* commandString;
    int commandIndex;
} Command;

int getCommandIndex(char* commandString);

int help();
int list();
int execute(Command c, int argc, char** argv);

#endif // !command
