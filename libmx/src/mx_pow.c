#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
    if(pow == 0)
        return 1;
    else
        return n * mx_pow(n, pow - 1);
}
