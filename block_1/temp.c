#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char* filename = "test.txt";
    int set = open(filename, O_RDONLY);
    if (set == -1) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    // Выделение памяти для массива
    size_t bufferSize = 5; // Начальный размер массива
    char* buffer = (char*)malloc(bufferSize);
    if (!buffer) {
        printf("Ошибка выделения памяти\n");
        close(set);
        return 1;
    }

    ssize_t bytesRead;
    ssize_t totalBytesRead = 0;
    while ((bytesRead = read(set, buffer + totalBytesRead, bufferSize)) > 0) {
        totalBytesRead += bytesRead;
        
        if (totalBytesRead == bufferSize) {
            printf(" Yes");
            bufferSize *= 2;
            char* newBuffer = (char*)realloc(buffer, bufferSize);
            buffer = newBuffer;
        }
    }

    if (bytesRead == -1) {
        printf("Ошибка чтения файла\n");
        free(buffer);
        close(set);
        return 1;
    }

    // Вывод данных
    write(STDOUT_FILENO, buffer, totalBytesRead);
    printf(" => set\n");

    // Освобождение памяти и закрытие файла
    free(buffer);
    close(set);

    return 0;
}