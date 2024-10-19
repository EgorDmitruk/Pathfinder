#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (!arr)
        return -1;

    int swap_count = 0;

    if (left < right) {
        int i = left;
        int j = right;
        int mid = (left + right) / 2;
        char *pivot = arr[mid];

        while (i <= j) {
            while (mx_strlen(arr[i]) < mx_strlen(pivot)) 
                i++;
            while (mx_strlen(arr[j]) > mx_strlen(pivot)) 
                j--;

            if (i <= j) {
                if (mx_strlen(arr[j]) != mx_strlen(arr[i])) {
                    char *temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    swap_count++;
                }

                j--;
                i++;
            }
        }

        swap_count += mx_quicksort(arr, left, j);
        swap_count += mx_quicksort(arr, i, right);
    }
    return swap_count;
}
