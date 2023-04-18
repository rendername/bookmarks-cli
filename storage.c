#include "storage.h"

char * get_storage_path(void) {
    char *home = getenv("HOME");
    return strcat(home, PATH_SUFFIX);
}
