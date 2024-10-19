#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

void updateKey(MinHeap* minHeap, int id, int newWeight) {
    int index = minHeap->pos[id];

    minHeap->array[index]->weight = newWeight;

    while (index && minHeap->array[index]->weight < minHeap->array[(index - 1) / 2]->weight) {
        minHeap->pos[minHeap->array[index]->id] = (index - 1) / 2;
        minHeap->pos[minHeap->array[(index - 1) / 2]->id] = index;
        swapNodes(&minHeap->array[index], &minHeap->array[(index - 1) / 2]);

        index = (index - 1) / 2;
    }
}

