#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char name[50];
   int age;
} Person;

int compare(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return strcmp(p1->name, p2->name);
}

void swap(void *a, void *b, size_t size) {
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void BubbleSort(void* base, size_t num, size_t size, int (*compare)(const void*, const void*)) {
    char* arr = (char*)base;
    size_t i, j;
    for (i = 0; i < num - 1; i++) {
        for (j = 0; j < num - 1 - i; j++) {
            if (compare(arr + j * size, arr + (j + 1) * size) > 0) {
                char temp[size];
                memcpy(temp, arr + j * size, size);
                memcpy(arr + j * size, arr + (j + 1) * size, size);
                memcpy(arr + (j + 1) * size, temp, size);
            }
        }
    }
}

void BubbleSort2(void *base, size_t num, size_t size, int (*compar)(const void *, const void *)) {
    for (size_t i = 0; i < num-1; i++) {
        for (size_t j = 0; j < num-i-1; j++) {
            if (compar(base + j*size, base + (j+1)*size) > 0) {
                swap(base + j*size, base + (j+1)*size, size);
            }
        }
    }
}

int main() {
    Person people[] = {
        {"Charlie", 30},
        {"David", 23},
        {"Alice", 25},
        {"Emily", 28},
        {"Bob", 20},
        {"Frank", 32},
    };
    size_t num_people = sizeof(people) / sizeof(Person);
    BubbleSort(people, num_people, sizeof(Person), compare);
    for (size_t i = 0; i < num_people; i++) {
        printf("%s\t%d\n", people[i].name, people[i].age);
    }
    return 0;
}
