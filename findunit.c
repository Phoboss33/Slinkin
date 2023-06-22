#include <stdio.h>
#include "findunit.h"

int line_find_one(const int src[], int src_size, testfunc func) {
    find_count = 0;
    for (int i = 0; i < src_size; i++) {
        find_count++; 
        if (func(src[i])) {
            return i; 
        }
    }
    return -1; 
}

int line_find_all(const int src[], int src_size, testfunc func, int result[], int result_maxsize) {
    int find_count = 0;
    for (int i = 0; i < src_size; i++) {
        if (func(src[i])) {
            if (find_count < result_maxsize) {
                result[find_count] = i;
            }
            find_count++;
        }
    }
    return find_count;
}
