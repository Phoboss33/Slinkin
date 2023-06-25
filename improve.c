#include <stdio.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
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
int main() {
    int arr[] = {5, 3, 1, 4, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    OptInsertSort(arr, size, sizeof(int), compare);
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
}