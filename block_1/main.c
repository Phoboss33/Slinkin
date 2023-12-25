#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>

int main(int argc, char *argv[]) {
	int size = 1;
    int file;
    char *filename = "set.dat";
    char *buffer = malloc(sizeof(char));
    char bufferFile[256];
    ssize_t bytes_read;

    file = open(filename, O_RDONLY);
    if (file == -1) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    printf("Файл разблокирован, чтение\n");
    usleep(2000000);

	while((bytes_read = read(file, buffer, size) > 0)) {
		size *= 2;
		buffer = realloc(buffer, sizeof(buffer) * size);
		printf("Считывается");
	}
    if (bytes_read == -1) {
        perror("Ошибка при чтении");
        close(file);
        return 1;
    }

    flock(file, LOCK_UN);
    close(file);

    int numbersSet[256]; 
    int fileNumbers[256];

    int numCount = 0;
    int numOfFile = 0;

    char *tok = strtok(buffer, " ");

    while(tok != NULL) {
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

        bytes_read = read(file, bufferFile, sizeof(bufferFile));

        char *tokInFile = strtok(bufferFile, " ");
        while (tokInFile != NULL) {
            fileNumbers[numOfFile++] = atoi(tokInFile);
            tokInFile = strtok(NULL, " ");
        }

        close(file);
    }

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
