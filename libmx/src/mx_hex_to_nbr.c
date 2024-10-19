#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL) 
        return 0; 

    unsigned long result = 0;

    for (int i = 0; hex[i] != '\0'; i++) {
        char current_char = hex[i];
        result *= 16; 

        if (current_char >= '0' && current_char <= '9') {
            result += current_char - '0'; 
        }
        else if (current_char >= 'a' && current_char <= 'f') {
            result += current_char - 'a' + 10;  
        }
        else if (current_char >= 'A' && current_char <= 'F') {
            result += current_char - 'A' + 10;  
        }
        else 
            return 0;  
    }

    return result;
}
