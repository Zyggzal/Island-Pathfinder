#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
	char *tmp = mx_strnew(len);
	if(!tmp) return 0;
	char *srct = (char*)src;
	char *dstt = (char*)dst;

	for(size_t i = 0; i < len; i++) {
		*(tmp + i) = *(srct + i);	
	}
	for(size_t i = 0; i < len; i++) {
		*(dstt + i) = *(tmp + i);
	}
	free(tmp);
	return (void*)dst;
}

