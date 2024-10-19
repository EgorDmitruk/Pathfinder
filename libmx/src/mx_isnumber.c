#include "../inc/libmx.h"

bool mx_isnumber(const char *str) {
    int i = 0;
    
    if (str[0] == '\0')
        return false;
    
    if (str[0] == '-' || str[0] == '+')
        i++;
    
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    
    return true; 
}
