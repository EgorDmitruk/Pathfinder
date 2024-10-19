#include "../inc/libmx.h"

// void mx_strshaffle(char *str) {
//     int lenght = mx_strlen(str);
//     int left = 0;
//     int right = lenght - 1; 
//     while(left < right) {
//         char buff = str[left];
//         str[left] = str[right];
//         str[right] = buff;
//         left++;
//         right--;
//     }
// }

void mx_printint(int n) {
    char str[12];
    int i = 0;
    int sign = n;
    
    if(n == 0) {
        str[i++] = '0';
    } else if (n < 0) {
        n = -n;
        str[i++] = '-';
    }

    while(n > 0) {
        str[i++] = n % 10 + '0';
        n /= 10;
    }

    str[i] = '\0';
    if (sign < 0 || str[0] == '0') {
        mx_strshaffle(str + (sign < 0 ? 1 : 0)); 
    } else {
        mx_strshaffle(str);
    }

    mx_printstr(str);
}
