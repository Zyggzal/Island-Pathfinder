#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	unsigned char uc = (unsigned char)c;
	unsigned char *tmp = (unsigned char*)s;

	int i = mx_strlen((char*)tmp) - 1;
	for(; i >= 0 && n > 0; i--, n--) {
		if(tmp[i] == uc) {
			tmp += i;
			return (void *)tmp;
		}
	}
	return NULL;
}

