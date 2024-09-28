#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

void print_and_delete(char** str, int where) {
    write(where, *str, mx_strlen(*str));
    mx_strdel(str);
}

void err_no_file(char *name) {
    write(2, "error: file ", 12);
    write(2, name, mx_strlen(name));
    write(2, " does not exist", 15);
}

void err_file_empty(char *name) {
    write(2, "error: file ", 12);
    write(2, name, mx_strlen(name));
    write(2, " is empty", 9);
}

void err_line_invalid(int num) {
    write(2, "error: line ", 12);
    char* l = mx_itoa(num);
    print_and_delete(&l, 2);
    write(2, " is not valid", 13);
}

