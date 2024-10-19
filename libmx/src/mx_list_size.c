#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    int count = 0;
    t_list *ptr = list;

    while(ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

