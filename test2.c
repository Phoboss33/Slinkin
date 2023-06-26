#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция сравнения для сортировки целых чисел по возрастанию
int compare(const void* a, const void* b) {
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;
    
    if (num1 < num2) {
        return -1;
    } else if (num1 > num2) {
        return 1;
    }
    
    return 0;
}

void InsertSort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)) {
    char* arr = (char*) base;
    
    for (size_t i = 1; i < num; i++) {
        char* key = arr + i * size;
        
        // Применение бинарного поиска для нахождения правильной позиции вставки
        size_t low = 0;
        size_t high = i - 1;
        size_t insert_pos = i;
        
        while (low <= high) {
            size_t mid = low + (high - low) / 2;
            char* mid_key = arr + mid * size;
            
            if (compar(mid_key, key) > 0) {
                high = mid - 1;
                insert_pos = mid;
            } else {
                low = mid + 1;
            }
        }
        
        // Перемещение всех элементов, которые больше вставляемого элемента, на одну позицию вправо
        memmove(arr + (insert_pos + 1) * size, arr + insert_pos * size, (i - insert_pos) * size);
        
        // Вставка элемента на правильную позицию
        memcpy(arr + insert_pos * size, key, size);
    }
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3};
    size_t num = sizeof(arr) / sizeof(arr[0]);
    size_t size = sizeof(arr[0]);
    
    printf("Before sorting: ");
    for (size_t i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    InsertSort(&arr, num, size, compare);
    
    printf("After sorting: ");
    for (size_t i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
