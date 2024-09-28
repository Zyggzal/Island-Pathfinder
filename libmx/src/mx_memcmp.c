#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	unsigned char *a = (unsigned char*)s1;
	unsigned char *b = (unsigned char*)s2;
	int c = 0;
	if(s1 == s2)return c;
	while(n > 0) {
		if(*a != *b) {
			if(*a > *b) {
				c = 1;
			}
			else { 
				c = -1;
			}
			break;
		}
		n--;
		a++;
		b++;
	}
	return c;
}

