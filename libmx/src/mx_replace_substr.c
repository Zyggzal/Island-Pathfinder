#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
        if(!str || !sub || !replace) return NULL;
        
        int cnt = mx_count_substr(str, sub);

        if(cnt <= 0) return mx_strdup(str);
        
	int subl = mx_strlen(sub);
	int repl = mx_strlen(replace);
	int strl = mx_strlen(str);

        int len = strl + (cnt * (repl - subl));

        char *res = mx_strnew(len);

	int p = 0;
	int x = mx_get_substr_index(str, sub);
	
	for(int i = 0; i < len; i++) {
		if(p < x) {
			res[i] = str[p++];
		}
		else {
			res[i] = '\0';
			mx_strcat(res, replace);
			p += subl;
			i += repl - 1;
			x = mx_get_substr_index(str + p, sub);
			x += p;
		}
	}
	return res;

}
