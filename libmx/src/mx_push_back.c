#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    if(data == NULL)
        return;

    t_list *new_node = mx_create_node(data);
    if(new_node == NULL)
        return;
    if(*list == NULL) {
        *list = new_node;
        return;
    }

    t_list *ptr = *list;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = new_node;
}

