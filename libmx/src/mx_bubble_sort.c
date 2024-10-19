#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int swap_count = 0;
    int swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            int cmp_result = 0;
            for (int k = 0; arr[j][k] != '\0' || arr[j + 1][k] != '\0'; k++) {
                if (arr[j][k] != arr[j + 1][k]) {
                    cmp_result = (unsigned char)arr[j][k] - (unsigned char)arr[j + 1][k];
                    break;
                }
            }

            if (cmp_result > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap_count++;
                swapped = 1;
            }
        }
        if (!swapped) 
            break;
    }
    return swap_count;
}

