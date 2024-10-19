#include "../inc/libmx.h"

int mx_atoi(char *s) {
    int k = 0;
    while (*s) {
        k = (k << 3) + (k << 1) + (*s) - '0';
        s++;
     }
     return k;
}
