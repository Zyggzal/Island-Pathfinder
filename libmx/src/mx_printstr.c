#include "../inc/libmx.h"

int mx_strlen(const char*);

void mx_printstr(const char *s) {
    write(1, s, mx_strlen(s));
}

