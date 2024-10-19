#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

int **load_edges(const char *filename, int *edge_count, char ***island_names, int *node_count) {
    int fd = open(filename, O_RDONLY);

    char *line_buffer;
    int bytes_read = mx_read_line_buff(&line_buffer, 64, '\n', fd, false);
    if (bytes_read <= 0) {
        free(line_buffer);
        close(fd);
        return NULL; 
    }

    int expected_nodes = pathfinder_atoi(line_buffer);
    free(line_buffer);

    char **islands = (char **)malloc(0);
    int actual_nodes = 0;
    int **edges = (int **)malloc(0);
    int edges_count = 0;

    char *first_island = NULL;
    char *second_island = NULL;
    char *weight_str = NULL;
    int first_id, second_id, weight;

    while ((bytes_read = mx_read_line_buff(&first_island, 64, '-', fd, false)) != -1) {
        if (bytes_read == 0 || !is_valid_string(first_island)) {
            free(first_island);
            continue; 
        }

        first_id = get_index(islands, actual_nodes, first_island);
        if (first_id == -1) {
            first_id = actual_nodes;
            add_to_strarr(&islands, &actual_nodes, first_island);
        } else {
            free(first_island);
        }

        bytes_read = mx_read_line_buff(&second_island, 64, ',', fd, false);
        if (bytes_read == 0 || !is_valid_string(second_island)) {
            free(second_island);
            continue; // Пропускаем некорректные строки
        }

        second_id = get_index(islands, actual_nodes, second_island);
        if (second_id == -1) {
            second_id = actual_nodes;
            add_to_strarr(&islands, &actual_nodes, second_island);
        } else {
            free(second_island);
        }

        bytes_read = mx_read_line_buff(&weight_str, 64, '\n', fd, false);
        if (bytes_read == 0) {
            free(weight_str);
            continue; 
        }

        weight = pathfinder_atoi(weight_str);
        free(weight_str);

        if (weight == -1 || first_id == second_id) {
            continue; 
        }

        add_edge(&edges, &edges_count, first_id, second_id, weight);
    }
    close(fd);

    if (expected_nodes != actual_nodes || contains_duplicate_edges(edges, edges_count) || is_weight_sum_excessive(edges, edges_count)) {
        delete_int_array(&edges, edges_count);
        delete_str_array(&islands, actual_nodes);
    }

    *edge_count = edges_count;
    *island_names = islands;
    *node_count = actual_nodes;

    return edges;
}
