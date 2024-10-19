#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

int main(int argc, char *argv[]) {
    char buff[32];
    char *str;

    if(argc != 2) {
        mx_printstr("usage: ./pathfinder [filename]\n");
        exit(1);
    } 
    else if((open(argv[1], O_RDONLY)) == -1) {
        mx_printstr("error: file ");
        mx_printstr(argv[1]);
        mx_printstr(" does not exist\n");
        exit(2);
    }
    else if(read((open(argv[1], O_RDONLY)), buff, 1) == 0) {
        mx_printstr("error: file ");
        mx_printstr(argv[1]);
        mx_printstr(" is empty\n");
        exit(3);
    }
    else if(mx_read_line(&str, 1, '\n', open(argv[1], O_RDONLY)) != 1) {
        mx_printstr("error: line 1 is not valid\n");
        exit(4);
    }

    else if(mx_check_lines(argv[1]) != 0) {
        mx_printstr("error: line ");
        mx_printint(mx_check_lines(argv[1]));
        mx_printstr(" is not valid\n");
        exit(5);
    }
    else if(mx_line_compare(argv[1]) != 0) {
        mx_printstr("error: line ");
        mx_printint(mx_line_compare(argv[1]));
        mx_printstr(" is not valid\n");
        exit(5);
    }

    int num = mx_atoi(str);
    if(mx_count_islands(argv[1]) != num) {
        mx_printstr("error: invalid number of islands\n");
        exit(6);
    }
    else if(mx_check_duplicate(argv[1]) != 0) {
        mx_printstr("error: duplicate bridges\n");
        exit(7);
    }
    else if(mx_check_b_sum(argv[1]) == -1) {
        mx_printstr("error: sum of bridges lengths is too big\n");
        exit(7);
    }

    char** islands;
    int nodes_count = 0;
    int edges_count = 0;
    int **edges = load_edges(argv[1], &edges_count, &islands, &nodes_count);

    int* graph_info_rows_length = (int*)malloc(sizeof(int) * nodes_count);
    for (int i = 0; i < nodes_count; i++) {
        graph_info_rows_length[i] = 0;
    }
    int*** graph_info = create_djk_graph(edges, edges_count, nodes_count, graph_info_rows_length);

    int* procesed_islands = (int*)malloc(0);

    for (int src = 0; src < nodes_count; src++) {
        int* dist;
        int* parent_count;
        int** parents = dijkstra_alghoritm(graph_info, graph_info_rows_length, src, nodes_count, &dist, &parent_count);

        printPaths(parents, parent_count, dist, islands, src, nodes_count, procesed_islands, src);
    
        delete_int_array(&parents, nodes_count);
        free(parent_count);
        free(dist);
        procesed_islands = (int*)mx_realloc(procesed_islands, (src+1) * sizeof(int));
        procesed_islands[src] = src;
    }

    for (int i = 0; i < nodes_count; i++) {
        delete_int_array(&graph_info[i], graph_info_rows_length[i]);
    }
    free(graph_info);
    free(graph_info_rows_length);

    free(procesed_islands);
    
    delete_int_array(&edges, edges_count);
    delete_str_array(&islands, nodes_count);


    return 0;
}
