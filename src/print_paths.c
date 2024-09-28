#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

void print_paths(char** from, char** to, t_barr* bridges)
{
    t_paths p;
    p.paths = NULL;
    p.count = 0;
    shortest_path(from, to, NULL, bridges, NULL, &p);

    for (int i = 0; i < p.count; i++) {
        char** stop = from;
        mx_printstr(BOUNDARY);
	mx_printstr("Path: ");
	mx_printstr(*from);
	mx_printstr(" -> ");
	mx_printstr(*to);
	mx_printstr("\nRoute: ");

        for (int j = 0; j < p.paths[i]->count; j++) {
            if (j != 0) mx_printstr(" -> ");
            mx_printstr(*stop);
            stop = get_next_stop(p.paths[i]->bridges[j], stop);
        }

        mx_printstr(" -> ");
	mx_printstr(*to);
	mx_printstr("\nDistance: ");
	if(p.paths[i]->count > 1) {
            for (int j = 0; j < p.paths[i]->count; j++) {
                if (j != 0) mx_printstr(" + ");
		char* c = mx_itoa(p.paths[i]->bridges[j]->length);
                print_and_delete(&c, 0);
            }
            mx_printstr(" = ");
        }
	char* c = mx_itoa(count_distance(p.paths[i]));
	print_and_delete(&c, 0);
	mx_printchar('\n');
	mx_printstr(BOUNDARY);
        free_bridge_array(&p.paths[i]);
    }
    free(p.paths);
}

