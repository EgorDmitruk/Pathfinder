#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    for (unsigned char *p = b; len > 0; len--) {
        *p = c;
        p++;
    }
    return b;
}
