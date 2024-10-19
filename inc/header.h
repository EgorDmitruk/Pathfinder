#ifndef HEADER_H
#define HEADER_H
#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> 
#include <stddef.h>
#include <stdbool.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

int mx_atoi(char *s);
int mx_isdigit(int n);
int mx_isalpha(int c);
bool mx_isnumber(const char *str);
void mx_strshaffle(char *str);
int mx_count_lines(const char *file);
int mx_check_lines(const char *file);
void mx_copy_from_char(char *dst,const char *src, int start, char ch); 
int mx_line_compare(const char *file);
int mx_check_duplicate(const char *file);
int mx_check_b_sum(const char *file);
int mx_count_islands(const char *file);

void add_edge(int ***edges, int *count, int node1, int node2, int weight);
bool contains_duplicate_edges(int **edges, int count);
bool are_edges_equal(int *edge1, int *edge2);
bool is_weight_sum_excessive(int **edges, int count);
int get_index(char **arr, int size, const char *str);
bool is_valid_string(const char *str);

typedef struct MinHeapNode {
    int id;
    int weight;
}              MinHeapNode;

typedef struct MinHeap {
    int size;     
    int capacity;  
    int *pos;    
    MinHeapNode **array;
}              MinHeap;



int **load_edges(const char *filename, int *edge_count, char ***island_names, int *node_count);
int*** create_djk_graph(int** edges, int edges_count, int nodes_count, int* graph_rows_lengths);
int** dijkstra_alghoritm(int*** graph, int* graph_rows_lengths, int start_node, int total_nodes, int **distances_ptr, int **parent_counts_ptr);
void printPaths(int** parent, int* parent_count, int* dist, char** islands, int src, int nodes_count, int* processed_nodes, int processed_nodes_count);
void find_paths_to_source(int ***all_paths, int **path_lengths, int *path_count,
                           int **parents, int *parent_counts,
                           int *current_path, int current_length, int source, int child);
void print_one_path(int* path_from_dst, int path_length, int* dist, int dst, int src, char** islands);
void sortParents(int*** parents, int* parentCounts, int totalNodes);


MinHeapNode* createMinHeapNode(int id, int weight);
//MinHeapNode* newMinHeapNode(int v, int dist);
MinHeap* createMinHeap(int capacity);
void del_minHeap(MinHeap** minHeap);
//void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b);
void swapNodes(MinHeapNode** a, MinHeapNode** b);
void minHeapify(MinHeap* minHeap, int idx);
int isEmpty(MinHeap* minHeap);
MinHeapNode* removeMin(MinHeap* minHeap);
void updateKey(MinHeap* minHeap, int id, int newWeight);
//void decreaseKey(MinHeap* minHeap, int v, int dist);
//bool isInMinHeap(MinHeap *minHeap, int v);
bool isNodeInMinHeap(MinHeap *minHeap, int id); 

#endif






