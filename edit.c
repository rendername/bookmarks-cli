#include <stdio.h>

void edit_usage() {
    printf("edit usage:\n");
    printf("\tbookmarks edit SHORTNAME\n\n");
    printf("examples:\n");
    printf("\tbookmarks edit google\n");
}

int edit(int argc, char** argv) {
    if(argc < 3) {
        edit_usage();
        return -1;
    }

    char* shortname = argv[2];
    printf("you are wanting to edit: %s\n", shortname);

    return 0;
}

