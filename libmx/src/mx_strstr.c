#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
	if(!haystack || !needle) {
		return NULL;
	}
	if (mx_strlen(needle) > mx_strlen(haystack)) { 
		return NULL;
	}
    	int i = 0;
    	while (haystack[i] != 0) {
        	if(mx_strncmp(&haystack[i], needle, mx_strlen(needle)) == 0) {
			return mx_strchr(&haystack[i], needle[0]);
		}
        	i++;
    	}
	return NULL;
}
