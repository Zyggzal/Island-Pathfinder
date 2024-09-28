#include "../inc/libmx.h"

void mx_printint(int n) {
    int c = 0;
    int num = n;
    int d = 1;

    if(n < 0) {
        mx_printchar('-');
            n = n * (-1);
            num = n;
    }
    if(n == 0) {
        mx_printchar('0');
    }
    while(n != 0) {
        n /= 10;
        ++c;
    }
    for(int i = 1; i < c; ++i) {
        d = d * 10;
    }
    while(num > 0) {
        int dig = num / d + 48;
        mx_printchar(dig);
        --c;
	num %= d;
        d = d / 10;
    }
    while (c) {
        mx_printchar('0');
        --c;
    }
}
