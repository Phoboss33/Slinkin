#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
        
        int partitionIndex = i + 1;
        
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void insertionSort(int arr[], int n) {
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

void optimizedInsertionSort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)) {
    int* arr = (int*)base;
    for (size_t i = 1; i < num; i++) {
        int key = arr[i];
        int left = 0;
        int right = i - 1;
        int j = i;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (compar(&arr[mid], &key) <= 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        while (j > left) {
            arr[j] = arr[j-1];
            j--;
        }
        
        arr[left] = key;
    }
}

void bubbleSort(int arr[], int n) {
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
    int arr[MAX_SIZE];
    
    int n = 850; 
    
    for (int i = 0;i < n;i++) {
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % MAX_SIZE;
        }

        
        //quickSort(arr, 0, n-1);			// 3500
        //insertionSort(arr, n);		// 1222
        //optimizedInsertionSort(arr, n, sizeof(int), compare);	//1350
        bubbleSort(arr, n);		// 850
        //count++;

  
    }
    printf("Количество элементов массива: %d\n", n);
}
