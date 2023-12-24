#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int size = 4;
    int *mas = NULL;
    mas = malloc(sizeof(int) * size);
    mas[0] = 1;
    mas[1] = 2;
    mas[2] = 3;
    mas[3] = 4;


    printf("%d\n", sizeof(mas));
    printf("%d\n", sizeof(mas[0]));
    for (int i = 0;i < size + 5; i++) {
        //printf("[%d]", mas[i]);
    }
    size+=5;
    int *mas2 = malloc(sizeof(int) * size);;
    mas2[0] = 5;
    mas2[3] = 5;
    mas = realloc(mas2, sizeof(int) * size);

    for (int i = 0;i < size; i++) {

        printf("[%d]", mas[i]);
    }
    return 0;
}