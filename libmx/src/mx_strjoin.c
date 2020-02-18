#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {

	if (s1 == NULL && s2 == NULL)
		return NULL;
	if (s1 != NULL && s2 == NULL)
		return mx_strdup(s1);
	if (s1 == NULL && s2 != NULL)
		return  mx_strdup(s2);
	if (s1 != NULL && s2 != NULL) {
		char *res = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
		res = mx_strcat(mx_strcpy(res, s1), s2);
		return res;
	}
	return NULL;
}
