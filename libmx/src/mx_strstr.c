#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if(needle == NULL)
        return (char *) haystack;

    for(const char *h = haystack; *h != '\0'; h++) {            
        const char *n = needle;
        const char *h_buf = h;

        while (*h_buf == *n && *n != '\0') {
            h_buf++;
            n++;
        }

        if (*n == '\0') 
            return (char *) h;
    }

    return NULL;
}
