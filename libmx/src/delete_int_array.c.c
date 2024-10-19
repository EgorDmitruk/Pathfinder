#include "../inc/libmx.h"

void delete_int_array(int*** arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        free((*arr)[i]);
    }
    free(*arr);
}

