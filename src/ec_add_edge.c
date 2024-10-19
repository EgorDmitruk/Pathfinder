#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

void add_edge(int ***edges, int *count, int node1, int node2, int weight) {
    *edges = (int **)mx_realloc(*edges, (*count + 1) * sizeof(int *));
    int *edge = (int *)malloc(3 * sizeof(int));

    edge[0] = node1;
    edge[1] = node2;
    edge[2] = weight;
    
    (*edges)[*count] = edge;
    (*count)++;
}
