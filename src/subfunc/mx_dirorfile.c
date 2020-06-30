#include "ush.h"

int mx_dirorfile(const char *obj) {
    struct stat obj_stat;

    errno = 0;
    lstat(obj, &obj_stat);
    if (S_ISDIR(obj_stat.st_mode))
        return 0;
    if (S_ISREG(obj_stat.st_mode))
        return 1;
    if (S_ISLNK(obj_stat.st_mode))
        return 0;
    if (S_ISBLK(obj_stat.st_mode))
        return 1;
    if (S_ISCHR(obj_stat.st_mode))
        return 1;
    return -1;
}
