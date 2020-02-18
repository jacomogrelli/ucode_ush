#include "libmx.h"

int mx_sqrt(int x) {
	if (x == 0) {
		return 0;
	}
	if (x == 1) {
		return 0;
	}
	if (x < 0) {
		return 0;
	}
	for (int res = 1; res <= 46340;) {
		if (res * res == x)
			return res;
		else
			res++;
	}
	return 0;
}

