#include "../inc/libmx.h"

void delete_str_array(char*** arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        free((*arr)[i]);
    }
    free(*arr);
}

