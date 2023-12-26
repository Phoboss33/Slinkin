#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/file.h>
#include <time.h>

void BubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                unsigned char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

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
    int fileSize = lseek(file, 0, SEEK_END) - 1;
    printf("Размер файла: %d байт\n", fileSize + 1);

    srand(time(NULL));
    int positions[fileSize];
    int needRandPos = 0;
    int randPos;
    int count = 0;
    close(file);


    while(count < fileSize) {
        randPos = rand() % fileSize;

        int flag = 0;
        for (int i = 0;i < count;i++) {
            if (positions[i] == randPos) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            positions[count++] = randPos;
        }

    }
    for (int i = 0;i < fileSize;i++) {
        printf("%d ", positions[i]);
    }

    unsigned char buffer[1];
    unsigned char bufferForReadChar[fileSize];
    while (1) {
        usleep(interval * 1000);
        
        file = open(filename, O_RDWR);
        if (file != -1) {
            
			if (needRandPos < fileSize) {
				
				lseek(file, positions[needRandPos], SEEK_SET);
				read(file, buffer, 1);
				printf("\nПрочитан: [%d] %d\n", positions[needRandPos], buffer[0]);
				
				bufferForReadChar[needRandPos] = buffer[0];
				//positions[0] = needRandPos;

				lseek(file, positions[needRandPos++], SEEK_SET);
				char zero = 0;

				write(file, &zero, 1);

				close(file);
			}
			else {
				printf("Прочитаны байты: позиция, [байт]\n");
				for (int i = 0;i < fileSize;i++) {
					printf("%d [%d]\n",positions[i], bufferForReadChar[i]);
				}
				break;
			}
        }
        else {
            printf("Тревога, уходим!\n");
            break;
        }

    }
	BubbleSort(positions, fileSize);	
	for (int i = 0;i < fileSize;i++) {
		printf("%d", positions[i]);
	}
    
        //usleep(interval * 1000);

    //read(file, &byteRead, 1);
    //write(file, 0, 1);
    

    return 0;
}
