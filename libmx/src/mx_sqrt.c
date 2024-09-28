#include "../inc/libmx.h"

int mx_sqrt(int x) {
	if (x <= 0 || x > 2147395600) return 0;
	unsigned int n = x;

	for(unsigned int i = 1; i <= (n / 2) + 1; i++) {
		if(i * i == n) {
			return i;
		}
	}
	return 0;
}
