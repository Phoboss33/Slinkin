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

void InsertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
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
        for (j = i; j > left; j--) {
            memcpy(arr + j * size, arr + (j - 1) * size, size);
        }
        memcpy(arr + left * size, temp, size);
    }
}

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n = 3500;

    int arr[n];
    
    int count = 0;
    int targetTime = 1; 
    

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 3500;
    }

        
    //QuickSort(arr, n, sizeof(int), compare); //3500
    //InsertSort(arr, n); // 1222
    //OptInsertSort(arr, n, sizeof(int), compare); //1350
    BubbleSort(arr, n);   // 850

  

    printf("Количество элементов массива: %d\n", n);
}