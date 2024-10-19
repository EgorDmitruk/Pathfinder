#include "../inc/libmx.h"

int mx_n_len(int number) {
    int len = 0;

    if (number == 0) 
        return 1;

    long long n = (long long) number;

    n = (n < 0) ? -n : n;

    while (n > 0) {
        len++;
        n /= 10; 
    }

    return len;
}
