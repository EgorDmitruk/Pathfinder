#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

void sortParents(int*** parents, int* parentCounts, int totalNodes) {
    for (int i = 0; i < totalNodes; i++) {
        if (parentCounts[i] <= 1) { continue; }
        int_quicksort(&((*parents)[i]), 0, parentCounts[i] - 1);
    }
}
