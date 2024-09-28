#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
	if(list == NULL || *list == NULL) {
		*list = mx_create_node(data);
		return;
	}
	t_list *last = *list;
	while(last->next != NULL) {
		last = last->next;
	}
	last->next = mx_create_node(data);
}

