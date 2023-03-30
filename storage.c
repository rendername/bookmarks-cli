#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storage.h"

char* getStoragePath() {
    char* home = getenv("HOME");
    char* pathSuffix = "/.config/bookmarks.txt";
    
    return strcat(home, pathSuffix);
}

char* join(char* a, const char* separator, char* b) {
    char result[1024];
    strcat(result, a);
    strcat(result, separator);
    strcat(result, b);

    char *pResult = result;
    return pResult;
}
