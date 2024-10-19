#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if(head == NULL || *head == NULL)
        return;
    else {
        t_list *ptr = *head;

        if(ptr->next == NULL) {
            free(ptr);
            *head = NULL;
            return;
        }
        while (ptr->next->next != NULL)
            ptr = ptr->next;

        t_list *last_node = ptr->next;
        ptr->next = NULL;
        free(last_node);

    }    
}
