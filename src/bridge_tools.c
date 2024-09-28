#include "../inc/pathfinder.h"

int count_bridges(t_bridge** arr) {
    if (!arr) return 0;
    int count = 0;
    while (*arr) {
        count++;
        arr++;
    }

    return count;
}

t_barr* append_bridge(t_barr* arr, t_bridge* i) {
    if (!i) return NULL;
    t_barr* tmp = (t_barr*)malloc(sizeof(t_barr));

    int count = arr ? arr->count : 0;

    tmp->count = count + 1;
    tmp->bridges = (t_bridge**)malloc(sizeof(t_bridge*) * tmp->count);
    for (int i = 0; i < count; i++) {
        tmp->bridges[i] = arr->bridges[i];
    }
    tmp->bridges[count] = i;

    return tmp;
}

int count_distance(t_barr* path) {
    if (!path) return 0;
    int count = 0;
    for (int i = 0; i < path->count; i++) {
        count += path->bridges[i]->length;
    }
    return count;
}

bool contains(t_barr* arr, t_bridge* e) {
    if (!arr) return false;
    for (int i = 0; i < arr->count; i++) {
        if (arr->bridges[i] == e)return true;
    }
    return false;
}

bool is_duplicate (t_barr* arr, t_bridge* e) {
    if (!arr) return false;
    for (int i = 0; i < arr->count; i++) {
        if (arr->bridges[i]->islandA == e->islandA && arr->bridges[i]->islandB == e->islandB)return true;
	if (arr->bridges[i]->islandA == e->islandB && arr->bridges[i]->islandB == e->islandA)return true;
    }
    return false;
}

char** get_next_stop(t_bridge* b, char** stop) {
    if (!b) return NULL;
    if (b->islandA == stop) return b->islandB;
    else if (b->islandB == stop) return b->islandA;
    else return NULL;
}

void free_bridge_array(t_barr** arr) {
    if (!*arr) return;
    free((*arr)->bridges);
    free(*arr);
    *arr = NULL;
}

