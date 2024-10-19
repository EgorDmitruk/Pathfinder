#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

MinHeapNode* removeMin(MinHeap* minHeap) {
    if (isEmpty(minHeap)) return NULL; 
 
    MinHeapNode* minNode = minHeap->array[0];
    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];

    minHeap->array[0] = lastNode;
    minHeap->pos[minNode->id] = minHeap->size - 1;
    minHeap->pos[lastNode->id] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return minNode;
}
