#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const char *str1 = s1;
    const char *str2 = s2;
    size_t i;

    for(i = 0; i < n; i++, str1++, str2++) {
        if(*str1 > *str2)
            return 1;
        else if(*str2 > *str1)
            return -1;
    }
    return 0;
}
