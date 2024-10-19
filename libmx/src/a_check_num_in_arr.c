#include "../inc/libmx.h"

bool is_arr_cont_int(int* arr, int arr_size, int num) {
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}

