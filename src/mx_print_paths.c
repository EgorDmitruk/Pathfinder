#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

void printPaths(int** parents, int* parentCounts, int* distances, char** islands, int src, int totalNodes, int* processedNodes, int processedNodesCount) {
    sortParents(&parents, parentCounts, totalNodes);

    for (int child = 0; child < totalNodes; child++) {
        if (child == src || is_arr_cont_int(processedNodes, processedNodesCount, child)) { continue; }

        int** pathsToSrc = NULL;
        int* pathLengths = NULL;
        int pathCount = 0;

        find_paths_to_source(&pathsToSrc, &pathLengths, &pathCount, parents, parentCounts, NULL, 0, src, child);

        for (int i = 0; i < pathCount; i++) 
            print_one_path(pathsToSrc[i], pathLengths[i], distances, child, src, islands);
        

        delete_int_array(&pathsToSrc, pathCount);
        free(pathLengths);
    }
}


