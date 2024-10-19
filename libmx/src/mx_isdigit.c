#include "../inc/libmx.h"

int mx_isdigit(int n) {
    if((n >= '0') && (n <= '9')) return 1;
    return 0;
}
