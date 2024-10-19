#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    if(s1 == NULL)
        return NULL;

    size_t arr_size = mx_strlen(s1);
    char *new_str = malloc(arr_size + 1);

    for(size_t i = 0; i < arr_size; i++) 
        new_str[i] = s1[i];

    new_str[arr_size] = '\0';
    return new_str;
}
