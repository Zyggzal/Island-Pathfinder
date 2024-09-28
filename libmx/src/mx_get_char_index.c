#include "../inc/libmx.h"

int mx_get_char_index(const char *str, char c) {
	if(!str) return -2;
	int l = mx_strlen(str);
	for(int i = 0; i < l; i++) {
		if(str[i] == c) return i;
	}
	return -1;
}

