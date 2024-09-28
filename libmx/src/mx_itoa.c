#include "../inc/libmx.h"

char *mx_itoa(int number) {
	int size = 0;
	bool neg = number < 0;

	if(neg) {
		size++;
		number *= -1;
	}
	else if (number == 0) {
		return mx_strdup("0");
	}
	else if (number == MIN_INT) {
		return mx_strdup("-2147483648");
	}
	int n = number;

	while(n > 0) {
		size++;
		n /= 10;	
	}
	n = number;
	char *str = mx_strnew(size + 1);
	str[size] = '\0';
	
	while(n > 0) {
		str[--size] = (n % 10) + 48;
		n /= 10;
	}

	if(neg) {
		str[0] = '-';
	}
	return str;
}
