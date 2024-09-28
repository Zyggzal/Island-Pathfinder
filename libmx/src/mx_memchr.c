#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
	unsigned char uc = (unsigned char)c;
	unsigned char *tmp = (unsigned char*)s;
	for(size_t i = 0; i < n; i++) {
		if(*tmp == uc)return (void *)tmp;
		tmp++;
	}
	return NULL;
}

