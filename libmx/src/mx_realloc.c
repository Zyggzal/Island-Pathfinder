#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	if(size == 0) {
		free(ptr);
		return 0;
	}
	if(!ptr) return malloc(size);
	if(size <= sizeof(ptr))return ptr;
	void *p = malloc(size);
	mx_memcpy(p, ptr, sizeof(p));
	free(ptr);
	
	return p;
}

