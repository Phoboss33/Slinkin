#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void BubleSort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)) {
    int* arr = (int*)base;
    for (size_t i = 0; i < num-1; i++) {
        for (size_t j = 0; j < num-i-1; j++) {
            if (compar(&arr[j], &arr[j+1]) > 0) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void InsertSort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)) {
    int* arr = (int*)base;
    for (size_t i = 1; i < num; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && compar(&arr[j], &key) > 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void QuickSort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)) {
    int* arr = (int*)base;
    if (num <= 1) {
        return;
    }
    int pivot = arr[num - 1];
    int i = -1;
    for (size_t j = 0; j < num - 1; j++) {
        if (compar(&arr[j], &pivot) < 0) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[num-1];
    arr[num-1] = temp;

    size_t pivotIndex = i + 1;

    QuickSort(arr, pivotIndex, size, compar);
    QuickSort(arr + (pivotIndex + 1) * size, num - pivotIndex - 1, size, compar);
}

int main() {
    int arr[] = {66, 33, 25, 12, 22, 11, 99};
    int n = sizeof(arr)/sizeof(arr[0]);

    BubleSort(arr, n, sizeof(int), compare);
    printf("Пузырь: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int arr2[] = {66, 33, 25, 12, 22, 11, 99};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    InsertSort(arr2, n2, sizeof(int), compare);
    printf("Вставками: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    int arr3[] = {66, 33, 25, 12, 22, 11, 99};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);

    InsertSort(arr3, n3, sizeof(int), compare);
    printf("Быстрая: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    int arr4[] = {66, 33, 25, 12, 22, 11, 99};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);

    qsort(arr4, n4, sizeof(int), compare);
    printf("qsort(): ");

    for (int i = 0; i < n4; i++) {
        printf("%d ", arr4[i]);
    }
}