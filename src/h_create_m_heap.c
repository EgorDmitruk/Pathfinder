#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    if (!minHeap) return NULL;

    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    if (!minHeap->pos) {
        free(minHeap);
        return NULL;
    }

    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    if (!minHeap->array) {
        free(minHeap->pos);
        free(minHeap);
        return NULL;
    }
    
    return minHeap;
}

