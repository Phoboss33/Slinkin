#include <stdio.h>
#include "findunit.h"
int find_count = 0;

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
    find_count = 0;
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

int bin_find_one(const int src[], int src_size, testfunc func) {
    int left = 0;
    int right = src_size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int test = func(src[mid]);
        if (test == 0)
            return mid;
        else if (test > 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
}

int bin_find_all(const int src[], int src_size, testfunc func,
    int *res_beg, int *res_end) {
    int left = 0;
    int right = src_size - 1;
    int start_found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int test = func(src[mid]);
        if (test == 0) {
            if (start_found == 0) {
                *res_beg = mid;
                start_found = 1;
            }
            *res_end = mid;

            left = mid + 1;
            right = mid - 1;
        } 
        else if (test > 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
}