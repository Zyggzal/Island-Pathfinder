#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h" 

int main(int argc, char **argv)
{
    int len = 0;

    t_barr* bridges = (t_barr*)malloc(sizeof(t_barr));
    bridges->bridges = NULL;
    char** islands = read_from_file(argc, argv, &len, &bridges);

    long int count = 0;
    for (int i = 0; i < bridges->count; i++) {
        count += bridges->bridges[i]->length;
    }

    if(count >= MAX_INT) {
	mx_printerr("error: sum of bridges lengths is too big");
    }
    else {
        for(int i = 0; i < len - 1; i++) {
	    for(int j = i + 1; j < len; j++) {
	        print_paths(islands + i, islands + j, bridges);
	    }
        }
    }
    free(islands);
    free(bridges->bridges);
    free(bridges);
    return 0;
}

