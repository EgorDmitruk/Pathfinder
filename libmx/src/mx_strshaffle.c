#include "../inc/libmx.h"

void mx_strshaffle(char *str) {
    int lenght = mx_strlen(str);
    int left = 0;
    int right = lenght - 1; 
    while(left < right) {
        char buff = str[left];
        str[left] = str[right];
        str[right] = buff;
        left++;
        right--;
    }
}
