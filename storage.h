#ifndef STORAGE_H
#define STORAGE_H

#include <stdlib.h>
#include <string.h>

#define PATH_SUFFIX "/.config/bookmarks.txt"

char * get_storage_path(void);

#endif // STORAGE_H
