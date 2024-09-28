#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
	if(!str || !sub) {
		return -2;
	}
	if (mx_strlen(sub) > mx_strlen(str)) { 
		return -1;
	}
    	int i = 0;
    	while (str[i] != '\0') {
        	if(mx_strncmp(&str[i], sub, mx_strlen(sub)) == 0) {
			return i;
		}
        	i++;
    	}
	return -1;
}

