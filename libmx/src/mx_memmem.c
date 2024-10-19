#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (little_len == 0) 
        return (void *)big; 

    const char *buffer = (const char *)big;
    const char *pt = (const char *)little;
    const char *p = buffer;

    while ((big_len - (p - buffer)) >= little_len) {
        p = mx_memchr(p, (int)(*pt), big_len - (p - buffer));
        if (p != NULL) {
            if (mx_memcmp(p, little, little_len) == 0) 
                return (void *)p; 
            else 
                ++p; 
        } else {
            break; 
        }
    }
    return NULL; 
}

