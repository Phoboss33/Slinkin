#include <stdio.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void InsertSort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)) {
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
int main() {
    int arr[] = {5, 2, 9, 1, 3, 7, 4, 6, 8};
    size_t num = sizeof(arr) / sizeof(arr[0]);
    size_t size = sizeof(arr[0]);
    
    InsertSort(arr, num, size, compare);
    
    printf("Отсортированный массив: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}