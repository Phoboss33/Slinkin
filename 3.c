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

void InsertSort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)) {
    char* arr = (char*) base;
    
    for (size_t i = 1; i < num; i++) {
        char* key = arr + i * size;
        size_t j = i - 1;
        
        while (j >= 0 && compar(arr + j * size, key) > 0) {
            memcpy(arr + (j + 1) * size, arr + j * size, size);
            j--;
        }
        
        memcpy(arr + (j + 1) * size, key, size);
    }
}

void OptInsertSort(void* base, size_t num, size_t size, int (*compare)(const void*, const void*)) {
	char* arr = (char*) base;
	for (size_t i = 1; i < num; i++) {
		char* key = arr + i * size;
		ssize_t left = 0;
		ssize_t right = i - 1;
		ssize_t j = i - 1;
		
		while (left <= right) {
			ssize_t middle = (left + right) / 2;
			if (compare(arr + middle * size, key) <= 0) {
				left = middle + 1;
			} else {
				right = middle - 1;
			}
		}
		
		memmove(arr + (left + 1) * size, arr + left * size, (j - left + 1) * size);
		memcpy(arr + left * size, key, size);
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
    int n = 58990000;

    int* arr = (int*)malloc(n * sizeof(int));
    
    for (long long int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }

        
    //QuickSort(arr, n, sizeof(int), compare); //4400000
    //InsertSort(arr, n, sizeof(int), compare); // 58990000
    OptInsertSort(arr, n, sizeof(int), compare); // 250000
    //BubbleSort(arr, n, sizeof(int), compare);   // 21000

	//for (long long int i = 0; i < n; i++) {
        //printf("%d", arr[i]);
    //}

    printf("Количество элементов массива: %d\n", n);
}
