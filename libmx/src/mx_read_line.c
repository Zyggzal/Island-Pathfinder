#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
	if(fd < 0)return -2;
	char *buf = mx_strnew(buf_size);
	static char* left = NULL;
	int ret = 0;
	int tmp = 0;
	*lineptr = NULL;
	if(left) {
		int d = mx_get_char_index(left, delim);
		if(d != -1) {
			left[d] = '\0';
			*lineptr = mx_strdup(left);
			char* t = &left[d + 1];
			mx_strdel(&left);
			left = t;
			return mx_strlen(*lineptr);
		}
		else {
			ret += mx_strlen(left);
			*lineptr = mx_strjoin_free(*lineptr, left);
			mx_strdel(&left);
		}
	}
	while((tmp = read(fd, buf, buf_size)) > 0) {
		int d = mx_get_char_index(buf, delim);
		if(d == -1) {
			ret += tmp;
			*lineptr = mx_strjoin_free(*lineptr, buf);
		}
		else {
			if(buf_size == 1)break;
			buf[d] = '\0';			
			*lineptr = mx_strjoin_free(*lineptr, buf);
			if(d < tmp - 1) {
				left = mx_strdup(&buf[d + 1]);
			}
			ret += d;
			free(buf);
			return ret;
		}
	}
	free(buf);
	if(ret == 0) {
		return -1;
	}
	return ret;
}
