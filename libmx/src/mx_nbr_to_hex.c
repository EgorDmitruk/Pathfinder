#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) {
        char *result = (char *)malloc(2);
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    char *hexadecimal = (char *)malloc(17);  
    if (!hexadecimal) return NULL;

    int i = 0;

    while (nbr != 0) {
        int temp = nbr % 16;  
        
        if (temp < 10)
            hexadecimal[i] = temp + '0'; 
        else
            hexadecimal[i] = temp + 'a' - 10; 
    
        nbr = nbr / 16;  
        i++;
    }

    hexadecimal[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = hexadecimal[j];
        hexadecimal[j] = hexadecimal[i - j - 1];
        hexadecimal[i - j - 1] = temp;
    }

    return hexadecimal;  
}
