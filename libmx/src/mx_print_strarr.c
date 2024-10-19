#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if(arr == NULL || delim == NULL) 
        exit(1);

    for(int i = 0; arr[i] != NULL; i++) {
        mx_printstr(arr[i]);
        if(arr[i+1] != NULL)
            mx_printstr(delim);
    }
}
