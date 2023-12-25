#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    char mas[10];
    mas[1] = 55;

    printf("%d", mas[1]);
    return 0;
}