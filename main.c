#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int file;
    char *filename = "set.dat";
    char buffer[256];
    char bufferFile[256];
    ssize_t bytes_read;

    file = open(filename, O_RDONLY);
    if (file == -1) {
        printf("Ошибка при открытии файла\n");
        return 1;
    }
    
    bytes_read = read(file, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        printf("Ошибка при чтении файла\n");
        return 1;
    }
    close(file);

    int numbersSet[256];
    int fileNumbers[256];
    int numCount = 0;
    int numOfFile = 0;
    char *tok = strtok(buffer, " ");

    while (tok != NULL) {
        //printf(" [%s]", tok);
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
            printf("Ошибка при открытии файла\n");
            return 1;
        }

        bytes_read = read(file, bufferFile, sizeof(bufferFile));
        if (bytes_read == -1) {
            printf("Ошибка при чтении файла\n");
            return 1;
        }

        char *tokInFile = strtok(bufferFile, " ");
        while (tokInFile != NULL) {
            //printf(" [%s]", tokInFile);
            fileNumbers[numOfFile++] = atoi(tokInFile);
            tokInFile = strtok(NULL, " ");
        }

        close(file);
    }
    printf("\n\nЧисла из файлов:\n");
    for (int i = 0; i < numOfFile; i++) {
        printf("%d ", fileNumbers[i]);
    }
    return 0;
}