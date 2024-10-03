#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

bool island_exists(char **arr, char *str) {
    if(!arr) return false;
    while(*arr) {
        if(mx_strcmp(*(arr++), str) == 0) {
            return true;
        }
    }
    return false;
}

void del_strarr(char*** arr) {
    if(!*arr)return;
    for (int i = 0; (*arr)[i]; i++) {
        mx_strdel(&((*arr)[i]));
    }
    free(*arr);
    *arr = NULL;
}

char **get_island(char **arr, char *island) {
    while(*arr) {
	if(mx_strcmp(*arr, island) == 0)return arr;
	arr++;
    }
    return NULL;
}

bool islands_valid(char* str) {
    int len = mx_strlen(str);
    for(int i = 0; i < len; i++) {
	if(!(str[i] >= 65 && str[i] <= 90) && !(str[i] >= 97 && str[i] <= 122) && str[i] != '-')return false; 
    }
    return true;
}

char **read_from_file(int argc, char** argv, int* islands, t_barr** bridges) {
    if(argc != 2) {
        write(2, "usage: ./pathfinder [filename]\n", 31);
        exit(0);
    }

    int fd = open(argv[1], O_RDONLY);  
    if(fd == -1) {
        close(fd);
	err_no_file(argv[1]);
        exit(0);
    }
    close(fd);
    char *content = mx_file_to_str(argv[1]);
    if(!content || mx_strlen(content) == 0) {
	err_file_empty(argv[1]);
	exit(0);
    }
    char **lines = mx_strsplit(content, '\n');
    mx_strdel(&content);
    if(!lines[0] || (*islands = mx_atoi(lines[0])) <= 0) {
        del_strarr(&lines);
        write(2, "error: line 1 is not valid\n", 27);
        exit(0);
    }
    char **isles = (char **)malloc(sizeof(char *) * ((*islands) + 1));
    for(int i = 0; i < (*islands) + 1; i++) {
        isles[i] = NULL;
    }
    int icounter = 0;
    int i = 0;
    while(lines[++i]) {
        if(mx_count_substr(lines[i], ",") != 1 || mx_count_substr(lines[i], "-") != 1) {
	    err_line_invalid(i + 1);
	    del_strarr(&isles);
            del_strarr(&lines);
            full_del_bridge_array(bridges);
            exit(0);
        }
        char **f = mx_strsplit(lines[i], ',');
        if(!f || !f[0] || !f[1] || !islands_valid(f[0])) {
	    err_line_invalid(i + 1);
	    del_strarr(&isles);
            del_strarr(&lines);
            del_strarr(&f);
            full_del_bridge_array(bridges);
            exit(0);
        }
        int len = mx_atoi(f[1]);
        char **inames = mx_strsplit(f[0], '-');
        del_strarr(&f);
        if(!inames || !inames[0] || !inames[1] || mx_strcmp(inames[0], inames[1]) == 0 || len <= 0) {
	    err_line_invalid(i + 1);
	    del_strarr(&isles);
            del_strarr(&lines);
            del_strarr(&inames);
            full_del_bridge_array(bridges);
            exit(0);
        }
	if(!island_exists(isles, inames[0])) {
            if(icounter >= *islands) {
                icounter++;
                del_strarr(&inames);
                break;
            }
            isles[icounter++] = inames[0];
        }
        else {
	    char **tmp = get_island(isles, inames[0]);
	    mx_strdel(&inames[0]);
	    inames[0] = *tmp;
	}
	if(!island_exists(isles, inames[1])) {
            if(icounter >= *islands) { 
                mx_strdel(&inames[1]);
		free(inames);
                icounter++;
                break;
            }
            isles[icounter++] = inames[1];
        }
        else {
	    char **tmp = get_island(isles, inames[1]);
	    mx_strdel(&inames[1]);
	    inames[1] = *tmp;
	}
        t_bridge* b = (t_bridge*)malloc(sizeof(t_bridge));
        b->length = len;
        b->islandA = get_island(isles, inames[0]);
        b->islandB = get_island(isles, inames[1]);

        free(inames);

	if(!is_duplicate(*bridges, b)) {
        	t_barr* tmp = append_bridge(*bridges, b);
        	free_bridge_array(bridges);
        	*bridges = tmp;
	}
	else {
            write(2, "error: duplicate bridges\n", 25);
            del_strarr(&isles);
	    del_strarr(&lines);
            full_del_bridge_array(bridges);
	    exit(0);
	}

    }
    del_strarr(&lines);
    
    if(icounter != *islands) {
        write(2, "error: invalid number of islands\n", 33);
        del_strarr(&isles);
        full_del_bridge_array(bridges);
        exit(0);
    }

    return isles;
}

