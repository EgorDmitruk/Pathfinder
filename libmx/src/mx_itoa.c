#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    int number = 0;
    while(s[number] != '\0')
	    number++;
    return number;
}

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

char *mx_itoa(int number) {
    char *str = (char *)malloc(12);
    int i = 0;
    int sign = number;
    
    if(number == 0) {
        str[i++] = '0';
    } else if (number < 0) {
        number = -number;
        str[i++] = '-';
    }

    while(number > 0) {
        str[i++] = number % 10 + '0';
        number /= 10;
    }

    str[i] = '\0';
    if (sign < 0 || str[0] == '0') {
        mx_strshaffle(str + (sign < 0 ? 1 : 0)); 
    } else {
        mx_strshaffle(str);
    }
    return str;
}
