#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

void mx_copy_from_char(char *dst,const char *src, int start, char ch) {
    int i = 0;
    start += 1;

    while (src[start] != ch) {
        dst[i] = src[start];
        i++;
        start++;
    }
    dst[i] = '\0';  
}
