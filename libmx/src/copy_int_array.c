#include "../inc/libmx.h"

void copy_int_array(int** dst, int*src, int size) {
    for (int i = 0; i < size; i++) {
        (*dst)[i] = src[i];
    }
}

