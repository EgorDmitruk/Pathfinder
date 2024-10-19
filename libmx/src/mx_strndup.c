#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if(s1 == NULL || n == 0)
        return NULL;

    size_t arr_size = mx_strlen(s1);
    size_t copy_size = (n < arr_size) ? n : arr_size;

    char *new_str = malloc(copy_size + 1);

    for(size_t i = 0; i < copy_size; i++) 
        new_str[i] = s1[i];

    new_str[copy_size] = '\0';
    return new_str;
}
