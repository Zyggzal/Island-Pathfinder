#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
	int l = mx_strlen(s);
	for(int i = 0; i < l / 2; i++) {
		mx_swap_char(&s[i], &s[l - i - 1]);
	}
}

