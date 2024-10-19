#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

bool isNodeInMinHeap(MinHeap *minHeap, int id) {
    return minHeap->pos[id] < minHeap->size;
}
