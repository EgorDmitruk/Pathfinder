#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left = 0;
    int right = size - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        int result = 9999;
        (*count)++;

        if (s == arr[mid])
            result = 0;
        if (result == 0)
            return mid;
        if (s > arr[mid])
            left = mid + 1;
        else   
            right = mid - 1;

    }

   return -1;
    
}

