#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    if(str == NULL) {
        return NULL;
    }
    int size = mx_strlen(str);
    char *res = mx_strnew(size);
    return mx_strcpy(res, str);
}

