#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storage.h"

char* getStoragePath() {
    char* home = getenv("HOME");
    char* pathSuffix = "/.config/bookmarks.txt";
    
    return strcat(home, pathSuffix);
}
