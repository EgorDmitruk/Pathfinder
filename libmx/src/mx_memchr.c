#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *str = s;
    unsigned char ch = (unsigned char)c;

    for(size_t i = 0; i < n; i++) 
        if(str[i] == ch) 
            return(void *)(str + i);
    return NULL;
}

