#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if(str == NULL || sub == NULL || replace == NULL)
        return NULL;

    int str_len = mx_strlen(str);
    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);
    int sub_count = mx_count_substr(str, sub);
    char *new_str = malloc(str_len + sub_count * (replace_len - sub_len) + 1);
    if(new_str == NULL)
        return NULL;
    
    char *result = new_str;
    while(*str) {
        const char *pos = mx_strstr(str,sub);
        if(pos) {
            while(str < pos) {
                *result = *str;
                result++;
                str++;

            }
            for(int i = 0; i < replace_len; i++) {
                *result = replace[i];
                result++;
            }
            str += sub_len;
        } else {
            while(*str) {
                *result = *str;
                result++;
                str++;
            }
            *result = '\0';
            break;
        }
    }
    return new_str;
}
