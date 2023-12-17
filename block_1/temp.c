#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int buffer[100];
    ssize_t bytesRead;

    // Открываем файл с помощью дескриптора
    fd = open("set.dat", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Читаем содержимое файла
    bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    // Печатаем содержимое файла
    printf("Содержимое файла:\n");
    for (int i = 0; i < bytesRead / sizeof(int); i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    // Закрываем файл
    close(fd);

    return 0;
}