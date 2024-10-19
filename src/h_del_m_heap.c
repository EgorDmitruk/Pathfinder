#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

void deleteMinHeap(MinHeap** minHeap) {
    if (minHeap && *minHeap) {
        for (int i = 0; i < (*minHeap)->size; i++) 
            free((*minHeap)->array[i]);
        
        free((*minHeap)->pos);
        free(*minHeap);
        *minHeap = NULL; 
    }
}
