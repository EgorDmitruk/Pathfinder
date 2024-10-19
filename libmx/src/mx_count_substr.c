#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if(sub == NULL || str == NULL)
        return -1;
    else if(sub[0] == '\0')
        return 0;

    int subs_amount = 0;
    int index = 0;

    while((index = mx_get_substr_index(str, sub))>= 0) {
        subs_amount++;
        str += index + mx_strlen(sub); 
    }
    return subs_amount;
}
