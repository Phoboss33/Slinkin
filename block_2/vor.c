#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/file.h>

int main(int argc, char *argv[]) {
    const char* filename = "secure.dat";
    int interval = atoi(argv[1]);
    int file;
    
    while (1) {
        file = open(filename, O_RDWR);

        if (file != -1) {
            printf("Файл появился, можно воровать\n");

            //int lock_result = flock(file, LOCK_EX | LOCK_NB);
            int lock_result = flock(file, LOCK_EX);
            if (lock_result == 0) {

                break;
            } 
            /*else {
                printf("Файл еще записывается\n");
                close(file);
                usleep(1000000);
            }*/
        } else {
            printf("Ожидание появления файла\n");
            usleep(1000000);
        }
    }

    struct stat st;
    fstat(file, &st);
    int size = st.st_size;


    printf("Размер файла: %d байт\n", size);
    unsigned char byteRead;
        //usleep(interval * 1000);

    read(file, &byteRead, 1);
    write(file, 0, 1);
    

    return 0;
}