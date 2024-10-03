#ifndef PFNDR_H
#define PFNDR_H

#define BOUNDARY "========================================\n"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

typedef struct s_bridge {
    char** islandA;
    char** islandB;
    int length;
} t_bridge;

typedef struct s_barr {
    t_bridge** bridges;
    int count;
} t_barr;

typedef struct s_paths {
    t_barr** paths;
    int count;
} t_paths;

int count_bridges(t_bridge** arr);
t_barr* append_bridge(t_barr* arr, t_bridge* i);
int count_distance(t_barr* path);
bool contains(t_barr* arr, t_bridge* e);
char** get_next_stop(t_bridge* b, char** stop);
void free_bridge_array(t_barr** arr);
void free_path_array(t_paths** arr);
void append_path(t_paths* arr, t_barr* i);
void shortest_path(char** from, char** to, t_bridge* on, t_barr* bridges, t_barr* path, t_paths* paths);
void print_paths(char** from, char** to, t_barr* bridges);
char **read_from_file(int argc, char** argv, int* islands, t_barr** bridges);
bool is_duplicate (t_barr* arr, t_bridge* e);
void print_and_delete(char** str, int where);
void err_no_file(char *name);
void err_file_empty(char *name);
void err_line_invalid(int num);
void del_strarr(char*** arr);
void full_del_bridge_array(t_barr** arr);

#endif
