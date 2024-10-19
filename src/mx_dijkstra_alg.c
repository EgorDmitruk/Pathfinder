#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

int** dijkstra_alghoritm(int*** graph, int* graph_rows_lengths, int start_node, int total_nodes, int **distances_ptr, int **parent_counts_ptr) {
    
    int* distances = (int*)malloc(total_nodes * sizeof(int));
    int* parent_counts = (int*)malloc(total_nodes * sizeof(int));
    int** parents = (int**)malloc(total_nodes * sizeof(int*));

    for (int i = 0; i < total_nodes; i++) {
        parents[i] = (int*)malloc(sizeof(int));
        parents[i][0] = -1; 
        parent_counts[i] = 0;
    }

    MinHeap* min_heap = createMinHeap(total_nodes);

    for (int i = 0; i < total_nodes; i++) {
        if (i == start_node) continue;

        distances[i] = INT_MAX;
        min_heap->array[i] = createMinHeapNode(i, distances[i]);
        min_heap->pos[i] = i;
    }

    min_heap->array[start_node] = createMinHeapNode(start_node, 0);
    min_heap->pos[start_node] = start_node;
    distances[start_node] = 0;
    updateKey(min_heap, start_node, distances[start_node]);
    min_heap->size = total_nodes;

    //dopisat bo ne rabotaet poisk last node blin
    while (!isEmpty(min_heap)) {
        MinHeapNode* min_heap_node = removeMin(min_heap);
        int current_node = min_heap_node->id;
        free(min_heap_node);

        for (int i = 0; i < graph_rows_lengths[current_node]; i++) {
            int neighbor = graph[current_node][i][0];
            int weight = graph[current_node][i][1];

            if (!isNodeInMinHeap(min_heap, neighbor) || distances[current_node] == INT_MAX) 
                continue;
            
            if (distances[current_node] + weight < distances[neighbor]) {
                distances[neighbor] = distances[current_node] + weight;
                parents[neighbor] = (int*)mx_realloc(parents[neighbor], sizeof(int));
                parents[neighbor][0] = current_node;
                parent_counts[neighbor] = 1;
                updateKey(min_heap, neighbor, distances[neighbor]);
            }
            //fix segfolt
            else if (distances[current_node] + weight == distances[neighbor]) {
                parents[neighbor] = (int*)mx_realloc(parents[neighbor], (parent_counts[neighbor] + 1) * sizeof(int));
                parents[neighbor][parent_counts[neighbor]] = current_node;
                parent_counts[neighbor]++;
            }
        }
    }

    free(min_heap->array);
    free(min_heap->pos);
    free(min_heap);

    *distances_ptr = distances;
    *parent_counts_ptr = parent_counts;

    return parents;
}
