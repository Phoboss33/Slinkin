#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>

#define BUFFER_SIZE 1

int main(int argc, char *argv[]) {
    int file;
    char *filename = "set.dat";
    char *buffer = malloc(BUFFER_SIZE);
    ssize_t bytes_read;
    size_t buffer_size = BUFFER_SIZE;
    size_t fileBufferSize = BUFFER_SIZE;
    size_t total_bytes_read = 0;

    file = open(filename, O_RDONLY);
    if (file == -1) {
        perror("Ошибка при открытии файла");
        return 1;
    }
    usleep(2000000);

    while ((bytes_read = read(file, buffer + total_bytes_read, buffer_size - total_bytes_read)) > 0) {
        total_bytes_read += bytes_read;

        if (total_bytes_read == buffer_size) {
            buffer_size *= 2;
            buffer = realloc(buffer, buffer_size);
        }
    }

    if (bytes_read == -1) {
        perror("Ошибка при чтении");
        close(file);
        free(buffer);
        return 1;
    }

    close(file);

    int numbersSet[buffer_size]; 
    int* fileNumbers = malloc(sizeof(int));

    int numCount = 0;
    int numOfFile = 0;

    char *tok = strtok(buffer, " ");

    while (tok != NULL) {
        numbersSet[numCount++] = atoi(tok);
        tok = strtok(NULL, " ");
    }

    printf("\nЧисла из set:\n");
    for (int i = 0; i < numCount; i++) {
        printf("%d ", numbersSet[i]);
    }

    for (int i = 1; i < argc; i++) {
        file = open(argv[i], O_RDONLY);

        if (file == -1) {
            printf("Ошибка при открытии файла [%s]\n", argv[i]);
            return 0;
        }
        
        total_bytes_read = 0;

        while ((bytes_read = read(file, buffer + total_bytes_read, fileBufferSize - total_bytes_read)) > 0) {
            total_bytes_read += bytes_read;

            if (total_bytes_read == fileBufferSize) {
                fileBufferSize *= 2;
                buffer = realloc(buffer, fileBufferSize);
                fileNumbers = realloc(fileNumbers, sizeof(int) * fileBufferSize);
            }
        }

        if (bytes_read == -1) {
            perror("Ошибка при чтении");
            close(file);
            free(buffer);
            return 1;
        }

        char *tokInFile = strtok(buffer, " ");
        while (tokInFile != NULL) {
            fileNumbers[numOfFile++] = atoi(tokInFile);
            tokInFile = strtok(NULL, " ");
        }

        close(file);
    }

    free(buffer);

    printf("\n\nЧисла из файлов:\n");

    for (int i = 0; i < numOfFile; i++) {
        printf("%d ", fileNumbers[i]);
    }

    for (int i = 0; i < numOfFile; i++) {
        int flag = 0;

        for (int j = 0; j < numCount; j++) {
            if (fileNumbers[i] == numbersSet[j]) {
                flag = 1;
                break;
            }
        }
        if (flag != 1) {
            numbersSet[numCount] = fileNumbers[i];
            numCount++;
            flag = 0;
        }
    }

    printf("\nЧисла из set итог:\n");

    for (int i = 0; i < numCount; i++) {
        printf("%d ", numbersSet[i]);
    }

    file = open(filename, O_WRONLY);
    if (file == -1) {
        perror("Ошибка при открытии на запись");
        return 1;
    }

    int lock_result = flock(file, LOCK_EX | LOCK_NB);
    while (lock_result != 0) {
        printf("Доступ к файлу заблокирован...\n");
        usleep(500000); 

        lock_result = flock(file, LOCK_EX | LOCK_NB);
    }

    printf("\nФайл разблокирован, начало записи.\n");
    for (int i = 0; i < numCount; i++) {
        int out = snprintf(buffer, sizeof(buffer), "%d ", numbersSet[i]);
        write(file, buffer, out);
    }
    usleep(2000000);

    flock(file, LOCK_UN);
    close(file);

    printf("\nЗапись завершена, файл разблокирован.\n");

    return 0;
}