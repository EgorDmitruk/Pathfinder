#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

int get_index(char **arr, int size, const char *str) {
    for (int i = 0; i < size; i++) {
        if (mx_strcmp(arr[i], str) == 0) {
            return i;
        }
    }
    return -1;
}
