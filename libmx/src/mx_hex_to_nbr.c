#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
	int len = mx_strlen(hex);
	if(len < 1) {
		return 0;
	}
	unsigned long num = 0;
	for(int i = 0; i < len; i++) {
		num *= 16;
		if(mx_isdigit(hex[i])) {
			num += hex[i] - 30;
		}
		else if(hex[i] >= 65 && hex[i] <= 70) {
			num += hex[i] - 55;
		}
		else if(hex[i] >= 97 && hex[i] <= 102) {
			num += hex[i] - 87;
		}
	}
	return num;
}

