#include <stdio.h>
#include <stdlib.h>

#define SET_FILE "set.dat"

// Функция для проверки, содержится ли число в массиве
int contains(int *array, int length, int number) {
    for (int i = 0; i < length; ++i) {
        if (array[i] == number) {
            return 1;
        }
    }
    return 0;
}

// Функция для добавления числа в массив, если оно там ещё не числится
void addUnique(int **array, int *length, int number) {
    if (!contains(*array, *length, number)) {
        *array = realloc(*array, (*length + 1) * sizeof(int));
        (*array)[*length] = number;
        (*length)++;
    }
}

// Основная функция
int main(int argc, char *argv[]) {
    // Массив для уникальных значений и его размер
    int *uniqueValues = NULL;
    int uniqueCount = 0;

    // Чтение уникальных значений из set.dat
    FILE *setFile = fopen(SET_FILE, "r");
    int value;
    while (fscanf(setFile, "%d", &value) == 1) {
        addUnique(&uniqueValues, &uniqueCount, value);
    }
    fclose(setFile);

    // Чтение значений из исходных файлов
    for (int i = 1; i < argc; ++i) {
        FILE *srcFile = fopen(argv[i], "r");
        if (srcFile == NULL) {
            fprintf(stderr, "Не удаётся открыть файл %s\n", argv[i]);
            continue;
        }

        while (fscanf(srcFile, "%d", &value) == 1) {
            addUnique(&uniqueValues, &uniqueCount, value);
        }
        fclose(srcFile);
    }

    // Запись уникальных значений обратно в set.dat
    setFile = fopen(SET_FILE, "w");
    for (int i = 0; i < uniqueCount; ++i) {
        fprintf(setFile, "%d\n", uniqueValues[i]);
    }
    fclose(setFile);

    // Освобождение памяти
    free(uniqueValues);

    return 0;
}