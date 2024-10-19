#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

int*** create_djk_graph(int** edges, int edges_count, int nodes_count, int* graph_rows_lengths) {
    
    int*** graph = (int***)malloc(sizeof(int**) * nodes_count);
    
    for (int i = 0; i < nodes_count; i++) {
        graph[i] = NULL; 
        graph_rows_lengths[i] = 0; 
    }

    for (int i = 0; i < edges_count; i++) {
        int* edge_from = (int*)malloc(sizeof(int) * 2);
        edge_from[0] = edges[i][1];
        edge_from[1] = edges[i][2];

        add_to_intptrarr(&graph[edges[i][0]], &graph_rows_lengths[edges[i][0]], edge_from);

        int* edge_to = (int*)malloc(sizeof(int) * 2);
        edge_to[0] = edges[i][0];
        edge_to[1] = edges[i][2];

        add_to_intptrarr(&graph[edges[i][1]], &graph_rows_lengths[edges[i][1]], edge_to);
    }

    return graph;
}

void free_graph_full(int*** graph, int nodes_count) {
    for (int i = 0; i < nodes_count; i++) 
        free(graph[i]); 

    free(graph); 
}
