#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if(!str) {
        return NULL;
    }
    int len = 0;
    char *res = mx_strtrim(str);
    if(res == NULL) {
	return mx_strdup("");
    }
    for(int i = 0; i < mx_strlen(res) - 1; i++) {
        if(mx_isspace(res[i]) && mx_isspace(res[i + 1])) {
            len--;
        }
        len++;
    }
    if(len <= 0) {
	return mx_strdup("");
    }
    char *ret = mx_strnew(len);
    int j = 0;
    for(int i = 0; i < mx_strlen(res); i++) {
        if(!mx_isspace(res[i])) {
            ret[j] = res[i];
            j++;
        } else if(!mx_isspace(res[i + 1]) && res[i] == ' ') {
            ret[j] = res[i];
            j++;
        }
    }
    mx_strdel(&res);
    return ret;    
}
