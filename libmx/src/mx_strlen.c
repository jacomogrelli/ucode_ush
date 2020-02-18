#include "libmx.h"

int mx_strlen(const char *s) {
	int i = 0;

	while(s && s[i]) {
		i++;
	}
	return i;
}
