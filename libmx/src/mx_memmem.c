#include "../inc/libmx.h"

void *mx_memmem( void *big, size_t big_len,  void *little,  size_t little_len) {
	if(big_len == 0 || big_len < little_len) return 0;
	if(little_len == 0) return big;
	char *tmpl = (char*)little;
	char *tmpb = (char*)big;
	if(little_len == 1) return mx_memchr(big, (int)*tmpl, big_len);
	char *last = (char*)tmpb + big_len - little_len;

	for(char* cur = (char*)tmpb; cur <= last; cur++) {
		if(cur[0] == tmpl[0] && mx_memcmp(cur, tmpl, little_len) == 0) {
			return cur;
		}
	}
	return 0;
}

