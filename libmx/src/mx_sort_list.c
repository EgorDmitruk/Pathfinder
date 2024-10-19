#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    int list_size = mx_list_size(lst);
    t_list *ptr, *last = NULL;

    for(int i = 0; i < list_size; i++) {
        ptr = lst;
        while(ptr->next != last) {
            if(cmp(ptr->data, ptr->next->data)) {
                void *temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
            }
            ptr = ptr->next; 
        }
        last = ptr;
    }
    return lst;
}
