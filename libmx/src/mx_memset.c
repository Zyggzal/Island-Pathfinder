#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
	if(!b) return 0;
	if(len == 0) return b;

	unsigned char uc = c;
	
	for(size_t i = 0; i < len; i++) {
		((char*)b)[i] = uc;	
	}
	
	return b;
}
