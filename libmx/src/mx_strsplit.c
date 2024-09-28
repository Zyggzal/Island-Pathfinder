#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {
	int i = 0;
    	int counter;
   	int len; 
    	int start;
    	char **result = (char **)malloc((mx_count_words(s, c) + 1) * sizeof(char *));
	result[mx_count_words(s, c)] = NULL;

    	while (s[i] == c) {
       		if (s[i]=='\0') {
           		return NULL;
       		}
       		i++;
    	}
    	for (counter = 0; counter < mx_count_words(s, c); counter++) {
        	len = 0;
        	start = i;
        	while (s[i] != c && s[i] != '\0') {
            		len++;
            		i++;
        	}
        	result[counter] = mx_strnew(len);
        	mx_strncpy(result[counter], &s[start], len);
		while (s[i] == c) {
           		i++;
        	}
    	}
    	return result;
}

