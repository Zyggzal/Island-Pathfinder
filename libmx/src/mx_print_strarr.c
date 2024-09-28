#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
	if(delim == NULL || mx_strlen(delim) < 1 || arr == NULL) {
		return;
	}
	do {
		mx_printstr(*arr++);
		if(*arr) {
			mx_printstr(delim);
		}
	} while (*arr);
	mx_printchar('\n');
}
