#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

MinHeapNode* createMinHeapNode(int id, int weight) {
    MinHeapNode* node = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    if (!node) return NULL; 

    node->id = id;
    node->weight = weight;
    
    return node;
}
