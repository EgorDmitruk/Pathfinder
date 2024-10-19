#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

bool is_weight_sum_excessive(int **edges, int count) {
    int total = edges[0][2];
    
    for (int i = 1; i < count; i++) {
        if (INT_MAX - edges[i][2] < total) {
            return true;
        }
    }
    return false;
}
