#ifndef SEARCH_H
#define SEARCH_H

#include "command.h"

#define MAX_LINE 1024

typedef struct SearchResult {
    char *line;
    char *shortname;
    char *url;
    char *tags;
    int line_number;
    int found;
} SearchResult;

void search_usage(void);
int search(Command *command, int argc, char **argv);
SearchResult *search_file(char *storage_path, char *shortname);

#endif // SEARCH_H
