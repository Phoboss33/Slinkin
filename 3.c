#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void QuickSort(void* base, size_t num, size_t size, int (*compare)(const void*, const void*)) {
    char* arr = (char*)base;
    if (num <= 1) {
        return;
    }
    char* pivot = arr + (num / 2) * size;
    char* temp = (char*)malloc(size);
    size_t i, j;
    for (i = 0, j = num - 1;; i++, j--) {
        while (compare(arr + i * size, pivot) < 0) {
            i++;
        }
        while (compare(arr + j * size, pivot) > 0) {
            j--;
        }
        if (i >= j) {
            break;
        }
        memcpy(temp, arr + i * size, size);
        memcpy(arr + i * size, arr + j * size, size);
        memcpy(arr + j * size, temp, size);
    }
    free(temp);
    QuickSort(arr, i, size, compare);
    QuickSort(arr + i * size, num - i, size, compare);
}

void InsertSort(void* base, size_t num, size_t size, int (*compare)(const void*, const void*)) {
    char* arr_ptr = (char*)base;
    char* key = malloc(size);
    size_t i, j;

    for (i = 1; i < num; i++) {
        memcpy(key, arr_ptr + i * size, size);
        j = i - 1;

        while (j >= 0 && compare(arr_ptr + j * size, key) > 0) {
            memcpy(arr_ptr + (j + 1) * size, arr_ptr + j * size, size);
            j = j - 1;
        }
        memcpy(arr_ptr + (j + 1) * size, key, size);
    }
}

void OptInsertSort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)) {
    char* arr = (char*)base;
    size_t i, j;
    for (i = 1; i < num; i++) {
        char temp[size];
        memcpy(temp, arr + i * size, size);
        size_t left = 0, right = i;
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (compare(arr + mid * size, temp) <= 0) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        memmove(arr + (left + 1) * size, arr + left * size, (i - left) * size);
        memcpy(arr + left * size, temp, size);
    }
}

void BubbleSort(void* arr, size_t n, size_t size, int (*compare)(const void*, const void*))
{
    char* array = (char*)arr;

    for (size_t i = 0; i < n-1; i++) {
        for (size_t j = 0; j < n-i-1; j++) {
            if (compare(array + j * size, array + (j+1) * size) > 0) {
                for (size_t k = 0; k < size; k++) {
                    char temp = array[j * size + k];
                    array[j * size + k] = array[(j+1) * size + k];
                    array[(j+1) * size + k] = temp;
                }
            }
        }
    }
}

int main() {
    int n = 140000;
    srand(time(NULL));
    int* arr = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }

    //QuickSort(arr, n, sizeof(int), compare); //2 400 000 | 2400000
    //InsertSort(arr, n, sizeof(int), compare); // 19 500 | 19500
    OptInsertSort(arr, n, sizeof(int), compare); // 140 000 | 140000
    //BubbleSort(arr, n, sizeof(int), compare);   // 21 000 | 9000 

    /*
	for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }*/

    printf("Количество элементов массива: %d\n", n);
}
