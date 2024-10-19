#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if(str == NULL)
        return NULL;
    
    char *half_clear_str = mx_strtrim(str);
    if(half_clear_str == NULL)
        return NULL;

    char *clear_str = mx_strnew(mx_strlen(half_clear_str));
    if(clear_str == NULL)
        return NULL;
    
    int j = 0;
    bool in_space = false;
  
    for (int i = 0; i < mx_strlen(half_clear_str); i++) {
        if(mx_isspace(half_clear_str[i])) { 
            if(!in_space) {
                clear_str[j++] = ' ';
                in_space = true;
            }
        } else {
            clear_str[j++] = half_clear_str[i];
            in_space = false;
        }    
    }
    clear_str[j] = '\0';
    free(half_clear_str);
    return clear_str;
}

