#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>

// чтение файлов .
// блокировка
// чтение целевого
// объединение целевого с прочитанным
// запись целевого 
// разблок

int main(int argc, char *argv[]) {
	int size = 2;
	int fileNumbersSize = 2; 
	
	int file;
	char *filename = "set.dat";
    char *buffer = malloc(size);
    
    ssize_t bytesRead = 0;
    ssize_t totalRead = 0;
	
	
	// Чтение файлов
	int *fileNumbers = malloc(sizeof(int) * fileNumbersSize);

    int numCount = 0;
    int numOfFile = 0;

    char *bufferFile = malloc(size);

    for (int i = 1; i < argc; i++) {
        file = open(argv[i], O_RDONLY);

        if (file == -1) {
            printf("Ошибка при открытии файла [%s]\n", argv[i]);
            return 0;
        }
        totalRead = 0;
        //bytesRead = read(file, bufferFile, sizeof(bufferFile));
        while((bytesRead = read(file, bufferFile + totalRead, 1)) > 0) {
            if (bufferFile[totalRead] == ' ') {
                bufferFile[totalRead] = '\0';
                fileNumbers[numOfFile++] = atoi(bufferFile);
                totalRead = 0;
                if (numOfFile == fileNumbersSize) {
                    fileNumbersSize *= 2;
                    fileNumbers = (int*)realloc(fileNumbers, sizeof(int) * fileNumbersSize);
                }
            } else {
                totalRead++;
                if (totalRead == size) {
                    size *= 2;
                    bufferFile = (char*)realloc(bufferFile, size);
                }
            }
            
        }
        close(file);
    }

    printf("\n\nЧисла из файлов:\n");

    for (int i = 0; i < numOfFile; i++) {
        printf("%d ", fileNumbers[i]);
    }
	usleep(2000000);
    
    // блокировка
    file = open(filename, O_RDONLY);

    int lock_result = flock(file, LOCK_EX | LOCK_NB);
    while (lock_result != 0) {
        printf("Доступ к файлу заблокирован...\n");
        usleep(500000); 

        lock_result = flock(file, LOCK_EX | LOCK_NB);
    }
    
    
    // Чтение целевого

    if (file == -1) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    usleep(1000000);

	totalRead = 0;
    while((bytesRead = read(file, buffer + totalRead, size - totalRead)) > 0) {
        totalRead += bytesRead;
        if (totalRead == size) {
            size *= 2;
            buffer = (char*)realloc(buffer, size);
        }
    }
	
	//printf("[%d]",size);
    int *numbersSet = malloc(sizeof(int) * size); 
    char *tok = strtok(buffer, " ");

    while(tok != NULL) {
        numbersSet[numCount++] = atoi(tok);
        tok = strtok(NULL, " ");
    }
    
    printf("\nЧисла из set:\n");
    for (int i = 0; i < numCount; i++) {
        printf("%d ", numbersSet[i]);
    }
    
    printf("[[%d]]",numCount);
	// Объединение
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
    
    
    // Запись
    file = open(filename, O_WRONLY);
    if (file == -1) {
        perror("Ошибка при открытии на запись");
        return 1;
    }

    free(buffer);
    buffer = realloc(buffer, size);
    
    printf("\nФайл разблокирован, начало записи.\n");
    for (int i = 0; i < numCount; i++) {
        int out = snprintf(buffer, size, "%d ", numbersSet[i]);
        write(file, buffer, out);
    }
    //usleep(2000000);
    
    // Разблок
    flock(file, LOCK_UN);
    close(file);

    printf("\nЗапись завершена, файл разблокирован.\n");
    
	return 0;
}
