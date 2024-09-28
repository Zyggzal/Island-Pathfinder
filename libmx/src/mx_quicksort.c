#include "../inc/libmx.h"

void swap(char** s1, char** s2, int* count) {
	char* tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
	(*count)++;
}

int partition(char **arr, int left, int right, int* count) {
    	char* p = arr[(left + right) / 2];
    	int i = left;
    	int j = right;

    	while (i < j) {
        	while (mx_strlen(arr[i]) <= mx_strlen(p) && i <= right - 1) {
            		i++;
        	}
        	while (mx_strlen(arr[j]) >= mx_strlen(p) && j >= left + 1) {
            		j--;
        	}
        	if (i < j) {
           		swap(&arr[i], &arr[j], count);		
        	}
    	}
    	swap(&arr[left], &arr[j], count);
    	return j;
}

int mx_quicksort(char** arr, int left, int right) {
	if(!arr) {
		return -1;
	}	
	int count = 0;
     	if (left < right) {
        	int pi = partition(arr, left, right, &count);
		count += mx_quicksort(arr, left, pi - 1);
        	count += mx_quicksort(arr, pi + 1, right);
    	}
	return count;
}

