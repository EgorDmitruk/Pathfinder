#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

void print_one_path(int* path_from_dst, int path_length, int* dist, int dst, int src, char** islands) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(islands[src]);
    mx_printstr(" -> ");
    mx_printstr(islands[dst]);
    mx_printstr("\n");
    
    mx_printstr("Route: ");
    for (int j = path_length - 1; j >= 0; j--) {
        if (j == 0) {
            mx_printstr(islands[path_from_dst[j]]);
            continue;
        }
        mx_printstr(islands[path_from_dst[j]]);
        mx_printstr(" -> ");
    }
    mx_printstr("\nDistance: ");
    if (path_length < 3) {
        mx_printint(dist[path_from_dst[0]]);
    }
    else {
        for (int j = path_length - 1; j >= 0; j--) {
            if (j == 0) {
                mx_printint(dist[path_from_dst[j]]);
                continue;
            }
            if (j == 1) {
                mx_printint(dist[path_from_dst[j - 1]] - dist[path_from_dst[j]]);
                mx_printstr(" = ");
                continue;
            }
            mx_printint(dist[path_from_dst[j - 1]] - dist[path_from_dst[j]]);
            mx_printstr(" + ");
        }
    }
    mx_printstr("\n========================================\n");
}
