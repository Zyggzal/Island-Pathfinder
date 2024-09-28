#include "../inc/pathfinder.h"

void shortest_path(char** from, char** to, t_bridge* on, t_barr* bridges, t_barr* path, t_paths* paths) {
    char** stop;
    if (on) {
        if (on->islandA == to || on->islandB == to) {
            if (paths->count != 0) {
                int cur_plen = count_distance(path);
                int min_plen = count_distance(paths->paths[0]);

                if (cur_plen == min_plen) {
                    append_path(paths, path);
                }
                else if (cur_plen < min_plen) {
                    free_path_array(&paths);
                    append_path(paths, path);
                }
                else {
                    free_bridge_array(&path);
                }
            }
            else {
                append_path(paths, path);
            }
            return;
        }
    }

    for(int i = 0; i < bridges->count; i++) {
        if (!contains(path, bridges->bridges[i])) {
            stop = get_next_stop(bridges->bridges[i], from);
            if (stop != NULL) {
                shortest_path(stop, to, bridges->bridges[i], bridges, append_bridge(path, bridges->bridges[i]), paths);
            }
        }
    }

    free_bridge_array(&path);
}

