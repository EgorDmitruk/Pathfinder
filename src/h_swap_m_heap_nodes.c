#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

void swapNodes(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

