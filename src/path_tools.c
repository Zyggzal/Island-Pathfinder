#include "../inc/pathfinder.h"

void free_path_array(t_paths** arr) {
    if (!*arr) return;
    if ((*arr)->count > 0) {
        for (int i = 0; i < (*arr)->count; i++) {
            free_bridge_array(&((*arr)->paths[i]));
        }
        free((*arr)->paths);
    }
    (*arr)->paths = NULL;
    (*arr)->count = 0;
}

void append_path(t_paths* arr, t_barr* i) {
    if (!i) return;
    t_barr** tmp = (t_barr**)malloc(sizeof(t_barr*) * (arr->count + 1));

    for (int i = 0; i < arr->count; i++) {
        tmp[i] = arr->paths[i];
    }
    tmp[arr->count] = i;

    if(arr->paths)free(arr->paths);
    arr->paths = tmp;
    arr->count++;
}

