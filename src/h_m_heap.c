#include "../libmx/inc/libmx.h"
#include "../inc/header.h"
//hell this shit isnt working
void minHeapify(MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // check left node
    if (left < minHeap->size && minHeap->array[left]->weight < minHeap->array[smallest]->weight) {
        smallest = left;
    }
    // check right node
    if (right < minHeap->size && minHeap->array[right]->weight < minHeap->array[smallest]->weight) {
        smallest = right;
    }

    if (smallest != index) {
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *currentNode =  minHeap->array[index];

        minHeap->pos[smallestNode->id] = index;
        minHeap->pos[currentNode->id] = smallest;

        swapNodes(&minHeap->array[smallest], &minHeap->array[index]);

        minHeapify(minHeap, smallest);
    }
}
  
