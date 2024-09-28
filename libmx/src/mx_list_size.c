#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
	t_list *cur = list;
	int size = 0;
	while(cur != NULL) {
		cur = cur->next;
		size++;
	}
	return size;
}
