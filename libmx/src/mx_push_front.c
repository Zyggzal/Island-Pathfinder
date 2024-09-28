#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data) {
	if(list == NULL || *list == NULL) {
		*list = mx_create_node(data);
		return;
	}
	t_list *tmp = mx_create_node(data);
	t_list *l = *list;
	tmp->data = data;
	tmp->next = l;
	*list = tmp;
}
