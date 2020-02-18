#include "libmx.h"

void mx_printint(int n) {
	if (n == -2147483648) {
		mx_printstr("-2147483648");
		return;
	}
	if (n == 0) {
		mx_printchar('0');
		return;
	}
	if (n < 0) {
		mx_printchar('-');
		n = -n;
	}
	if (n/10) {
		mx_printint(n/10);
	}
	mx_printchar(n%10 + '0');
}

