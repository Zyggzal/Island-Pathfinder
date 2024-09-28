#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	return mx_strncpy(mx_strnew(n), s1, n);
}

