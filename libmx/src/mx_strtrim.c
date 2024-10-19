#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) 
        return NULL; 

    int start = 0;
    while (mx_isspace(str[start])) 
        start++;

    int end = 0;
    while (str[end] != '\0')   
        end++;

    end--;

    while (end >= start && mx_isspace(str[end])) 
        end--;

    int new_str_len = end - start + 1;
    char *trimmed_str = mx_strnew(new_str_len + 1);   
    
    for (int i = 0; i < new_str_len; i++) 
        trimmed_str[i] = str[start + i];
    
    trimmed_str[new_str_len] = '\0'; 
    return trimmed_str;
}
