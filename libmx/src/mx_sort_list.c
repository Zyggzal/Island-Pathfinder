#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *)) {
	if(list == NULL || cmp == NULL) {
		return NULL;
	}
	bool change = true;
	while(change) {
		change = false;
		t_list *prev = NULL;
		t_list *cur = list;
		while(cur->next != NULL) {
			if(cmp(cur->data, cur->next->data)) {
				if(prev != NULL) {
					prev->next = cur->next;
				}
				t_list *tmp = cur->next;
				cur->next = tmp->next;
				tmp->next = cur;
				change = true;
			}
			if(prev != NULL) {
				prev = prev->next;
			} else {
				prev = list;
			}
			cur = prev->next;
		}
	}
	return list;
}
