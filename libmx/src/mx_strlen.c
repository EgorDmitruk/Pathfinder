#include "../inc/libmx.h"

int mx_strlen(const char *s) {
	int number = 0;
	while(s[number] != '\0')
		number++;
	return number;
}
