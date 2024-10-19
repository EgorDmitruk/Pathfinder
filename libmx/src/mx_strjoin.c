#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    char *buff;
    
    if(s1 == NULL && s2 == NULL)
        return NULL;
    else if(s1 == NULL) {
        buff = mx_strdup(s2);
        return buff;
    }
    else if(s2 == NULL) {
        buff = mx_strdup(s1);
        return buff;
    }

    buff = mx_strdup(s1);
    char *new_str = mx_strcat(buff, s2);
    return new_str;
}

