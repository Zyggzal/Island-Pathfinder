#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    if(!arr || !s || !count) {
        return -1;
    }
    int idx = (size / 2) - 1;
    idx = idx < 0 ? 0 : idx;
    int t = 0;
    while(*count <= size / 2) {
        int cmp = mx_strcmp(arr[idx], s);
        *count += 1;
        if(cmp < 0) {
            t = idx;
            idx = (idx + (size - idx) / 2) + 1;
        } else if (cmp > 0) {
            idx = (t + (idx - t) / 2);
        } else {
            return idx;
        }
    }
    *count = 0;
    return -1;
}

