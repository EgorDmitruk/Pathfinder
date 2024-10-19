#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

bool contains_duplicate_edges(int **edges, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (are_edges_equal(edges[i], edges[j])) {
                return true;
            }
        }
    }
    return false;
}

