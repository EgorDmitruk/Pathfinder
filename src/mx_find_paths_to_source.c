#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

void find_paths_to_source(int ***all_paths, int **path_lengths, 
                            int *path_count, int **parents, 
                            int *parent_counts, int *current_path, 
                            int current_length, int source, int child) {
    
    if (child == source) {
        add_to_intarr(&current_path, &current_length, source);
        
        int length = *path_count;
        add_to_intarr(path_lengths, &length, current_length);
        
        add_to_intptrarr(all_paths, path_count, current_path);
        return;
    }

    for (int i = 0; i < parent_counts[child]; i++) {
        int *new_path = (int *)malloc((current_length + 1) * sizeof(int));
        copy_int_array(&new_path, current_path, current_length);

        new_path[current_length] = child; 

        find_paths_to_source(all_paths, path_lengths, path_count,
                             parents, parent_counts,
                             new_path, current_length + 1, source, parents[child][i]);
    }

    free(current_path); 
}
