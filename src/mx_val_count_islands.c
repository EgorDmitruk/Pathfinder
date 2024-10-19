#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

int mx_count_islands(const char *file) {
    char *str = NULL;
    char **buffer = malloc(0); 
    int capacity = 0; 
    int i = 0;
    int num;
    int fd = open(file, O_RDONLY);

    while (1) {
        num = mx_read_line(&str, 30, '\n', fd);
        if (num <= 0) break; 

        int sub_pos = mx_get_substr_index(str, "-");
        if (sub_pos == -1) continue;

        if (i >= capacity) {
            capacity += 10; 
            buffer = mx_realloc(buffer, capacity * sizeof(char *));
            for (int j = i; j < capacity; j++) {
                buffer[j] = malloc(30 * sizeof(char)); 
            }
        }

        mx_strncpy(buffer[i], str, sub_pos);
        buffer[i][sub_pos] = '\0'; 

        int comma_pos = mx_get_substr_index(str + sub_pos + 1, ",");
        if (comma_pos != -1) {
            mx_strncpy(buffer[i + 1], str + sub_pos + 1, comma_pos);
            buffer[i + 1][comma_pos] = '\0'; 
            // printf("word_c #%i: %s\n", i + 1, buffer[i + 1]);
        }

        //printf("word #%i: %s\n", i, buffer[i]);
        i += 2; 
    }

    int list_length = i;
    for (int a = 0; a < list_length; a++) {
        for (int b = a + 1; b < list_length; b++) {
            if (mx_strcmp(buffer[a], buffer[b]) == 0) {
                free(buffer[b]);
                for (int k = b; k < list_length - 1; k++) {
                    buffer[k] = buffer[k + 1];
                }
                list_length--;
                b--;
            }
        }
    }
    for (int j = 0; j < list_length; j++) 
        free(buffer[j]);

    free(buffer);
    free(str); 
    close(fd);

    return list_length;
}
