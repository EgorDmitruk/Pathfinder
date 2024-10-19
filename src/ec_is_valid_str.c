#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

bool is_valid_string(const char *str) {
    if (*str == '\0') 
        return false;
        
    while (*str) {
        if (!mx_isalpha(*str)) 
            return false;
        str++;
    }
    return true;
}
