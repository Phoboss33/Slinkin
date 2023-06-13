#include <stdio.h>
#include <string.h>

#define rcountM(A, result) {\
for (unsigned short i = 0; A[i] != '\0'; i++)\
    if ((unsigned char)(A)[i] >= 0xD0 && (unsigned char)(A)[i] <= 0xD1) {\
        result++;\
        i++;\
    }\
}

int main() {
    unsigned short result = 0;
    char A[100];

    fgets(A, 100, stdin);
    
    A[strlen(A)-1] = '\0';
    rcountM(A, result);

    printf("букв: %hu\n", result);

}