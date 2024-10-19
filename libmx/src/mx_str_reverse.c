#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    if (s == NULL) return;
    
    char *ptr_start = s;
    char *ptr_end = s + mx_strlen(s) - 1;
    char temp;

    for(int i = 0; i < mx_strlen(s) / 2; i++) {
        temp = *ptr_end;
        *ptr_end = *ptr_start;
        *ptr_start = temp;

        ptr_start++;
        ptr_end--;
    }
}
