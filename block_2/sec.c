#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/file.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {

        return 1;
    }
    char* name = "secure.dat";

    int filesize = atoi(argv[1]);
    int interval = atoi(argv[2]);
    
    unsigned char etalon[filesize];
    
    int file = open(name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (file == -1) {
        perror("Error opening file");
        return 1;
    }

    flock(file, LOCK_EX);

    unsigned char buffer[filesize];
    for (int i = 0; i < filesize; i++) {
        buffer[i] =  1 + rand() % 255;
        etalon[i] = buffer[i];
    }

    buffer[filesize] = 0, etalon[filesize] = 0;
    write(file, buffer, filesize);
    
    for (int i = 0;i < filesize;i++) {
        printf("%d ", etalon[i]);
    }    
    printf("\n");
    for (int i = 0;i < filesize;i++) {
        printf("%c", etalon[i]);
    }
    usleep(50000);
    printf("\n=======\n");
    flock(file, LOCK_UN);
    close(file);

    unsigned char newBuffer[filesize];

    while(1) {
        printf("Охранник считывает\n");
        usleep(interval * 1000);

        file = open(name, O_RDWR);
        read(file, newBuffer, filesize);
        close(file);

        if(memcmp(newBuffer, etalon, filesize) != 0) {
            printf("Обнаружен похититель!\n");
            break;
        }

    }

    printf("Изменены байты на позициях:\n");
    for (int i = 0;i < filesize;i++) {
        if(newBuffer[i] == 0) {
            printf("%d ", i);
        }
    }

    printf("\nЭталон: %s\n", etalon);
    unlink(name);
    return 0;
}
